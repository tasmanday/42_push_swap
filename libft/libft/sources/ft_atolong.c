/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:37:02 by tday              #+#    #+#             */
/*   Updated: 2023/10/29 17:03:02 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
converts characters in a string to a long

str = given string
sign = multiplies by -1 if number is -ve
result = number as a long
*/

#include "libft.h"

long	ft_atolong(const char *str)
{
	long	result;
	long	i;
	long	sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
