/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:31:32 by tday              #+#    #+#             */
/*   Updated: 2023/10/15 19:35:50 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_round_up(float number)
{
	int	int_part;

	int_part = (int)number;
	if (number != int_part)
		return (int_part + 1);
	else
		return (int_part);
}
