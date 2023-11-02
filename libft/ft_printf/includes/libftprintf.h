/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:24:50 by tday              #+#    #+#             */
/*   Updated: 2023/10/08 18:24:50 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_character(char c, int *length);
void	ft_string(char *string, int *length);
void	ft_decimal_integer(int d, int *length);
void	ft_pointer(size_t p, int *length, int first);
void	ft_unsigned_integer(unsigned int u, int *length);
void	ft_hexidecimal(unsigned int x, int *length, char char_case, int first);

int		ft_printf(const char *string, ...);

#endif