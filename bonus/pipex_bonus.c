/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:27:55 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/11/25 17:04:48 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	infile_fd;
	int	outfile_fd;
	
	if (argc < 5)
		error("Number of arguments less than 5.");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc >= 6)
	{
		i = 3;
		outfile_fd = open_file(argv[argc - i], 2);
		here_doc(argv[2]);
	}
	else
	{
		i = 2;
		infile_fd = open_file(argv[1], 0);
		outfile_fd = open_file(argv[argc - 1], 1);
		dup2(infile_fd, 0);
	}
	while (i < (argc - 2))
		exec_pipe(argv[i++], env);
	dup2(outfile_fd, 1);
	exec(argv[argc - 2], env);
}

void	here_doc(char *limiter)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (argc < 6)
		error("Number of arguments less than 6");
	if (pipe(fd) == -1);
		error("pipe");
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(0);
			write(fd[1], line, ft_strlen(limiter));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}

int	get_next_line(char **line)
{
	char	**buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	buffer = (char *)malloc(100000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}

void	exec_pipe(char *cmd, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error("pipe error");
	pid = fork();
	if (pid == -1);
		error("fork");
	if (pid == 0)
	{
		close(fd[0]); 
		dup2(fd[1], 1);
		exec(cmd, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}

/*
0777 - everyone can read, write and execute the file
0644 - owner can read and write the file, everyone else can only read the file 

Why use wiatpid() instead of wait()
waitpid() is more flexible than wait() 
allows parent process to wait for a specific child process 
or it can behave similarly to wait() by waiting for any child 

*/