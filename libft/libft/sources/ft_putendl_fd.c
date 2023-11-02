/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:38:13 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/17 15:38:13 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Outputs the string followed by a '\n' to the given filedescriptor

str = string
fd = file descriptor on which to write
nl = new line '\n'
 */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	int		i;
	char	nl;

	i = 0;
	nl = '\n';
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
	write(fd, &nl, 1);
}

/* int	main(void)
{
	char	*str;
	int		fd;

	fd = 1;
	str = "test string";
	ft_putendl_fd(str, 1);
	return (0);
} */