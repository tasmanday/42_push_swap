/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:16:35 by tday              #+#    #+#             */
/*   Updated: 2023/11/01 16:13:47 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

void	push_swap_a_to_b(t_node **stack_a, t_node **stack_b, int *op_counter);

Summary
This code snippet defines the push_swap_a_to_b function, which takes two stacks
(stack_a and stack_b) and an operation counter (op_counter) as input. The
function performs a series of operations on the stacks to move elements from
stack A to stack B, while keeping the elements in both stacks sorted in
ascending order.

Inputs
stack_a: a pointer to the top of stack A
stack_b: a pointer to the top of stack B
op_counter: a pointer to an integer variable to keep track of the number of
operations performed

Flow
1. The function calls the pb function to push the top element from stack_a to
stack_b, and updates the operation counter.
2. It then checks if the rank of the top element in stack_b is less than the
rank of the next element in stack_b.
3. If the condition is true, it checks if the rank of the top element in
stack_a is greater than the rank of the next element in stack_a.
4. If the condition is true, it calls the ss function to swap the top elements
of both stacks and updates the operation counter.
5. If the condition is false, it calls the sb function to swap the top elements
of stack_b and updates the operation counter.

Outputs
The elements from stack_a are moved to stack_b while keeping both stacks sorted.
The operation counter is updated to reflect the number of operations performed.

*/
void	push_swap_a_to_b(t_node **stack_a, t_node **stack_b, int *op_counter)
{
	pb(stack_a, stack_b, op_counter);
	if ((*stack_b)->rank < (*stack_b)->next->rank)
	{
		if (*stack_b != NULL && ((*stack_a)->rank > (*stack_a)->next->rank))
			ss(stack_a, stack_b, op_counter);
		else
			sb(stack_a, stack_b, op_counter);
	}
}

/*

void	push_swap_b_to_a(t_node **stack_a, t_node **stack_b, int *op_counter);

Summary
This code snippet defines the push_swap_b_to_a function, which takes two stacks
(stack_a and stack_b) and an operation counter (op_counter) as input.
The function performs a series of operations on the stacks to move elements
from stack B to stack A, while keeping the elements in both stacks sorted in
ascending order.

Inputs
stack_a: a pointer to the top of stack A
stack_b: a pointer to the top of stack B
op_counter: a pointer to an integer variable to keep track of the number of
operations performed

Flow
1. The function calls the pa function to push the top element from stack_b to
stack_a, and updates the operation counter.
2. It then checks if the rank of the top element in stack_a is greater than the
rank of the next element in stack_a.
3. If the condition is true, it checks if stack_b is not empty and if the rank
of the top element in stack_b is less than the rank of the next element in
stack_b.
4. If the condition is true, it calls the ss function to swap the top elements
of both stacks and updates the operation counter.
5. If the condition is false, it calls the sa function to swap the top elements
of stack_a and updates the operation counter.

Outputs
The elements from stack_b are moved to stack_a while keeping both stacks sorted.
The operation counter is updated to reflect the number of operations performed.

*/
void	push_swap_b_to_a(t_node **stack_a, t_node **stack_b, int *op_counter)
{
	pa(stack_a, stack_b, op_counter);
	if ((*stack_a)->rank > (*stack_a)->next->rank)
	{
		if (*stack_b != NULL && ((*stack_b)->rank < (*stack_b)->next->rank))
			ss(stack_a, stack_b, op_counter);
		else
			sa(stack_a, stack_b, op_counter);
	}
}
