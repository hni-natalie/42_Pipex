/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:46:30 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/11/26 13:31:56 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(1);
}

int	open_file(char *file, int fd)
{
	int	result;

	if (fd == 0)
		result = open(file, O_RDONLY, 0777);
	if (fd == 1)
		result = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == 2)
		result = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (result == -1)
		error("File not found");
	return (result);
}

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
