/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:19:02 by tday              #+#    #+#             */
/*   Updated: 2023/11/02 14:46:44 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

void	sort(t_node **stack_a, t_node **stack_b, int *op_counter, t_pair *pair);

Summary
The sort function is responsible for sorting the elements in the stack_a using
different sorting algorithms based on the number of elements in the stack.

Inputs
stack_a: a pointer to the first node of the stack to be sorted.
stack_b: a pointer to the first node of an auxiliary stack.
op_counter: a pointer to an integer variable to keep track of the number of
operations performed.
pair: a pointer to a structure that holds two integers.

Flow
1. The function first determines the number of elements in stack_a.
2. If the number of elements is less than 10, it calls the sort_small function
to sort the stack.
3. If the number of elements is between 10 and 120, it calls the sort_medium
function to sort the stack.
4. If the number of elements is greater than 120, it calls the sort_large
function to sort the stack.

Outputs
The function does not return any value. It sorts the elements in stack_a and
updates the stack_b, op_counter, and pair variables as necessary.

*/
void	sort(t_node **stack_a, t_node **stack_b, int *op_counter, t_pair *pair)
{
	int		num;

	num = stack_size(*stack_a);
	if (num < 10)
		sort_small(stack_a, stack_b, op_counter);
	else if (num < 120)
		sort_medium(stack_a, stack_b, op_counter, pair);
	else
		sort_large(stack_a, stack_b, op_counter, pair);
}

/*

void	rotate_if_needed(t_node **stack_a, t_node **stack_b, int *op_counter);

Summary
The rotate_if_needed function is a support function for the sort_3 function.
It checks if a rotation operation is needed on the stack_a based on the ranks
of its elements.

Inputs
stack_a: a pointer to the first node of the stack to be checked.
stack_b: a pointer to the first node of an auxiliary stack.
op_counter: a pointer to an integer variable to keep track of the number of
operations performed.

Flow
1. The function checks if the rank of the current element is less than the
rank of the next element and greater than the rank of the previous element,
or if the rank of the next element is less than the rank of the previous
element and the previous element is less than the current element.
2. If the condition is true, it checks if the rank of the current element is
less than the rank of the next element.
3. If the condition is true, it calls the rra function to rotate the stack_a
in reverse.
4. If the condition is false, it calls the ra function to rotate the stack_a
in the regular direction.

Outputs
The function does not return any value. It performs rotation operations on the
stack_a as necessary.

*/
void	rotate_if_needed(t_node **stack_a, t_node **stack_b, int *op_counter)
{
	if (((*stack_a)->rank < (*stack_a)->next->rank && (*stack_a)->rank > \
	(*stack_a)->prev->rank) || ((*stack_a)->next->rank < (*stack_a)->prev->rank \
	&& (*stack_a)->prev->rank < (*stack_a)->rank))
	{
		if ((*stack_a)->rank < (*stack_a)->next->rank)
			rra(stack_a, stack_b, op_counter);
		else
			ra(stack_a, stack_b, op_counter);
	}
}

/*

void	sort_3(t_node **stack_a, t_node **stack_b, int *op_counter);

Summary
This function is used to sort a stack of three nodes in ascending order.

Inputs
stack_a: a pointer to the top of the stack to be sorted
stack_b: a pointer to the top of an auxiliary stack (not used in this function)
op_counter: a pointer to an integer variable to keep track of the number of
operations performed

Flow
1. Check if the stack is empty or already sorted, and if so, return.
2. Call the rotate_if_needed function to rotate the stack if necessary.
3. Check the ranks of the nodes to determine the appropriate sorting operation.
4. If the first node has the lowest rank, swap the first two nodes and rotate
the stack.
5. If the first node has the highest rank, swap the first two nodes and rotate
the stack in the opposite direction.
6. Otherwise, simply swap the first two nodes.

Outputs
None, the function manipulates stack_a itself

*/
void	sort_3(t_node **stack_a, t_node **stack_b, int *op_counter)
{
	if (*stack_a == NULL || (*stack_a)->prev->index != 2 || is_sorted(*stack_a))
		return ;
	rotate_if_needed(stack_a, stack_b, op_counter);
	if (is_sorted(*stack_a))
		return ;
	if ((*stack_a)->rank < (*stack_a)->next->rank && \
	(*stack_a)->rank < (*stack_a)->prev->rank)
	{
		sa(stack_a, stack_b, op_counter);
		ra(stack_a, stack_b, op_counter);
	}
	else if ((*stack_a)->rank > (*stack_a)->next->rank && \
	(*stack_a)->rank > (*stack_a)->prev->rank)
	{
		sa(stack_a, stack_b, op_counter);
		rra(stack_a, stack_b, op_counter);
	}
	else
		sa(stack_a, stack_b, op_counter);
}

