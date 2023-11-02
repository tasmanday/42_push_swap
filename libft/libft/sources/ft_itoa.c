/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:48:58 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/16 16:03:31 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
allocates memory and converts the given integer to a string of characters
returns a pointer to the string

n = given integer
str = pointer to string
len = length of string/number of digits in integer
*/

#include "libft.h"

int	get_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		n *= -1;
		len = 1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = get_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len] = '\0';
	while (len-- && n)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}

/*
int	main(void)
{

	int		n;
	char	*str;

	n = -2147483648;
	str = ft_itoa(n);
	if (str != NULL)
	{
		printf("The string representation of %i is: %s\n", n, str);
        free(str);
    }
    else
		printf("Failed to convert %d to a string.\n", numbers[i]);

	return (0);
}
*/