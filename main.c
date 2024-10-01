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

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

void	print_error(char *p, char *s)
{
	write(2, WHITE, 7);
	write(2, "shell : ", 8);
	write(2, RESET, 4);
	write(2, s, ft_strlen(s));
	write(2, ": ", 2);
	write(2, YELL, 7);
	write(2, p, ft_strlen(p));
	write(2, RESET, 4);
	write(2, "\n", 2);
}

int main()
{
	if (access("example.txt", R_OK) != -1)
		printf("I have permission\n");
	else
		print_error("example.txt", strerror(errno));

	return (0);
}