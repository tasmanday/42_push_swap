/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:31:26 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/15 20:41:01 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
allocates memory and returns a substring from the string ’str’
The substring begins at index ’start’ and is of maximum size ’sub_len’
returns the substring or NULL if malloc fails

str = original string
start = start index of the substring
sub_len = maximum length of substring
sub = substring
*/

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t sub_len)
{
	char	*sub;
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(str);
	if (start >= str_len)
	{
		start = str_len;
		sub_len = 0;
	}
	else if (start + sub_len > str_len)
		sub_len = str_len - start;
	sub = (char *) malloc((sub_len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (str[start + i] != '\0' && i < sub_len)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*
int main(void)
{
    char const *str = "test string!";
    unsigned int start = 5;
    size_t sub_len = 3;
    char *sub;

    sub = ft_substr(str, start, sub_len);
    
    if (sub == NULL)
	{
        printf("Memory allocation failed.\n");
		return (1);
    }
	else
    {
        printf("original String: %s\n", str);
        printf("substring: %s\n", sub);
        free(substring);
    }
	return 0;
}
*/