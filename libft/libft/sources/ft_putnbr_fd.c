/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:38:48 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/17 15:38:48 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Outputs the integer as a string to the given file descriptor

n = integer to output
str = string
fd = file descriptor on which to write
 */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

/*
I like this one better but putnbr doesn't allocate memory

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr_fd(str, fd);
}
*/

/* int	main(void)
{
	int		n;
	int		fd;

	n = -424242;
	fd = 1;
	ft_putnbr_fd(n, fd);
	return (0);
} */