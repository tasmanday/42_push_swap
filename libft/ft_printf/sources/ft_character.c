/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 08:01:46 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/29 08:01:46 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	writes the character to the standard output and increases the value at
	&length
 */

#include "../includes/libftprintf.h"

void	ft_character(char c, int *length)
{
	write(1, &c, 1);
	(*length)++;
}
