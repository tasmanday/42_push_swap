/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:14:01 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/15 13:14:12 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
fills a number of bytes (n) at a given memory location with a given character (c)
returns a pointer to the start of the memory location

pointer = a pointer to the memory to be set
c = character value to set bytes to
n = number of bytes to be set to the character
temp_str = temporary pointer cast as an unsigned char which allows it to
increment through the memory byte by byte
*/

#include "libft.h"

void	*ft_memset(void *pointer, int c, size_t n)
{
	unsigned char	*temp_str;

	temp_str = (unsigned char *)pointer;
	while (n--)
	{
		*temp_str = (unsigned char)c;
		temp_str++;
	}
	return (pointer);
}

/*
int	main(void)
{
	int		c;
	int		n;
	char	str[12];
	char	*result;

	str = "test string";
	c = '@';
	n = 5;
	result = ft_memset(str, c, n);
	printf("%s\n", result);
	return (0);
}
*/