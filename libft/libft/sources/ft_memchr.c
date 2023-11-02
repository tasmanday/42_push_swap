/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:12:33 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/15 14:12:37 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
searches for the first occurrence of a specific character in a block of memory,
returns a pointer to the matching byte or NULL if the character does not occur
in the given memory area

ptr = a pointer to the memory location
c = character (int variable as it uses ascii)
n = number of bytes to check
temp_str = temporary pointer cast as an unsigned char which allows it to
increment through the memory byte by byte
*/

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*temp_str;
	size_t			i;

	i = 0;
	temp_str = (unsigned char *)ptr;
	while (i < n)
	{
		if (temp_str[i] == (unsigned char)c)
			return (&temp_str[i]);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	int		c;
	int		n;
	char	ptr[12] = "test string";
	char	*result;

	c = 's';
	n = 10;
	result = ft_memchr(str, c, n);
	printf("string: %s, result: %s\n", ptr, result);
	return (0);
}
*/
