/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:55:55 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/14 17:55:59 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
converts uppercase characters to lowercase characters

c = character (int variable as it uses ascii)
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
int	main(void)
{
	int	c;
	int	result;

	c = 'C';
	result = ft_tolower(c);
	printf("%i -> %i\n", c, result);
	return (0);
}
*/