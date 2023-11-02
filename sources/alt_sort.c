/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:32:29 by tday              #+#    #+#             */
/*   Updated: 2023/11/02 16:05:20 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

void	alt_sort(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair)

Summary
An alternative version of the 'sort' function that uses a different sorting
algorithm for sorting medium sized stacks.

Inputs
stack_a: a pointer to the first node of the stack A.
stack_b: a pointer to the first node of the stack B.
op_counter: a pointer to an integer variable that keeps track of the number of
operations performed.
pair: a pointer to a structure that holds information about the median and other
values used in the sorting algorithm.

Flow
1. The function determines the size of the stack_a by calling the stack_size
function.
2. If the size of stack_a is less than 10, the function calls the sort_small
function to sort the stacks.
3. If the size of stack_a is between 10 and 120, the function calls the
sort_alt_med function to sort the stacks.
4. If the size of stack_a is greater than 120, the function calls the sort_large
function to sort the stacks.

Outputs
The stack_a and stack_b stacks are sorted according to the alternative sorting
algorithm.

*/
void	alt_sort(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair)
{
	int		num;

	num = stack_size(*stack_a);
	if (num < 10)
		sort_small(stack_a, stack_b, op_counter);
	else if (num < 120)
		sort_alt_med(stack_a, stack_b, op_counter, pair);
	else
		sort_large(stack_a, stack_b, op_counter, pair);
}

/*

void	push_around_median(t_node **stack_a, t_node **stack_b, \
int *op_counter, t_pair *pair);

Summary
The push_around_median function is a support function for 'sort_alt_med' due to
norminette constraints. It moves the median node from stack A to stack B, then
finds the cheapest node in stack_a whos rank is within the range and pushes it
to stack_b. If the node's rank is lower than the median node's rank, it rotates
stack_b to partially sort the stack with all nodes ranked above median above the
median node in the stack and all nodes ranked below, below.

Inputs
stack_a: a pointer to the first node of stack A.
stack_b: a pointer to the first node of stack B.
op_counter: a pointer to an integer variable that keeps track of the number of
operations performed.
pair: a pointer to a structure that holds information about the median and other
values used in the sorting algorithm.

Flow
1. Check if stack B is empty.
2. If stack B is empty, move the median node from stack A to stack B.
3. If stack B is not empty, find the node with the highest rank that is less than
or equal to the median node's rank.
4. Move the found node to the top of stack A.
5. If the found node's rank is greater than the median node's rank, perform a
push_swap operation to move it from stack A to stack B.
6. If the found node's rank is less than or equal to the median node's rank,
perform a push and rotate operation to move it from stack A to stack B.

Outputs
There are no explicit outputs from this function. It modifies the stacks and the
operation counter indirectly through the pointers passed as arguments.

*/
void	push_around_median(t_node **stack_a, t_node **stack_b, \
int *op_counter, t_pair *pair)
{
	t_node	*node;

	if (*stack_b == NULL)
	{
		move_to_top_a(pair->median, stack_a, stack_b, op_counter);
		pb(stack_a, stack_b, op_counter);
	}
	else
	{
		node = okayest(*stack_a, pair);
		move_to_top_a(node, stack_a, stack_b, op_counter);
		if (node->rank > pair->median->rank)
			push_swap_a_to_b(stack_a, stack_b, op_counter);
		else
		{
			pb(stack_a, stack_b, op_counter);
			rb(stack_a, stack_b, op_counter);
		}
	}
}

/*

void	sort_alt_med(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair);

Summary
The sort_alt_med function is an alternative sorting algorithm for medium-sized
stacks. It uses the push_around_median function to partially sort the stack as
it pushes them to stack_b, starting with nodes ranked close to the median node
and working towards the minimum and maximum ranked nodes. It then sorts the nodes
when moving them back to stack_a by looking for the nodes that will be cheapest
to move to the correct position.

Inputs
stack_a: a pointer to the first node of stack A.
stack_b: a pointer to the first node of stack B.
op_counter: a pointer to an integer variable that keeps track of the number of
operations performed.
pair: a pointer to a structure that holds information about the median and other
values used in the sorting algorithm.

Flow
1. Calculate the median rank of stack A and assign it to pair->median.
2. While the index of the second-to-last node in stack A is greater than 1:
3. Calculate the range of ranks for the nodes to be moved around the median.
4. Call the push_around_median function to move nodes from stack A to stack B.
5. Move the remaining nodes from stack B back to stack A in the correct order.
6. Check if stack A is sorted. If not, move the minimum ranked node to the top
of stack A.

Outputs
There are no explicit outputs from this function. It indirectly modifies the
stacks and the operation counter through the pointers passed as arguments.

*/
void	sort_alt_med(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair)
{
	int		i;
	int		num;
	t_node	*node;

	pair->median = median_rank(*stack_a, 0);
	while ((*stack_a)->prev->index > 1)
	{
		num = stack_size(*stack_a) / 9;
		pair->low = (median_rank(*stack_a, num * -1));
		pair->high = (median_rank(*stack_a, num));
		push_around_median(stack_a, stack_b, op_counter, pair);
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
		node = min_rank(*stack_a, 0);
		move_to_top_a(node, stack_a, stack_b, op_counter);
	}
}

/* void	sort_alt_med(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair)
{
	int		i;
	int		num;
	t_node	*node;
	t_node	*median_node;

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
			node = okayest(*stack_a, pair);
			move_to_top_a(node, stack_a, stack_b, op_counter);
			if (node->rank > median_node->rank)
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
		node = min_rank(*stack_a, 0);
		move_to_top_a(node, stack_a, stack_b, op_counter);
	}
} */
