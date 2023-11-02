/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:26:17 by tday              #+#    #+#             */
/*   Updated: 2023/11/01 23:15:36 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

void	push(t_node **stack_x, t_node **stack_y);

Summary
The push function takes two double pointers to t_node structs as input. It
removes a node from the top of the first stack (stack_x) and adds it to the
top of the second stack (stack_y).

Inputs
stack_x: A double pointer to the first stack (stack_x).
stack_y: A double pointer to the second stack (stack_y).

Flow
1. The function first calls the remove_node function to remove a node from the
top of stack_x. The removed node is assigned to the push_node variable.
2. Then, the function calls the add_node function to add the push_node to the
top of stack_y.
3. The add_node function updates the next and previous pointers of the nodes in
stack_y to properly insert the push_node at the top.
4. Finally, the push_node is assigned as the new top of stack_y.

Outputs
The function does not return any value. It modifies the stack_x and stack_y
pointers indirectly by removing and adding nodes.

*/
void	push(t_node **stack_x, t_node **stack_y)
{
	t_node	*push_node;

	push_node = remove_node(stack_x);
	add_node(stack_y, push_node);
}

/*

t_node	*remove_node(t_node **stack_x);

Summary
The remove_node function removes a node from the top of a stack and updates the
stack pointer accordingly.

Inputs
stack_x: A double pointer to the stack from which the node is to be removed.

Flow
1. The function first checks if the stack_x pointer is NULL. If it is, the
function returns NULL.
2. The function assigns the value of *stack_x to the push_node variable, which
represents the node to be removed.
3. If the push_node is the only node in the stack (i.e., push_node->next points
to itself), the function sets *stack_x to NULL.
4. Otherwise, the function updates the next and prev pointers of the nodes
surrounding push_node to bypass it.
5. The function then updates *stack_x to point to the next node after push_node.
6. The function also updates the index values of the nodes after push_node to
reflect the removal of the node.
7. Finally, the next and prev pointers of push_node are set to NULL, and
push_node is returned.

Outputs
The function returns the removed node (push_node) or NULL if the stack is empty.

*/
t_node	*remove_node(t_node **stack_x)
{
	t_node	*push_node;
	t_node	*temp_node;

	if (stack_x == NULL)
		return (NULL);
	push_node = *stack_x;
	if (push_node->next == push_node)
		*stack_x = NULL;
	else
	{
		push_node->prev->next = push_node->next;
		push_node->next->prev = push_node->prev;
		*stack_x = push_node->next;
		temp_node = push_node->next;
		while (temp_node->index != 0)
		{
			temp_node->index -= 1;
			temp_node = temp_node->next;
		}
	}
	push_node->next = NULL;
	push_node->prev = NULL;
	return (push_node);
}

/*

void	add_node(t_node **stack_y, t_node *push_node);

Summary
The add_node function adds a node to the top of a stack. It takes a double
pointer to the stack (stack_y) and a pointer to the node to be added
(push_node) as inputs.

Inputs
stack_y: A double pointer to the stack where the node will be added.
push_node: A pointer to the node that will be added to the stack.

Flow
1. The function first checks if the push_node is NULL. If it is, the function
returns without making any changes.
2. If the stack_y is NULL, it means the stack is empty. In this case, the next
and prev pointers of the push_node are set to point to itself, creating a
circular reference.
3. If the stack_y is not NULL, the next and prev pointers of the push_node are
set to the current top of the stack (*stack_y) and the previous node of the top
((*stack_y)->prev), respectively.
4. The next pointer of the previous node of the top ((*stack_y)->prev->next)
is updated to point to the push_node, and the prev pointer of the top
((*stack_y)->prev) is updated to point to the push_node, effectively inserting
the push_node at the top of the stack.
5. The index value of the top of the stack is set to 1, indicating that it is no
longer the first node in the stack.
6. The function then iterates through the nodes in the stack, starting from the
next node after the top, and increments their index values by 1 to reflect the
insertion of the push_node.
7. Finally, the stack_y pointer is updated to point to the push_node, making it
the new top of the stack.

Outputs
The function does not return any value. It modifies the stack_y pointer
indirectly by adding the push_node to the top of the stack.

*/
void	add_node(t_node **stack_y, t_node *push_node)
{
	t_node	*temp_node;

	if (push_node == NULL)
		return ;
	if (*stack_y == NULL)
	{
		push_node->next = push_node;
		push_node->prev = push_node;
	}
	else
	{
		push_node->next = *stack_y;
		push_node->prev = (*stack_y)->prev;
		(*stack_y)->prev->next = push_node;
		(*stack_y)->prev = push_node;
		(*stack_y)->index = 1;
		temp_node = (*stack_y)->next;
		while (temp_node->index != 0)
		{
			temp_node->index += 1;
			temp_node = temp_node->next;
		}
	}
	*stack_y = push_node;
}

/*

void	pa(t_node **stack_a, t_node **stack_b, int *opp_counter);

Summary
The pa function is used to move the top element from stack B to stack A. It
takes two double pointers to t_node structs as input, representing the stacks,
and an integer pointer to keep track of the number of operations performed. If
stack B is not empty, the function calls the push function to remove the top
element from stack B and add it to the top of stack A. It then increments the
operation counter and prints "pa" using the ft_printf function.

Inputs
stack_a: A double pointer to the stack A.
stack_b: A double pointer to the stack B.
opp_counter: An integer pointer to keep track of the number of operations
performed.

Flow
1. Check if stack B is empty. If it is, return without performing any operations.
2. Call the push function with stack_b as the first argument and stack_a as
the second argument to move the top element from stack B to stack A.
3. Increment the opp_counter by 1.
4. Print "pa" using the ft_printf function.

Outputs
The top element from stack B is moved to stack A.
The opp_counter is incremented by 1.
"pa" is printed.

*/
void	pa(t_node **stack_a, t_node **stack_b, int *opp_counter)
{
	if (*stack_b == NULL)
		return ;
	push(stack_b, stack_a);
	(*opp_counter)++;
	ft_printf("pa\n");
}

/*

void	pb(t_node **stack_a, t_node **stack_b, int *opp_counter);

Summary
The pb function is used to move the top element from stack A to stack B. It takes
two double pointers to t_node structs as input, representing the stacks, and an
integer pointer to keep track of the number of operations performed. If stack A
is not empty, the function calls the push function to remove the top element from
stack A and add it to the top of stack B. It then increments the operation
counter and prints "pb" using the ft_printf function.

Inputs
stack_a: A double pointer to the stack A.
stack_b: A double pointer to the stack B.
opp_counter: An integer pointer to keep track of the number of operations
performed.

Flow
1. Check if stack A is empty. If it is, return without performing any operations.
2. Call the push function with stack_a as the first argument and stack_b as the
second argument to move the top element from stack A to stack B.
3. Increment the opp_counter by 1.
4. Print "pb" using the ft_printf function.

Outputs
The top element from stack A is moved to stack B. The opp_counter is incremented
by 1. "pb" is printed.

*/
void	pb(t_node **stack_a, t_node **stack_b, int *opp_counter)
{
	if (*stack_a == NULL)
		return ;
	push(stack_a, stack_b);
	(*opp_counter)++;
	ft_printf("pb\n");
}
