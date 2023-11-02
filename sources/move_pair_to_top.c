/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pair_to_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:51:51 by tday              #+#    #+#             */
/*   Updated: 2023/11/01 17:40:45 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

void	move_pair_to_top(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter);

Summary
This function move_pair_to_top is responsible for moving a pair of nodes to the
top of two stacks (stack_a and stack_b). The function first calculates the
midpoints of both stacks. If both nodes in the pair have indices less than or
equal to their respective midpoints, the function determines which node has a
smaller index and rotates both stacks accordingly. If both nodes have indices
greater than their respective midpoints, the function determines which node
requires fewer operations to reach the top of its stack and performs reverse
rotations accordingly. If the nodes have indices on opposite sides of their
midpoints, the function moves each node individually to the top of its stack.

Inputs
pair: a pointer to a structure representing a pair of nodes
stack_a: a pointer to a pointer to the first node of stack A
stack_b: a pointer to a pointer to the first node of stack B
op_counter: a pointer to an integer representing the operation counter

Flow
1. Calculate the midpoints of both stacks by dividing the size of each stack by
2.
2. Check if both nodes in the pair have indices less than or equal to their
respective midpoints.
3. If true, determine which node has a smaller index and rotate both stacks
accordingly using the rotate_both_rb or rotate_both_ra functions.
4. If both nodes have indices greater than their respective midpoints, determine
which node requires fewer operations to reach the top of its stack using the
count_ops function.
5. Perform reverse rotations using the rev_rot_both_rb or rev_rot_both_ra
functions based on the result of the previous step.
6. If the nodes have indices on opposite sides of their midpoints, move each node
individually to the top of its stack using the move_to_top_a and move_to_top_b
functions.

Outputs
This function does not have a return value. It modifies the stacks stack_a and
stack_b by performing rotations and reverse rotations to move the pair of nodes
to the top. The op_counter variable is also updated to keep track of the number
of operations performed.

*/
void	move_pair_to_top(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter)
{
	int	mid_a;
	int	mid_b;

	mid_a = stack_size(*stack_a) / 2;
	mid_b = stack_size(*stack_b) / 2;
	if (pair->a->index <= mid_a && pair->b->index <= mid_b)
	{
		if (pair->a->index <= pair->b->index)
			rotate_both_rb(pair, stack_a, stack_b, op_counter);
		else
			rotate_both_ra(pair, stack_a, stack_b, op_counter);
	}
	else if (pair->a->index > mid_a && pair->b->index > mid_b)
	{
		if (count_ops(pair->a, *stack_a) <= count_ops(pair->b, *stack_b))
			rev_rot_both_rb(pair, stack_a, stack_b, op_counter);
		else
			rev_rot_both_ra(pair, stack_a, stack_b, op_counter);
	}
	else
	{
		move_to_top_a(pair->a, stack_a, stack_b, op_counter);
		move_to_top_b(pair->b, stack_a, stack_b, op_counter);
	}
}

/*

void	rotate_both_ra(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter);

Summary
The rotate_both_ra function is responsible for rotating both stacks, stack_a and
stack_b, in order to move a pair of nodes to the top of the stacks, in the
scenario where the node in 'stack_a' is further from the top than the node in
'stack_b'. It first rotates both stacks pair->b->index times, to get the node in
'stack_b' to the top, and move 'stack_a closer. It then rotates stack_a
pair->a->index - pair->b->index times, to get the node in 'stack_a' to the top.

Inputs
pair: a pointer to a structure representing a pair of nodes.
stack_a: a pointer to a pointer to the first node of stack A.
stack_b: a pointer to a pointer to the first node of stack B.
op_counter: a pointer to an integer representing the operation counter.

Flow
1. Initialize i with the index of pair->b.
2. While i is greater than 0, rotate both stacks using the rr function and
decrement i.
3. Set i to the difference between the indices of pair->a and pair->b.
4. While i is greater than 0, rotate stack_a using the ra function and
decrement i.

Outputs
This function does not have a return value. It modifies the stacks stack_a and
stack_b by performing rotations to move the pair of nodes to the top.
The op_counter variable is also updated to keep track of the number of
operations performed.

*/
void	rotate_both_ra(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter)
{
	int	i;

	i = pair->b->index;
	while (i > 0)
	{
		rr(stack_a, stack_b, op_counter);
		i--;
	}
	i = pair->a->index - pair->b->index;
	while (i > 0)
	{
		ra(stack_a, stack_b, op_counter);
		i--;
	}
}

