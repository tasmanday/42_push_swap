/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:42:51 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/16 18:35:18 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
allocates memory and returns a new string, which is the result of the
concatenation of s1 and s2

s1 = string 1
s2 = string 2
result = joined strings
len_s1 = lenth of string 1
len_s2 = lenth of string 2
*/

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!result)
		return (NULL);
	ft_memmove(result, s1, len_s1);
	ft_memmove(result + len_s1, s2, len_s2 + 1);
	return (result);
}

/*
int main(void)
{
	const char	*s1 = "test ";
	const char	*s2 = "string";
	char		*result;

	result = ft_strjoin(s1, s2);
	if(result == NULL)
	{
		printf("Failed to join strings.\n");
		return 1;
	}
	else
	{
		printf("%s\n", result);
		free(result);
	}   
	return 0;
}
*/