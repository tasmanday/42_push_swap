/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:52:26 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/16 19:08:22 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Outputs the character ’c’ to the given file descriptor.

c = character
fd = file descriptor on which to write
 */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* 
int	main(void)
{
	int		fd;
	char	c;

	fd = 1;
	c = 'c';
	ft_putchar_fd(c, fd);
	return (0);
}
 */