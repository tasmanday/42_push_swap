/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:22:01 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/14 17:22:09 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
checks if the gven character is an ASCII character

c = character (int variable as it uses ascii)
*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	int	c;
	int	result;

	c = 'c';
	result = ft_isascii(c);
	printf("1 if ASCII character, 0 if not: %i\n", result);
	return (0);
}
*/