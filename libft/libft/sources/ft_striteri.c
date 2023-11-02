/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:31:55 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/16 18:37:26 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
applies the function 'f' to each character of the given string
modifies the given string

str = given string
f = function
*/

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	int	i;

	if (!str || !f)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		f(i, str + i);
		i++;
	}
}

/* void	ft_even_toupper(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = ft_toupper(*c);
}

int	main(void)
{
	char	str[] = "test string";

	ft_striteri(str, ft_even_toupper);
	printf("%s\n", str);
	return (0);
} */