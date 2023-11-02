/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:01:59 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/15 15:02:02 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
compares 2 blocks of memory up to a given number of bytes or the first different
byte. If all bytes are the same, returns 0
if the ascii value of a character in s1 is < the char in s2, returns -ve value
if the ascii value of a character in s1 is > the char in s2, returns +ve value

s1 = memory location 1
s2 = memory location 2
n = number of characters to compare
temp_s1 & temp_s2 = temporary pointers cast as unsigned chars which allows 
them to increment through the memory byte by byte
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*temp_s1 != *temp_s2)
			return (*temp_s1 - *temp_s2);
		temp_s1++;
		temp_s2++;
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
	n = '10';
	result = ft_memcmp(s1, s2, n);
	printf("equal = 0, s1<s2 = -n, s1>s2 = +n: %i\n", result);
	return (0);
}
*/