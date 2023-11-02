/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:23:50 by tday              #+#    #+#             */
/*   Updated: 2023/11/02 16:07:41 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

void	push_back_to_a(t_node **stack_a, t_node **stack_b, int *op_counter);

Summary
This is a support function for the sort_medium function. It is responsible for
pushing all elements from stack B back to stack A in a specific order.

Inputs
stack_a: a pointer to the top of stack A
stack_b: a pointer to the top of stack B
op_counter: a pointer to an integer variable that keeps track of the number of
operations performed

Flow
1. Find the node with the maximum rank in stack B and store it in the variable
node.
2. Move the node node to the top of stack B by calling the move_to_top_b
function.
3. If the top element of stack A has a rank of 1, rotate stack A to bring the
next element to the top.
4. Iterate over stack B and push each element to stack A by calling the pa
function.
5. If the element that was previously at the top of stack A (before the rotation)
has a rank of 1, rotate stack A in the reverse direction to bring it back to the
top.

Outputs
None. The function modifies the stacks and updates the op_counter variable.

*/
void	push_back_to_a(t_node **stack_a, t_node **stack_b, int *op_counter)
{
	int		i;
	t_node	*node;

	node = max_rank(*stack_b, 0);
	move_to_top_b(node, stack_a, stack_b, op_counter);
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

/*

void	sort_medium(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair);

Summary
The 'sort_medium' function sorts a medium-sized stack containing fewer than 120
integers into ascending order. It pushes the nodes from stack_a to stack_b,
sorting them in descending order in the process, except for the minimum and
maximum nodes. Once they are all sorted in stack_b, they are then pushed back
to stack_a, which results in stack_a being sorted in ascending order.

Inputs
stack_a: a pointer to the top of stack A, which contains the integers to be
sorted.
stack_b: a pointer to the top of stack B, which is initially empty.
op_counter: a pointer to an integer variable that keeps track of the number of
operations performed.
pair: a pointer to a structure that holds two integers (low and high)
representing the range of ranks to consider for sorting.

Flow
1. Initialize a variable i to the size of stack_a minus 2.
2. Iterate i from its initial value down to 0.
3. Calculate the value of num by dividing the size of stack_a by 5.
4. Set pair->low to the median rank of the bottom num elements of stack_a
(negative range).
5. Set pair->high to the median rank of the top num elements of stack_a.
6. If stack_b is empty, move elements from stack_a to stack_b until the top
element of stack_a is not the minimum or maximum rank.
7. Push the top element of stack_a to stack_b.
8. If stack_b is not empty, find the best pair of elements (pair) to move
from stack_a to stack_b using the best_a_to_b function.
9. Move the best pair of elements to the top of stack_a and stack_b using
the move_pair_to_top function.
10. Push the top element of stack_a to stack_b.
11. Decrement i by 1.

Outputs
None. The function modifies the stacks stack_a and stack_b and updates the
op_counter variable.

*/
void	sort_medium(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair)
{
	int		i;
	int		num;

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
	push_back_to_a(stack_a, stack_b, op_counter);
}

/*

void	sort_back_to_a(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair);

Summary
The sort_back_to_a function is a support function for the 'sort_large' function.
It is responsible for sorting the elements in stack B and pushing them back to
stack A in a specific order.

Inputs
stack_a: a pointer to the top of stack A, which contains the elements to be
sorted.
stack_b: a pointer to the top of stack B, which is initially empty.
op_counter: a pointer to an integer variable that keeps track of the number of
operations performed.
pair: a pointer to a structure that holds two integers (low and high)
representing the range of ranks to consider for sorting.

Flow
1. Initialize a variable i to the size of stack B.
2. Set pair->low to the minimum rank in stack B.
3. Set pair->high to the maximum rank in stack B.
4. Iterate i from its initial value down to 0.
5. Find the best pair of elements (pair) to move from stack B to stack A using
the best_b_to_a function.
6. Move the best pair of elements to the top of stack A and stack B using the
move_pair_to_top function.
7. Push the top element of stack B to stack A using the pa function.
8. Decrement i by 1.
9. If stack A is not sorted, find the minimum element in stack A and move it to
the top using the move_to_top_a function.

Outputs
None. The function modifies the stacks stack_a and stack_b and updates the
op_counter variable.

*/
void	sort_back_to_a(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair)
{
	int		i;
	t_node	*node;

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
		node = min_rank(*stack_a, 0);
		move_to_top_a(node, stack_a, stack_b, op_counter);
	}
}

/*

void	sort_large(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair);

Summary
The sort_large function is responsible for sorting large-sized stacks of integers
in ascending order. IT pushes the cheapest node that is ranked in the bottom
quarter of nodes in stack_a over to stack_b and if that node is ranked lower than
the node below it in stack_b, it swaps them. It repeats that until there are only
2 stacks left in stack_a resulting in stack_b being partially sorted. It then
properly sorts them when moving them back to stack_a.

Inputs
stack_a: a pointer to the top of stack A, which contains the elements to be
sorted.
stack_b: a pointer to the top of stack B, which is initially empty.
op_counter: a pointer to an integer variable that keeps track of the number of
operations performed.
pair: a pointer to a structure that holds two integers (low and high)
representing the range of ranks to consider for sorting.

Flow
1. Initialize a variable i to the size of stack_a minus 2.
2. Iterate i from its initial value down to 0.
3. Calculate the value of num by dividing the size of stack_a by 4.
4. Set pair->low to the minimum rank in stack_a.
5. Set pair->high to the minimum rank in stack_a within the range of num.
6. Find the node with the best rank (node) within the range specified by pair
using the okayest function.
7. Move the node to the top of stack_a and stack_b using the move_to_top_a
function.
8. Push the elements from stack_a to stack_b using the push_swap_a_to_b function.
9. Decrement i by 1.
10. Sort the elements in stack_b and push them back to stack_a in a specific
order using the sort_back_to_a function.

Outputs
None. The function modifies the stacks stack_a and stack_b and updates the
op_counter variable.

*/
void	sort_large(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair)
{
	int		i;
	int		num;
	t_node	*node;

	i = stack_size(*stack_a) - 2;
	while (i >= 0)
	{
		num = stack_size(*stack_a) / 4;
		pair->low = (min_rank(*stack_a, 0));
		pair->high = (min_rank(*stack_a, num));
		node = okayest(*stack_a, pair);
		move_to_top_a(node, stack_a, stack_b, op_counter);
		push_swap_a_to_b(stack_a, stack_b, op_counter);
		i--;
	}
	sort_back_to_a(stack_a, stack_b, op_counter, pair);
}
