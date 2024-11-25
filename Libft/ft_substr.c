/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:26:57 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/06/08 15:27:00 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// if start or len is not match to the string,
// return an empty string that will be freeable
// this is important to avoid segmentation fault 

/**
 * @brief function extract a substring from a string(s)
 * 
 * @param s string from which to extract the new string
 * @param start start index of the new string in the string 's'
 * @param len maximum size of the new string
 * 
 * @return the new string 
 * @return NULL if the memory allocation failed
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*new;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	new = ptr;
	while (len--)
		*ptr++ = s[start++];
	*ptr = '\0';
	return (new);
}

/* int main(void)
{
	char	str[] = "all of this ! ";
	char	*ptr = ft_substr(str, 1, ft_strlen(str));
	printf("%s", ptr);
	free(ptr);
} */