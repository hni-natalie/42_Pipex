/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:46:30 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/11/25 17:04:26 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(1);
}

int	open_file(char* file, int fd)
{
	int	result;

	if (fd == 0)
		result = open(file, O_RDONLY, 0777);
	else if (fd == 1)
		result = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (fd == 2)
		result = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (result == -1)
		error("File not found");
	return (result);
}