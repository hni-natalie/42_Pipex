/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:33:36 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/08/28 15:34:00 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putendl_fd("Error: wrong number of arguments", 2);
		exit(0);
	}
	if (pipe(fd) == -1)
	{
		ft_putendl_fd("Error: pipe failed", 2);
		exit(0);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putendl_fd("Error: fork failed", 2);
		exit(0);
	}
	if (pid == 0)
		child(fd, argv, env);
	parent(fd, argv, env);
}

void	child(int *fd, char **argv, char **env)
{
	int	self_fd;

	self_fd = open(argv[1], O_RDONLY);
	if (self_fd == -1)
	{
		ft_putendl_fd("Error: file not found", 2);
		exit(0);
	}
	dup2(self_fd, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	exec(argv[2], env);
}

void	parent(int *fd, char **argv, char **env)
{
	int	self_fd;

	self_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (self_fd == -1)
	{
		ft_putendl_fd("Error: file not found", 2);
		exit(0);
	}
	dup2(self_fd, 1);
	dup2(fd[0], 0);
	close(fd[1]);	
	exec(argv[3], env);
}

/*
Concept of child function:
The child writes to the pipe using the write end 
Hence, the child does not need the read end, so it can be safely closed
1. Open the file in read only mode
2. If the file is not found, then exit
3. Redirect stdin to the opened file
4. Redirect stdout to the write end of the pipe 
5. Close the read end of the pipe
6. Execute the first command
*/

/*
Concept of parent function:
The parent reads from the pipe using the read end
Hence, the parent does not need the write end, so it can be safely closed
1. Open the file in write only mode
2. If the file is not found, then exit
3. Redirect stdout to the opened file (to ensure that any output produces get written to the file)
4. Redirect stdin to the read end of the pipe （to ensure that the parent process can receive input from the child process)
5. Close the write end of the pipe
6. Execute the second command 
*/

/*
Concept of the main function:
1. fd representing the 2 ends of the pipe
2. fd[0] is the read end of the pipe
3. fd[1] is the write end of the pipe
*Warning: As data flows from the write end to the read end
If the roles swapped, the system calls will not behave as expected 
4. pid_t is a data type representing the process ID
5. If the number of arguments is not 5, then print an error message and exit
6. If the pipe system call fails, then print an error message and exit
7. Create a child process using the fork system call
8. If the fork system call fails, then print an error message and exit
9. If the child process is created, then call the child function
10. If the parent process is created, then call the parent function
*/