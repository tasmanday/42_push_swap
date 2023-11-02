/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:48:39 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/16 17:14:57 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
counts the number of characters in a string and returns that number
(stops counting at null terminator '\0')

str = string
*/

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
int	main(void)
{
	char	str[12]
	int		result;

	str = "test string";
	result = ft_strlen(str);
	printf("string length: %i\n", result);
	return (0);
}
*/