/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:08:08 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/16 18:34:53 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
allocates memory and returns a copy of s1 with the characters specified in set
removed from the beginning and the end of the string.

s1 = string to be trimmed
set = set of characters to trim
c = character
start = start index of the trimmed string
end = end index of the trimmed string
trimmed_str = trimmed string
*/

#include "libft.h"

int	is_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && is_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_set(s1[end - 1], set))
		end--;
	trimmed_str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trimmed_str)
		return (NULL);
	trimmed_str = ft_memmove(trimmed_str, s1 + start, end - start);
	trimmed_str[end - start] = '\0';
	return (trimmed_str);
}

/*
int main(void)
{
	const char	*s1 = "xvxtest stringvxv";
	const char	*set = "vx";
	char		*result;

	result = ft_strtrim(s1, set);
	if (result == NULL)
	{
		printf("failed to trim string.\n");
		return (1);
	}
	else
	{
		printf("the trimmed string is: %s\n", result);
		free(result);
	}

	return 0;
}
*/