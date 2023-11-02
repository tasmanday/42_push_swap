/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:39:02 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/17 15:39:02 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Outputs the string to the given filedescriptor

str = string
fd = file descriptor on which to write
 */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

/* int	main(void)
{
	char	*str;
	int		fd;

	fd = 1;
	str = "test string";
	ft_putstr_fd(str, 1);
	return (0);
} */