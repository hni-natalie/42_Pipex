/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:33:36 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/11/25 11:09:47 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	path = get_path(split_cmd[0], env);
	if (execve(path, split_cmd, env) == -1)
	{
		ft_putstr_fd("Error: command not found: ", 2);
		ft_putendl_fd(split_cmd[0], 2);
		ft_free_arr(split_cmd);
		exit(0);
	}
}

char	*get_path(char *cmd, char **env)
{	
	int		i;
	char	**path;
	char	*split_path;
	char	*exec;

	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == NULL)
		i++;
	path = ft_split(env[i] + 5, ':');
	i = -1;
	while (path[++i])
	{
		split_path = ft_strjoin(path[i], "/");
		exec = ft_strjoin(split_path, cmd);
		free(split_path);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
	}
	ft_free_arr(path);
	return (0);
}

void	ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/*
Concept of exec function:
1. Split the command into an array of strings
2. If the split fails, then print an error message and exit
3. Get the path of the command
4. If the execve system call fails, then print an error message, 
	
	free the memory allocated and exit
*/

/*
Concept of get_path function:
1. Split the PATH environment variable into an array of strings
2. Loop through the array of strings
3. Concatenate the path with the command
4. If the command is found, then return the executable path
5. Free the path
6. If the command is not found, then return the command
*/