/*

void	rotate_both_rb(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter);

Summary
The rotate_both_rb function is responsible for rotating both stacks, stack_a and
stack_b, in order to move a pair of nodes to the top of the stacks, in the
scenario where the node in stack_b is further from the top than the node in
stack_a. It first rotates both stacks pair->a->index times, to get the node in
stack_a to the top, and move stack_b closer. It then rotates stack_b
pair->b->index - pair->a->index times, to get the node in stack_b to the top.

Inputs
pair: a pointer to a structure representing a pair of nodes.
stack_a: a pointer to a pointer to the first node of stack A.
stack_b: a pointer to a pointer to the first node of stack B.
op_counter: a pointer to an integer representing the operation counter.

Flow
1. Initialize i with the index of pair->a.
2. While i is greater than 0, rotate both stacks using the rr function and
decrement i.
3. Set i to the difference between the indices of pair->b and pair->a.
4. While i is greater than 0, rotate stack_b using the rb function and
decrement i.

Outputs
This function does not have a return value. It modifies the stacks stack_a and
stack_b by performing rotations to move the pair of nodes to the top.
The op_counter variable is also updated to keep track of the number of
operations performed.

*/
void	rotate_both_rb(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter)
{
	int	i;

	i = pair->a->index;
	while (i > 0)
	{
		rr(stack_a, stack_b, op_counter);
		i--;
	}
	i = pair->b->index - pair->a->index;
	while (i > 0)
	{
		rb(stack_a, stack_b, op_counter);
		i--;
	}
}

/*

void	rev_rot_both_ra(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter)

Summary
The rev_rot_both_ra function is responsible for moving a pair of nodes to the
top of the stacks stack_a and stack_b by performing reverse rotations. It first
calculates the number of operations required to move each node to the top using
the count_ops function. Then, it performs reverse rotations on both stacks to
move the node in stack_b to the top and the node in stack_a closer to the top.
Finally, it performs reverse rotations on stack_a to move the node in stack_a
to the top.

Inputs
pair: a pointer to a structure representing a pair of nodes
stack_a: a pointer to a pointer to the first node of stack A
stack_b: a pointer to a pointer to the first node of stack B
op_counter: a pointer to an integer representing the operation counter

Flow
1. Calculate the number of operations required to move the node in pair->a to
the top of stack_a using the count_ops function and store it in opps_a.
2. Calculate the number of operations required to move the node in pair->b to
the top of stack_b using the count_ops function and store it in opps_b.
3. Perform reverse rotations on both stacks using the rrr function opps_b times
to move the node in stack_b to the top and the node in stack_a closer to the top.
4. Perform reverse rotations on stack_a using the rra function opps_a - opps_b
times to move the node in stack_a to the top.

Outputs
This function does not have a return value. It modifies the stacks stack_a and
stack_b by performing reverse rotations to move the pair of nodes to the top.
The op_counter variable is also updated to keep track of the number of operations
performed.

*/
void	rev_rot_both_ra(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter)
{
	int	i;
	int	opps_a;
	int	opps_b;

	opps_a = count_ops(pair->a, *stack_a);
	opps_b = count_ops(pair->b, *stack_b);
	i = opps_b;
	while (i > 0)
	{
		rrr(stack_a, stack_b, op_counter);
		i--;
	}
	i = opps_a - opps_b;
	while (i > 0)
	{
		rra(stack_a, stack_b, op_counter);
		i--;
	}
}

/*

void	rev_rot_both_rb(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter)

Summary
This function rev_rot_both_rb is used to perform a reverse rotation operation on
both stack_a and stack_b based on the number of operations (opps_a and opps_b)
calculated for each element in the stacks.

Inputs
pair: a pointer to a t_pair struct that contains two elements a and b.
stack_a: a pointer to a pointer to a t_node struct representing stack A.
stack_b: a pointer to a pointer to a t_node struct representing stack B.
op_counter: a pointer to an integer representing the operation counter.

Flow
1. Calculate the number of operations (opps_a and opps_b) required to move
element pair->a to the top of stack_a and element pair->b to the top of
stack_b respectively.
2. Perform a reverse rotation operation on both stack_a and stack_b opps_a times
using the rrr function.
3. Perform a reverse rotation operation on stack_b opps_b - opps_a times using
the rrb function.

Outputs
The elements pair->a and pair->b are moved to the top of stack_a and stack_b
respectively, based on the calculated number of operations.

*/
void	rev_rot_both_rb(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter)
{
	int	i;
	int	opps_a;
	int	opps_b;

	opps_a = count_ops(pair->a, *stack_a);
	opps_b = count_ops(pair->b, *stack_b);
	i = opps_a;
	while (i > 0)
	{
		rrr(stack_a, stack_b, op_counter);
		i--;
	}
	i = opps_b - opps_a;
	while (i > 0)
	{
		rrb(stack_a, stack_b, op_counter);
		i--;
	}
}
