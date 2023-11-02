/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:44:28 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/14 17:44:35 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
checks if given character is a printable character

c = character (int variable as it uses ascii)
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
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
	result = ft_isprint(c);
	printf("1 if printable char, 0 if not: %i\n", result);
	return (0);
}
*/