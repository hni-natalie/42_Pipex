/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:02:22 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/06/07 13:02:25 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief functions locates the first occurence of c (converted to a char)
 * in the string pointed to by s 
 * if c is '\0', the function locate the terminating '\0'
 * 
 * @param s the whole strings
 * @param c the character you want to find 
 * 
 * @return a pointer to the located character; 
 * @return NULL if the character does not appear in the string
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/* int main(void)
{
	const char	str[] = "36678vbvv";
	const char find = 'v';
	printf("%s\n", strchr(str, find));
	printf("%s", ft_strchr(str, find));
} */