/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 08:01:53 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/29 08:01:53 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	prints the given string to the standard output using ft_character so that
	the value at length is also increased

	if (!s)
	prints (null) if the string doesn't exist
 */

#include "../includes/libftprintf.h"

void	ft_string(char *s, int *length)
{
	size_t	i;

	if (!s)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_character(s[i], length);
		i++;
	}
}
