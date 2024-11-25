/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:17:28 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/06/08 16:17:30 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief function that concatenate 2 strings in a new string
 * 
 * @param s1 prefix string
 * @param s2 sufffix string
 * 
 * @return the new string
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	new = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (new);
}

/* int main(void)
{
    char str1[] = "Hello ";
    char str2[] = "I'm Natalie";
    printf("%s", ft_strjoin(str1, str2));
	free(ft_strjoin(str1, str2));
} */