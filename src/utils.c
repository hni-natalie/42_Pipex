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

void	exec(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	if (split_cmd == NULL)
	{
		ft_putendl_fd("Error: split failed", 2);
		exit(0);
	}
	path = get_path(split_cmd[0], env);
	if (execve(split_cmd[0], split_cmd, env) == -1)
	{
		ft_putstr_fd("Error: command not found: ", 2);
		ft_putendl_fd(split_cmd[0], 2);
		ft_free_arr(split_cmd);
		free(path);
		exit(0);
	}
	free(path);
}

char	*get_path(char *cmd, char **env)
{	
	int		i;
	char	**split_path;
	char	*path_value;
	char	*path;
	char	*exec;

	i = -1;
	path_value = get_env("PATH", env);
	split_path = ft_split(path_value, ':');
	while (split_path[++i])
	{
		path = ft_strjoin(split_path[i], "/");
		exec = ft_strjoin(path, cmd);
		free(path);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
	}
	ft_free_arr(split_path);
	return (cmd);
}

char	*get_env(char *key, char **env)
{
	int		i;
	int		j;
	char	*title;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		title = ft_substr(env[i], 0, j);
		if (ft_strcmp(title, key) == 0)
		{
			free(title);
			return (env[i] + j + 1);
		}
		free(title);
		i++;
	}
	return (NULL);
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
4. If the execve system call fails, then print an error message, free the memory allocated and exit
*/

/*
Concept of get_env function:
1. Loop through the environment variables
2. Loop through each environment variable to find the '=' character
3. Extract the title of the environment variable
4. If the title matches the key, then return the value of the environment variable from the '=
5. Free the title
6. If the key is not found, then return NULL
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