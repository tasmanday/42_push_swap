/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:38:25 by tmitchel          #+#    #+#             */
/*   Updated: 2023/05/25 10:51:04 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

/* int	ft_strcmp(char *s1, char *s2);

int main(void)
{
    char    *s1;
    char    *s2;
    int     cmp;

    s1 = "abcd";
    s2 = "abc";
    cmp = ft_strcmp(s1, s2);
    printf("%i\n", cmp);
    return (0);
} */

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s1[i] || s2[i])
		return (s1[i] - s2[i]);
	return (0);
}
