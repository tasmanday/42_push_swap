/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:53:40 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/15 16:53:51 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
checks the first n characters of a string to find the first occurrence of a 
substring
returns a pointer to the first occurance of the substring or NULL if the needle 
substring is not found in the first n characters of the haystack string

haystack = string to be searched
needle = substring that the function is searching for
n = number of characters to check
needle_len = length of the needle substring
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	if (needle_len > n)
		return (NULL);
	while (*haystack != '\0' && n >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		n--;
	}
	return (NULL);
}

/*
int main(void)
{
    const char *haystack = "test string";
    const char *needle = "str";
    
    char *result = strnstr(haystack, needle, ft_strlen(haystack));
    if (result)
        printf("found: %s\n", result);
    else
        printf("not found.\n");
    return 0;
}
*/
