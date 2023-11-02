/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:32:51 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/16 18:33:05 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
allocates memory and copies a source string to a destination string
source string must be null-terminated

src = source string
len = lenght of source string
dest = destination string
*/

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;

	len = ft_strlen(src);
	dest = (char *) malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest = ft_memmove(dest, src, len + 1);
	return (dest);
}

/*
int main(void)
{
    char	*src = "test string";
    char	*dest;

	dest = ft_strdup(src);
    if (dest == NULL)
	{
        printf("Memory allocation failed\n");
		return (1);
    }
	else
    {
        printf("source string: %s\n", src);
        printf("destination string: %s\n", dest);
        free(dest);
    }
    return 0;
}
*/