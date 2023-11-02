/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:43:16 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/15 19:23:44 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
converts characters in a string to an integer

str = given string
sign = multiplies by -1 if number is -ve
result = number as an int
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		result;
	int		i;
	int		sign;

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

/*
int main()
{
    char	str1[] = "123";
    char	str2[] = "-123";
    char	str3[] = "   123";

    printf("str1: %d\n", ft_atoi(str1)); // Expected output: 123
    printf("str2: %d\n", ft_atoi(str2)); // Expected output: -123
    printf("str3: %d\n", ft_atoi(str3)); // Expected output: 123
    return 0;
}
*/