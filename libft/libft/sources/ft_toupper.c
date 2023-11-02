/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:57:59 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/14 17:58:02 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
converts lowercase characters to uppercase characters

c = character (int variable as it uses ascii)
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
int	main(void)
{
	int	c;
	int	result;

	c = 'c';
	result = ft_toupper(c);
	printf("%i -> %i\n", c, result);
	return (0);
}
*/