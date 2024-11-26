/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:26:01 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/11/26 13:30:38 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/libft.h"
# include "../Libft/get_next_line/get_next_line.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

void	exec(char *cmd, char **env);
void	ft_free_arr(char **arr);
char	*get_path(char *cmd, char **env);
void	here_doc(char *limiter);
void	here_doc_input(int *fd, char *limiter);
void	exec_pipe(char *cmd, char **env);
void	error(char *error);
int		open_file(char *file, int fd);

#endif
