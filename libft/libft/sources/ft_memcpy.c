/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:24:25 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/15 21:03:18 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
copies a number (n) of bytes of memory from one location to another
returns a pointer to the destination

dest = pointer to destination array
src = pointer to the source array
n = number of bytes to be copied
temp_src & temp_dest = temporary pointers cast as unsigned chars which allows 
them to increment through the memory byte by byte
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;
	size_t			i;

	temp_src = (unsigned char *) src;
	temp_dest = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dest);
}

/*
int main(void)
{
    char	src[12] = "test string";
    char	dest[12];

    ft_memcpy(dest, src, ft_strlen(src) + 1);

    printf("src: %s, dest: %s\n", src, dest);
    return (0);
}
*/