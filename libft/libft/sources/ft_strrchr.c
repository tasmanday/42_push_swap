/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:18:54 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/14 18:18:57 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
searches a null-terminated string for the last occurance of a given character
if the character is found, returns a pointer to that character
if the character is not found, returns a null pointer (NULL) 

c = character (int variable as it uses ascii)
str = string
*/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	while (c > 255)
		c -= 256;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}

/*
int	main(void)
{
	int		c;
	char	str[12];
	char	*result;

	str = "test string";
	c = 's';
	result = ft_strrchr(str, c);
	printf("string: %s, result: %s\n", str, result);
	return (0);
}
*/