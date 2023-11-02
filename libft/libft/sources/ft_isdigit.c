/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:53:16 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/16 11:48:20 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
checks if the given character is a numerical character

c = character (int variable as it uses ascii)
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
	result = ft_isdigit(c);
	printf("1 if digit, 0 if not: %i\n", result);
	return (0);
}
*/