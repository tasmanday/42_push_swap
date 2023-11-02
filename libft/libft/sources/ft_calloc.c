/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:25:37 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/15 19:31:23 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_calloc allocates memory and initialises each byte of that memory to 0 ('\0')

number = number of elements to allocate
size = size of each element
pointer = pointer to start of allocated memory
*/

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*pointer;

	pointer = malloc(number * size);
	if (!pointer)
		return (NULL);
	if (pointer != NULL)
		ft_bzero(pointer, number * size);
	return (pointer);
}

/*
int main(void)
{
    int	*array;
    int	array_length = 10;
    int	i;

    array = (int*)ft_calloc(array_length, sizeof(int));
    if (array == NULL)
    {
        printf("Memory allocation failed\n");
        return (1);
    }
    printf("Array contents: ");
	i = 0;
    while (i < array_length)
    {
        printf("%i ", array[i]);
		i++;
    }
    printf("\n");
    free(array);
    return (0);
}
*/