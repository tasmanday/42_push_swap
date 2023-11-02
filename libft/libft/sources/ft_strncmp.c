/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:36:23 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/14 18:36:27 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
compares 2 strings up to a given number of characters
itterates through and compares characters in the same position on each string
if the first n characters are the same, returns 0
if the ascii value of a character in s1 is < the char in s2, returns -ve value
if the ascii value of a character in s1 is > the char in s2, returns +ve value

s1 = string 1
s2 = string 2
n = number of characters to compare
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

/*
int	main(void)
{
	int		n;
	char	s1[12];
	char	s2[12];	
	int		result;

	s1 = "test string";
	s2 = "test shring";
	n = '8';
	result = ft_strcmp(s1, s2, n);
	printf("equal = 0, s1<s2 = -n, s1>s2 = +n: %i\n", result);
	return (0);
}
*/