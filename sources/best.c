/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:02:19 by tday              #+#    #+#             */
/*   Updated: 2023/11/01 17:24:11 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

int	atob_pair_and_min_ops(t_node *stack_a, t_node *stack_b, t_pair *pair);

Summary
The atob_pair_and_min_ops function calculates the minimum number of operations
required to move an element from stack_a to stack_b. It updates the pair
structure with the best pair of nodes to perform the operation.

Inputs
stack_a: A pointer to the head of the first stack.
stack_b: A pointer to the head of the second stack.
pair: A pointer to a structure containing the low and high ranks.

Flow
1. Set the a field of the pair structure to stack_a.
2. Set the b field of the pair structure to the position of stack_a in stack_b.
3. If the rank of stack_a is within the range defined by pair->low and 
pair->high, return the number of operations required to move stack_a to stack_b.
4. Otherwise, return INT_MAX.

Outputs
The minimum number of operations required to move an element from stack_a to
stack_b.

*/
int	atob_pair_and_min_ops(t_node *stack_a, t_node *stack_b, t_pair *pair)
{
	pair->a = stack_a;
	pair->b = find_pos_a_to_b(stack_a, stack_b);
	if (stack_a->rank >= pair->low->rank && stack_a->rank <= pair->high->rank)
		return (count_ops(pair->b, stack_b));
	else
		return (INT_MAX);
}

/*

t_pair	*best_a_to_b(t_node *stack_a, t_node *stack_b, t_pair *pair);

Summary
The best_a_to_b function finds the best pair of nodes from stack_a and stack_b
to perform an operation. It calculates the minimum number of operations
required to move an element from stack_a to stack_b and updates the pair
structure with the best pair of nodes.

Inputs
stack_a: A pointer to the head of the first stack.
stack_b: A pointer to the head of the second stack.
pair: A pointer to a structure containing the low and high ranks.

Flow
1. Calculate the minimum number of operations required to move an element from
stack_a to stack_b using the atob_pair_and_min_ops function.
2. Iterate through each node in stack_a starting from the second node.
3. Find the position of the current node in stack_b using the find_pos_a_to_b
function.
4. Calculate the total number of operations required to move the current node
from stack_a to stack_b.
5. Check if the current node's rank is within the range defined by pair->low and
pair->high, and if the total number of operations is less than the minimum
number of operations found so far.
6. If the conditions are met, update the minimum number of operations, and update
the pair structure with the current node and its position in stack_b.
7. Repeat steps 3-6 for each node in stack_a.
8. Return the updated pair structure.

Outputs
The function returns the updated pair structure, which contains the best pair
of nodes from stack_a and stack_b to perform the operation.

*/
t_pair	*best_a_to_b(t_node *stack_a, t_node *stack_b, t_pair *pair)
{
	t_node	*current;
	t_node	*position;
	int		total_ops;
	int		min_ops;

	if (stack_b == NULL || stack_a == NULL)
		return (NULL);
	min_ops = atob_pair_and_min_ops(stack_a, stack_b, pair);
	current = stack_a->next;
	while (current != stack_a)
	{
		position = find_pos_a_to_b(current, stack_b);
		total_ops = count_ops(current, stack_a) + count_ops(position, stack_b);
		if (current->rank >= pair->low->rank && current->rank <= \
		pair->high->rank && total_ops < min_ops)
		{
			min_ops = total_ops;
			pair->a = current;
			pair->b = position;
		}
		current = current->next;
	}
	return (pair);
}

/*

int	btoa_pair_and_min_ops(t_node *stack_a, t_node *stack_b, t_pair *pair);

Summary
The btoa_pair_and_min_ops function calculates the minimum number of operations
required to move an element from stack_b to stack_a. It updates the pair
structure with the best pair of nodes to perform the operation.

Inputs
stack_a: A pointer to the head of the first stack.
stack_b: A pointer to the head of the second stack.
pair: A pointer to a structure containing the low and high ranks.

Flow
1. Set the b field of the pair structure to stack_b.
2. Set the a field of the pair structure to the position of stack_b in stack_a.
3. If the rank of stack_b is within the range defined by pair->low and
pair->high, return the number of operations required to move stack_b to stack_a.
4. Otherwise, return INT_MAX.

Outputs
The minimum number of operations required to move an element from stack_b to
stack_a.

*/
int	btoa_pair_and_min_ops(t_node *stack_a, t_node *stack_b, t_pair *pair)
{
	pair->b = stack_b;
	pair->a = find_pos_b_to_a(stack_b, stack_a);
	if (stack_b->rank >= pair->low->rank && stack_b->rank <= pair->high->rank)
		return (count_ops(pair->a, stack_a));
	else
		return (INT_MAX);
}

