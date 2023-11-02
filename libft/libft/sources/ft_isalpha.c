/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:40:46 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/14 16:50:04 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
checks if the given character is an alphabetical character

c = character (int variable as it uses ascii)
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
	result = ft_isalpha(c);
	printf("1 if alpha, 0 if not: %i\n", result);
	return (0);
}
*/