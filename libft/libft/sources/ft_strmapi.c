/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:32:00 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/16 17:29:43 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
applies the function 'f' to each character of the given string
allocates memory and returns a new modified string

str = oriinal string
f = function to be applied to characters in string
result = new string
*/

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (!str || !f)
		return (NULL);
	result = malloc(ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		result[i] = f(i, str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* char	ft_even_toupper(unsigned int i, char c)
{
	if (i % 2 == 0)
	{
		if (c >= 'a' && c <= 'z')
			return (c - 32);
		return (c);
	}
	return (c);
}

int	main(void)
{
	const char	*original = "test string";
	char		*modified;

	modified = ft_strmapi(original, ft_even_toupper);
	if (modified == NULL)
	{
		printf("Failed to allocate memory.\n");
		return (1);
	}
	printf("Original string: %s\n", original);
	printf("Modified string: %s\n", modified);
	free(modified);
	return (0);
} */