/*

void	sort_small(t_node **stack_a, t_node **stack_b, int *op_counter);

Summary
The sort_small function is responsible for sorting a small stack of less than 10
numbers. It pushes the node with the smallest rank from stack_a to stack_b until
there are only three nodes left in stack_a. It then calls the sort_3 function to
sort those three nodes. Finally, it pushes back any nodes from stack_b to
stack_a.

Inputs
stack_a: a pointer to the stack that needs to be sorted
stack_b: a pointer to an empty stack that will be used as a temporary stack
op_counter: a pointer to an integer that keeps track of the number of operations
performed

Flow
1. Initialize a variable i with the size of stack_a minus 2.
2. Enter a loop that iterates while i is greater than 0.
3. Find the node with the minimum rank in stack_a using the min_rank function
and assign it to the variable node.
4. Move the node to the top of stack_a using the move_to_top_a function.
5. Push the node to stack_b using the pb function.
6. Decrement i by 1.
7. Call the sort_3 function to sort the remaining three nodes in stack_a.
8. Check if stack_b is not empty.
9. Enter a loop that iterates while i is greater than or equal to 0.
10. Push the top node from stack_b back to stack_a using the pa function.
11. Decrement i by 1.

Outputs
The function does not return any value. It sorts the stack_a in ascending order
and updates the op_counter with the number of operations performed.

*/
void	sort_small(t_node **stack_a, t_node **stack_b, int *op_counter)
{
	int		i;
	t_node	*node;

	i = stack_size(*stack_a) - 2;
	while (i > 0)
	{
		node = min_rank(*stack_a, 0);
		move_to_top_a(node, stack_a, stack_b, op_counter);
		pb(stack_a, stack_b, op_counter);
		i--;
	}
	sort_3(stack_a, stack_b, op_counter);
	if (*stack_b != NULL)
	{
		i = stack_size(*stack_b);
		while (i >= 0)
		{
			pa(stack_a, stack_b, op_counter);
			i--;
		}
	}
}

/* void	sort(t_node **stack_a, t_node **stack_b, int *op_counter, t_pair *pair)
{
	int		i;
	int		num;
	t_node	*next_node;
	t_node	*median_node;

	next_node = NULL;
	median_node = NULL;
	num = stack_size(*stack_a);

	if (num < 10)
	{
		i = stack_size(*stack_a) - 2;
		while (i > 0)
		{
			next_node = min_rank(*stack_a, 0);
			move_to_top_a(next_node, stack_a, stack_b, op_counter);
			pb(stack_a, stack_b, op_counter);
			i--;
		}
		sort_3(stack_a, stack_b, op_counter);
		if (*stack_b != NULL)
		{
			i = stack_size(*stack_b);
			while (i >= 0)
			{
				pa(stack_a, stack_b, op_counter);
				i--;
			}
		}
	}
	else if (num < 120)
	// I use the other sort medium in the submitted version
	{
		while ((*stack_a)->prev->index > 1)
		{
			num = stack_size(*stack_a) / 9;
			pair->low = (median_rank(*stack_a, num * -1));
			pair->high = (median_rank(*stack_a, num));
			if (*stack_b == NULL)
			{
				median_node = median_rank(*stack_a, 0);
				move_to_top_a(median_node, stack_a, stack_b, op_counter);
				pb(stack_a, stack_b, op_counter);
			}
			else
			{
				next_node = ok_a_to_b(*stack_a, pair);
				move_to_top_a(next_node, stack_a, stack_b, op_counter);
				if (next_node->rank > median_node->rank)
					push_swap_a_to_b(stack_a, stack_b, op_counter);
				else
				{
					pb(stack_a, stack_b, op_counter);
					rb(stack_a, stack_b, op_counter);
				}
			}
		}
		i = stack_size(*stack_b);
		while (i >= 0)
		{
			pair = best_b_to_a(*stack_a, *stack_b, pair);
			move_pair_to_top(pair, stack_a, stack_b, op_counter);
			pa(stack_a, stack_b, op_counter);
			i--;
		}
		if (!is_sorted(*stack_a))
		{
			next_node = min_rank(*stack_a, 0);
			move_to_top_a(next_node, stack_a, stack_b, op_counter);
		}
	}
	// this one is used in the submitted version, it will need to be
	// commented out to use the other version of sort medium
	{
		i = stack_size(*stack_a) - 2;
		while (i >= 0)
		{
			num = stack_size(*stack_a) / 5;
			pair->low = (median_rank(*stack_a, num * -1));
			pair->high = (median_rank(*stack_a, num));
			if (*stack_b == NULL)
			{
				while (*stack_a == min_rank(*stack_a, 0) || \
				*stack_a == max_rank(*stack_a, 0))
					ra(stack_a, stack_b, op_counter);
				pb(stack_a, stack_b, op_counter);
			}
			else
			{
				pair = best_a_to_b(*stack_a, *stack_b, pair);
				move_pair_to_top(pair, stack_a, stack_b, op_counter);
				pb(stack_a, stack_b, op_counter);
			}
			i--;
		}

		next_node = max_rank(*stack_b, 0);
		move_to_top_b(next_node, stack_a, stack_b, op_counter);

		if ((*stack_a)->rank == 1)
			ra(stack_a, stack_b, op_counter);
		i = stack_size(*stack_b);
		while (i >= 0)
		{
			pa(stack_a, stack_b, op_counter);
			i--;
		}
		if ((*stack_a)->prev->rank == 1)
			rra(stack_a, stack_b, op_counter);
	} 
	else
	{
		i = stack_size(*stack_a) - 2;
		while (i >= 0)
		{
			num = stack_size(*stack_a) / 4;
			pair->low = (min_rank(*stack_a, 0));
			pair->high = (min_rank(*stack_a, num));
			next_node = okayest(*stack_a, pair);
			move_to_top_a(next_node, stack_a, stack_b, op_counter);
			push_swap_a_to_b(stack_a, stack_b, op_counter);
			i--;
		}
		i = stack_size(*stack_b);
		pair->low = (min_rank(*stack_b, 0));
		pair->high = (max_rank(*stack_b, 0));
		while (i >= 0)
		{
			pair = best_b_to_a(*stack_a, *stack_b, pair);
			move_pair_to_top(pair, stack_a, stack_b, op_counter);
			pa(stack_a, stack_b, op_counter);
			i--;
		}
		if (!is_sorted(*stack_a))
		{
			next_node = min_rank(*stack_a, 0);
			move_to_top_a(next_node, stack_a, stack_b, op_counter);
		}
	}
} */
