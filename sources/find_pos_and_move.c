/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_and_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:02:53 by tday              #+#    #+#             */
/*   Updated: 2023/11/01 17:52:02 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

t_node	*find_pos_a_to_b(t_node *node, t_node *target_stack);

Summary
This code defines a function find_pos_a_to_b that takes in two parameters: a node
and a target stack. The function finds the position of the node in the target
stack and returns the corresponding node.

Inputs
node: a pointer to a node in the stack
target_stack: a pointer to the target stack

Flow
1. Get the rank of the node.
2. Set the first_flag to 1 to indicate the first iteration of the loop.
3. Set the current node to the target_stack.
4. Find the minimum and maximum ranked nodes in the target_stack.
5. If the rank of the node is less than the rank of the minimum node or greater
than the rank of the maximum node, return the maximum node.
6. Otherwise, iterate through the target_stack until the current node's index is
0 or it is the first iteration.
7. If the current node's rank is less than the rank of the node and the previous
node's rank is greater than the rank of the node, break the loop.
8. Update the current node to the next node.
9. Set the first_flag to 0 to indicate subsequent iterations.
10. Return the current node.

Outputs
current: a pointer to the node in the target stack that corresponds to the
position of the input node.

*/
t_node	*find_pos_a_to_b(t_node *node, t_node *target_stack)
{
	int		node_rank;
	int		first_flag;
	t_node	*current;
	t_node	*min_node;
	t_node	*max_node;

	node_rank = node->rank;
	first_flag = 1;
	current = target_stack;
	min_node = min_rank(target_stack, 0);
	max_node = max_rank(target_stack, 0);
	if (node_rank < min_node->rank || node_rank > max_node->rank)
		return (max_node);
	else
	{
		while (current->index != 0 || first_flag)
		{
			if (current->rank < node_rank && current->prev->rank > node_rank)
				break ;
			current = current->next;
			first_flag = 0;
		}
	}
	return (current);
}

/*

t_node	*find_pos_b_to_a(t_node *node, t_node *target_stack);

Summary
This code defines a function find_pos_b_to_a that takes in two parameters: a node
and a target stack. The function finds the position of the node in the target
stack and returns the corresponding node.

Inputs
node: a pointer to a node in the stack
target_stack: a pointer to the target stack

Flow
1. Get the rank of the node.
2. Set the first_flag to 1 to indicate the first iteration of the loop.
3. Set the current node to the target_stack.
4. Find the minimum and maximum ranked nodes in the target_stack.
5. If the rank of the node is less than the rank of the minimum node or greater
than the rank of the maximum node, return the minimum node.
6. Otherwise, iterate through the target_stack until the current node's index is
0 or it is the first iteration.
7. If the current node's rank is greater than the rank of the node and the
previous node's rank is less than the rank of the node, break the loop.
8. Update the current node to the next node.
9. Set the first_flag to 0 to indicate subsequent iterations.
10. Return the current node.

Outputs
current: a pointer to the node in the target stack that corresponds to the
position of the input node.

*/
t_node	*find_pos_b_to_a(t_node *node, t_node *target_stack)
{
	int		node_rank;
	int		first_flag;
	t_node	*current;
	t_node	*min_node;
	t_node	*max_node;

	node_rank = node->rank;
	first_flag = 1;
	current = target_stack;
	min_node = min_rank(target_stack, 0);
	max_node = max_rank(target_stack, 0);
	if (node_rank < min_node->rank || node_rank > max_node->rank)
		return (min_node);
	else
	{
		while (current->index != 0 || first_flag)
		{
			if (current->rank > node_rank && current->prev->rank < node_rank)
				break ;
			current = current->next;
			first_flag = 0;
		}
	}
	return (current);
}

/*

void	move_to_top_a(t_node *node, t_node **stack_a, t_node **stack_b, \
int *op_counter);

Summary
This code defines a function move_to_top_a that moves a given node to the top
of stack A. The function takes in four parameters: a node, a pointer to stack A,
a pointer to stack B, and a pointer to an operation counter. It determines the
position of the node in stack A and moves it to the top by performing the
appropriate rotation operations (ra or rra).

Inputs
node: a pointer to the node that needs to be moved to the top of stack A.
stack_a: a pointer to stack A.
stack_b: a pointer to stack B.
op_counter: a pointer to an integer that keeps track of the number of operations
performed.

Flow
1. Get the position of the node in stack A.
2. Get the size of stack A.
3. If the position is less than or equal to half the size of stack A, perform a
series of ra operations to move the node to the top.
4. Otherwise, perform a series of rra operations to move the node to the top.
Update the operation counter accordingly.

Outputs
The node is moved to the top of stack A.

*/
void	move_to_top_a(t_node *node, t_node **stack_a, t_node **stack_b, \
int *op_counter)
{
	int		position;
	int		size;

	position = node->index;
	size = stack_size(*stack_a);
	if (position <= size / 2)
	{
		while (position > 0)
		{
			ra(stack_a, stack_b, op_counter);
			position--;
		}
	}
	else
	{
		while (position <= size)
		{
			rra(stack_a, stack_b, op_counter);
			position++;
		}
	}
}

/*

void	move_to_top_b(t_node *node, t_node **stack_a, t_node **stack_b, \
int *op_counter);

Summary
This code defines a function move_to_top_b that moves a given node to the top of
stack B. The function takes in four parameters: a node, a pointer to stack A,
a pointer to stack B, and a pointer to an operation counter. It determines the
position of the node in stack B and moves it to the top by performing the
appropriate rotation operations (rb or rrb).

Inputs
node: a pointer to the node that needs to be moved to the top of stack B.
stack_a: a pointer to stack A.
stack_b: a pointer to stack B.
op_counter: a pointer to an integer that keeps track of the number of operations
performed.

Flow
1. Get the position of the node in stack B.
2. Get the size of stack B.
3. If the position is less than or equal to half the size of stack B, perform a
series of rb operations to move the node to the top.
4. Otherwise, perform a series of rrb operations to move the node to the top.
Update the operation counter accordingly.

Outputs
The node is moved to the top of stack B.

*/
void	move_to_top_b(t_node *node, t_node **stack_a, t_node **stack_b, \
int *op_counter)
{
	int		position;
	int		size;

	position = node->index;
	size = stack_size(*stack_b);
	if (position <= size / 2)
	{
		while (position > 0)
		{
			rb(stack_a, stack_b, op_counter);
			position--;
		}
	}
	else
	{
		while (position <= size)
		{
			rrb(stack_a, stack_b, op_counter);
			position++;
		}
	}
}
