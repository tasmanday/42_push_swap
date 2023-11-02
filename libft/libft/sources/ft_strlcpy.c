/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:25:06 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/16 18:32:33 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
copies a source string into a destination buffer of a certain size
if the source is longer than the destination it will shorten it so that it fits
returns the length of the source string

dest = destination buffer
src = source string
dest_len = length of destination buffer
src len = length of the source string
len = number of characters to be copied from src to dest
*/

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_len)
{
	size_t	src_len;
	size_t	len;

	src_len = ft_strlen(src);
	if (dest_len == 0)
		return (src_len);
	else if (src_len >= dest_len)
		len = dest_len - 1;
	else
		len = src_len;
	ft_memmove(dest, src, len);
	dest[len] = '\0';
	return (src_len);
}

/*
int main(void)
{
    char		destination[12];
    const char	*source = "test string";
    size_t result;

    result = ft_strlcpy(destination, source, sizeof(destination));

    printf("copied string: %s\n", destination);
    printf("str_len: %zu\n", result);

    return 0;
}
*/
