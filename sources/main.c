/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:53:26 by tday              #+#    #+#             */
/*   Updated: 2023/11/02 16:22:56 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

int	main(int argc, char *argv[]);

Summary
This code snippet represents the main function of a program. It performs various
operations on two stacks, stack_a and stack_b, to sort the elements in stack_a
in ascending order. The function takes command line arguments as inputs and
returns 0 if the sorting is successful.

Code Analysis
Inputs
argc: an integer representing the number of command line arguments passed to 
the program.
argv: an array of strings containing the command line arguments.

Flow
1. The function first checks for any errors in the command line arguments using
the check_errors function. If an error is found, the function returns -1.
2. It initializes the op_counter variable to 0 and creates two empty stacks,
stack_a and stack_b.
3. The function fills stack_a with the elements from the command line arguments
using the fill_stack_a function.
4. It assigns ranks to the elements in stack_a using the assign_ranks function.
5. The function checks if stack_a is already sorted. If it is, the function
returns 0.
6. It allocates memory for a t_pair structure named pair.
7. The function calls the sort function to sort stack_a and stack_b using the
pair structure and updates the op_counter variable with the number of operations
performed.
8. The pair structure is freed and set to NULL.
9. The stack_a and stack_b stacks are freed and set to NULL.
10. The function returns 0.

Outputs
0: if the sorting is successful.

*/
int	main(int argc, char *argv[])
{
	int		op_counter;
	t_node	*stack_a;
	t_node	*stack_b;
	t_pair	*pair;

	if (check_errors(argc, argv) == -1)
		return (0);
	op_counter = 0;
	stack_b = NULL;
	stack_a = fill_stack_a(argc, argv);
	if (stack_a == NULL)
		return (-1);
	assign_ranks(stack_a);
	if (is_sorted(stack_a))
		return (0);
	pair = malloc(sizeof(t_pair));
	if (pair == NULL)
		return (-1);
	sort(&stack_a, &stack_b, &op_counter, pair);
	free(pair);
	pair = NULL;
	free_null_stack(&stack_a);
	free_null_stack(&stack_b);
	return (0);
}

/* this is just to test, remove before submission !!
void	print_nodes(t_node *stack_a, t_node *stack_b)
{
	if (stack_a == NULL && stack_b == NULL)
	{
		ft_printf("no stacks\n");
		return ;
	}
	ft_printf("stack_a:\n");
	if (stack_a == NULL)
		ft_printf("empty\n");
	while (stack_a != NULL)
	{
		ft_printf("value: %i, index: %i, rank: %i\n", \
		stack_a->value, stack_a->index, stack_a->rank);
		stack_a = stack_a->next;
		if (stack_a->index == 0)
			break ;
	}
	ft_printf("\nstack_b:\n");
	if (stack_b == NULL)
		ft_printf("empty\n");
	while (stack_b != NULL)
	{
		ft_printf("value: %i, index: %i, rank: %i\n", \
		stack_b->value, stack_b->index, stack_b->rank);
		stack_b = stack_b->next;
		if (stack_b->index == 0)
			break ;
	}
	ft_printf("\n");
}

 int	main(int argc, char *argv[])
{
	int		op_counter;
	t_node	*stack_a;
	t_node	*stack_b;
	t_pair	*pair;

	if (check_errors(argc, argv) == -1)
		return (-1);
	op_counter = 0;
	stack_b = NULL;
	stack_a = fill_stack_a(argc, argv);
	if (stack_a == NULL)
		return (-1);
	assign_ranks(stack_a);
	if (is_sorted(stack_a))
		return (0);
	print_nodes(stack_a, stack_b);
	pair = malloc(sizeof(t_pair));
	if (pair == NULL)
		return (-1);
	sort(&stack_a, &stack_b, &op_counter, pair);
	print_nodes(stack_a, stack_b);
	free(pair);
	pair = NULL;
	free_null_stack(&stack_a);
	free_null_stack(&stack_b);
	ft_printf("operations count: %i\n", op_counter);
	return (0);
} */
