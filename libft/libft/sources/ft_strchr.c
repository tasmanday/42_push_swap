/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:13:44 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/14 18:13:48 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
searches a null-terminated string for the first occurance of a given character
if the character is found, returns a pointer to that character
if the character is not found, returns a null pointer (NULL) 

c = character (int variable as it uses ascii)
str = string
*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	while (c > 255)
		c -= 256;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

/*
int	main(void)
{
	int		c;
	char	str[12] = "test string";
	char	*result;

	c = 's';
	result = ft_strchr(str, c);
	printf("string: %s, result: %s\n", str, result);
	return (0);
}
*/