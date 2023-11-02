/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:57:10 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/15 13:57:15 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
fills a number of bytes (n) at a given memory location with 0 ('\0')

pointer = a pointer to the memory to be set
n = number of bytes to be set to the character
*/

#include "libft.h"

void	ft_bzero(void *pointer, size_t n)
{
	ft_memset(pointer, 0, n);
}

/*
int	main(void)
{
	int		n;
	int		i;
	char	str[12] = "test string";

	n = 5;
	ft_bzero(str, n);
	i = 0;
	while (i < 12)
		printf("%c", str[i])
	printf("\n");
	return (0);
}
*/
