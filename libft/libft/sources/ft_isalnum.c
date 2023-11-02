/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:13:45 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/14 17:14:20 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
checks if given character is an alphanumeric character

c = character (int variable as it uses ascii)
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') \
	|| (c >= '0' && c <= '9'))
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
	result = ft_isalnum(c);
	printf("1 if alphanumeric, 0 if not: %i\n", result);
	return (0);
}
*/