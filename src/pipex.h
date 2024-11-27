/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:33:36 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/11/27 09:21:06 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

void	exec(char *cmd, char **env);
void	child(int *fd, char **argv, char **env);
void	parent(int *fd, char **argv, char **env);
void	ft_free_arr(char **arr);
char	*get_path(char *cmd, char **env);

#endif