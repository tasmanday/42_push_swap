/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:45:35 by tday              #+#    #+#             */
/*   Updated: 2023/09/17 18:19:07 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *input_str, char delimeter)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (input_str[i] != '\0')
	{
		while (input_str[i] == delimeter && input_str[i] != '\0')
			i++;
		if (input_str[i] != delimeter && input_str[i] != '\0')
		{
			count++;
			while (input_str[i] != delimeter && input_str[i] != '\0')
				i++;
		}
	}
	return (count);
}
