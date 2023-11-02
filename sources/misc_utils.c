/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:08:33 by tday              #+#    #+#             */
/*   Updated: 2023/11/01 23:13:13 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

int	stack_size(t_node *stack);

Summary
The stack_size function calculates the size of a stack by iterating through the
linked list and finding the maximum index value.

Inputs
stack (t_node*): A pointer to the head of the stack.

Flow
1. Initialize max_index variable with the index value of the head of the stack.
2. Set current pointer to the next node of the head.
3. Iterate through the linked list until current becomes equal to the head.
4. If the index value of the current node is greater than max_index, update
max_index with the current node's index value.
5. Move current to the next node.
6. Return max_index, which represents the size of the stack.

Outputs
max_index (int): The size of the stack.

*/
int	stack_size(t_node *stack)
{
	int		max_index;
	t_node	*current;

	max_index = stack->index;
	current = stack->next;
	while (current != stack)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

/*

int	count_ops(t_node *node, t_node *stack_x);

Summary
The count_ops function calculates the number of operations needed to move a node
to the top of a stack. It takes two parameters: node, which is the node to be
moved, and stack_x, which is the stack containing the node.

Inputs
node (t_node*): A pointer to the node that needs to be moved to the top of the
stack.
stack_x (t_node*): A pointer to the stack that contains the node.

Flow
1. Calculate the size of the stack by getting the index of the last node in the
stack (stack_x->prev->index).
2. Get the index of the node that needs to be moved (node->index).
3. Calculate the midpoint of the stack by dividing the stack size by 2
(stack_size / 2).
4. If the index of the node is less than or equal to the midpoint, set the
number of operations (ops) to be equal to the index of the node.
5. Otherwise, set ops to be equal to the difference between the stack size and
the index of the node, plus 1.
6. Return the number of operations (ops).

Outputs
ops (int): The number of operations needed to move the node to the top of the
stack.

*/
int	count_ops(t_node *node, t_node *stack_x)
{
	int		ops;
	int		mid;
	int		stack_size;
	int		node_index;

	stack_size = stack_x->prev->index;
	node_index = node->index;
	mid = stack_size / 2;
	if (node_index <= mid)
		ops = node_index;
	else
		ops = stack_size - node_index + 1;
	return (ops);
}

/*

int	is_sorted(t_node *stack_x);

Summary
The is_sorted function checks if a given stack is sorted in ascending order
based on the rank value of each node.

Inputs
stack_x (t_node*): A pointer to the head of the stack.

Flow
1. Check if stack_x is NULL. If it is, return -1 to indicate an error.
2. Initialize sorted variable to 0.
3. Iterate through the stack until the next node's index is 0 (indicating
the end of the stack).
4. Check if the next node is NULL. If it is, return -1 to indicate an error.
5. Compare the rank value of the current node with the rank value of the next
node.
6. If the current node's rank is greater than or equal to the next node's rank,
the stack is not sorted. Set sorted to 0 and return.
7. Otherwise, set sorted to 1 to indicate that the stack is sorted.
8. Move to the next node in the stack.
9. Return the value of sorted.

Outputs
sorted (int): 0 if the stack is not sorted, 1 if the stack is sorted.

*/
int	is_sorted(t_node *stack_x)
{
	int	sorted;

	if (stack_x == NULL)
		return (-1);
	sorted = 0;
	while (stack_x->next->index != 0)
	{
		if (stack_x->next == NULL)
			return (-1);
		if (stack_x->rank >= stack_x->next->rank)
			return (sorted = 0);
		else
			sorted = 1;
		stack_x = stack_x->next;
	}
	return (sorted);
}

/*

void	free_null_stack(t_node **stack);

Summary
The free_null_stack function is responsible for freeing the memory allocated for
a stack. It takes a double pointer to the stack as input and sets the stack
pointer to NULL after freeing the memory.

Inputs
stack (t_node**): A double pointer to the stack that needs to be freed.

Flow
1. Set current pointer to the stack.
2. Check if current is NULL. If it is, return.
3. Set the next pointer of the last node in the stack to NULL to indicate the end
of the stack.
4. Iterate through the stack until current becomes NULL.
5. Set temp pointer to current.
6. Set current pointer to the next node in the stack.
7. Free the memory allocated for temp.
8. Repeat steps 5-7 until current becomes NULL.
9. Set the stack pointer to NULL.

Outputs
None. The function frees the memory allocated for the stack.

*/
void	free_null_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*current;

	current = *stack;
	if (!current)
		return ;
	current->prev->next = NULL;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}
