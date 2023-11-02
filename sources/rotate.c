/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:51:26 by tday              #+#    #+#             */
/*   Updated: 2023/11/01 15:09:49 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

void	rotate(t_node **stack_x);

Summary
The rotate function is used to rotate a linked list by moving the first element
to the end of the list. It updates the index values of the nodes accordingly.

Inputs
stack_x: A pointer to a pointer to the head of the linked list.

Flow
1. Check if stack_x or *stack_x is NULL. If either is NULL, return.
2. Set temp_node to the next node of *stack_x.
3. Iterate through the linked list until the node with index 0 is found.
4. Decrement the index of each node by 1.
5. Set the index of the last node to the index of its previous node plus 1.
6. Update *stack_x to point to the next node.
7. The linked list is now rotated.

Outputs
None. The function modifies the linked list in-place.

*/
void	rotate(t_node **stack_x)
{
	t_node	*temp_node;

	if (stack_x == NULL || *stack_x == NULL)
		return ;
	temp_node = (*stack_x)->next;
	while (temp_node->index != 0)
	{
		temp_node->index -= 1;
		temp_node = temp_node->next;
	}
	temp_node->index = temp_node->prev->index + 1;
	*stack_x = (*stack_x)->next;
}

/*

void	ra(t_node **stack_a, t_node **stack_b, int *opp_counter);

Summary
The ra function is used to rotate the stack_a linked list by moving the first
element to the end of the list. It also increments the opp_counter variable by 1
and prints "ra" using the ft_printf function.

Inputs
stack_a: A pointer to a pointer to the head of the stack_a linked list.
stack_b: A pointer to a pointer to the head of the stack_b linked list.
opp_counter: A pointer to an integer variable that keeps track of the number of
operations performed.

Flow
1. Check if stack_a is NULL. If it is, return.
2. Call the rotate function passing stack_a as an argument to rotate the linked
list.
3. Increment the opp_counter variable by 1.
4. Print "ra" using the ft_printf function.

Outputs
None. The function modifies the stack_a linked list in-place and increments the
opp_counter variable by 1.

*/
void	ra(t_node **stack_a, t_node **stack_b, int *opp_counter)
{
	(void)stack_b;
	if (*stack_a == NULL)
		return ;
	rotate(stack_a);
	(*opp_counter)++;
	ft_printf("ra\n");
}

/*

void	rb(t_node **stack_a, t_node **stack_b, int *opp_counter);

Summary
The rb function is used to rotate the stack_b linked list by moving the first
element to the end of the list. It increments the opp_counter variable by 1 and
prints "rb" using the ft_printf function.

Inputs
stack_a: A pointer to a pointer to the head of the stack_a linked list.
stack_b: A pointer to a pointer to the head of the stack_b linked list.
opp_counter: A pointer to an integer variable that keeps track of the number of
operations performed.

Flow
1. Check if stack_b is NULL. If it is, return.
2. Call the rotate function passing stack_b as an argument to rotate the linked
list.
3. Increment the opp_counter variable by 1.
4. Print "rb" using the ft_printf function.

Outputs
None. The function modifies the stack_b linked list in-place and increments the
opp_counter variable by 1.

*/
void	rb(t_node **stack_a, t_node **stack_b, int *opp_counter)
{
	(void)stack_a;
	if (*stack_b == NULL)
		return ;
	rotate(stack_b);
	(*opp_counter)++;
	ft_printf("rb\n");
}

/*

void	rr(t_node **stack_a, t_node **stack_b, int *opp_counter);

Summary
The rr function is used to rotate both the stack_a and stack_b linked lists by
moving their first elements to the end of the lists. It also increments the
opp_counter variable by 1 and prints "rr" using the ft_printf function.

Inputs
stack_a: A pointer to a pointer to the head of the stack_a linked list.
stack_b: A pointer to a pointer to the head of the stack_b linked list.
opp_counter: A pointer to an integer variable that keeps track of the number of
operations performed.

Flow
1. Check if either stack_a or stack_b is NULL. If either is NULL, return.
2. Call the rotate function passing stack_a as an argument to rotate the stack_a
linked list.
3. Call the rotate function passing stack_b as an argument to rotate the stack_b
linked list.
4. Increment the opp_counter variable by 1.
5. Print "rr" using the ft_printf function.

Outputs
None. The function modifies both the stack_a and stack_b linked lists in-place
and increments the opp_counter variable by 1.

*/
void	rr(t_node **stack_a, t_node **stack_b, int *opp_counter)
{
	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	(*opp_counter)++;
	ft_printf("rr\n");
}
