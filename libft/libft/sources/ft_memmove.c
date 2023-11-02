/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:32:27 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/16 17:58:24 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
copies a block of memory from one location to another, returns a pointer to the
destination. handles overlapping of source and destination by copying original
source bytes before they are overwritten

dest = pointer to destination array
src = pointer to the source array
n = number of bytes to be copied
temp_src & temp_dest = temporary pointers cast as unsigned chars which allows 
them to increment through the memory byte by byte
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;

	temp_dest = dest;
	temp_src = src;
	if (temp_dest == temp_src)
		return (dest);
	else if (dest > src)
		while (n--)
			temp_dest[n] = temp_src[n];
	else
		while (n--)
			*temp_dest++ = *temp_src++;
	return (dest);
}

/* int	main(void)
{
	char	src[12] = "test string";
	char	dest[12];

	ft_memmove(dest, src, ft_strlen(src) + 1);
	printf("src: %s, dest: %s\n", src, dest);
	return (0);
} */