/*

t_pair	*best_b_to_a(t_node *stack_a, t_node *stack_b, t_pair *pair);

Summary
The best_b_to_a function finds the best pair of nodes from stack_a and stack_b
to perform an operation. It calculates the minimum number of operations
required to move an element from stack_b to stack_a and updates the pair
structure with the best pair of nodes.

Inputs
stack_a: A pointer to the head of the first stack.
stack_b: A pointer to the head of the second stack.
pair: A pointer to a structure containing the low and high ranks.

Flow
1. Calculate the minimum number of operations required to move an element from
stack_b to stack_a using the btoa_pair_and_min_ops function.
2. Iterate through each node in stack_b starting from the second node.
3. Find the position of the current node in stack_a using the find_pos_b_to_a
function.
4. Calculate the total number of operations required to move the current node
from stack_b to stack_a.
5. Check if the current node's rank is within the range defined by pair->low
and pair->high, and if the total number of operations is less than the minimum
number of operations found so far.
6. If the conditions are met, update the minimum number of operations, and
update the pair structure with the current node and its position in stack_a.
7. Repeat steps 3-6 for each node in stack_b.
8. Return the updated pair structure.

Outputs
The function returns the updated pair structure, which contains the best pair
of nodes from stack_a and stack_b to perform the operation.

*/
t_pair	*best_b_to_a(t_node *stack_a, t_node *stack_b, t_pair *pair)
{
	t_node	*current;
	t_node	*position;
	int		total_ops;
	int		min_ops;

	if (stack_b == NULL || stack_a == NULL)
		return (NULL);
	min_ops = btoa_pair_and_min_ops(stack_a, stack_b, pair);
	current = stack_b->next;
	while (current != stack_b)
	{
		position = find_pos_b_to_a(current, stack_a);
		total_ops = count_ops(position, stack_a) + count_ops(current, stack_b);
		if (current->rank >= pair->low->rank && current->rank <= \
		pair->high->rank && total_ops < min_ops)
		{
			min_ops = total_ops;
			pair->a = position;
			pair->b = current;
		}
		current = current->next;
	}
	return (pair);
}

/*

t_node	*okayest(t_node *stack, t_pair *pair);

Summary
The okayest function returns the node with the lowest number of operations
needed to move it to the correct position in the stack, within a given range
of ranks.

Inputs
stack: a pointer to the head of the stack
pair: a pointer to a pair struct containing the low and high ranks

Flow
1. Check if the stack is empty. If it is, return NULL.
2. Set the okayest node to the head of the stack.
3. If the rank of the head node is within the range specified by pair, return
the head node.
4. Initialize min_ops to the maximum integer value.
5. Iterate through the stack starting from the second node.
6. Calculate the number of operations needed to move the current node to the
correct position in the stack.
7. If the rank of the current node is within the range specified by pair and
the number of operations is less than min_ops, update min_ops and set okayest
to the current node.
8. Move to the next node in the stack.
9. Return the okayest node.

Outputs
okayest: a pointer to the node with the lowest number of operations within the
specified rank range.

*/
t_node	*okayest(t_node *stack, t_pair *pair)
{
	int		min_ops;
	int		current_ops;
	t_node	*current;
	t_node	*okayest;

	if (stack == NULL)
		return (NULL);
	okayest = stack;
	if (stack->rank >= pair->low->rank && stack->rank <= pair->high->rank)
		return (stack);
	min_ops = INT_MAX;
	current = stack->next;
	while (current != stack)
	{
		current_ops = count_ops(current, stack);
		if (current->rank >= pair->low->rank && current->rank <= \
		pair->high->rank && current_ops < min_ops)
		{
			min_ops = current_ops;
			okayest = current;
		}
		current = current->next;
	}
	return (okayest);
}
