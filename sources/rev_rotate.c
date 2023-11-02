/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:57:03 by tday              #+#    #+#             */
/*   Updated: 2023/11/01 15:40:57 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

void	rev_rotate(t_node **stack_x);

Summary
The rev_rotate function is used to reverse rotate a doubly linked list. It moves
the node ate the tail of the doubly linked list to the head. It takes a pointer
to the head of the list as input and modifies the list in-place.

Inputs
stack_x: A pointer to a pointer to the head of the doubly linked list.

Flow
1. Check if the input stack_x is NULL or if the list is empty (*stack_x == NULL).
If either condition is true, return without making any changes to the list.
2. Set a temporary node temp_node to point to the head of the list (*stack_x).
3. Set the index of the previous node of temp_node to 0, indicating that it is no
longer the last node in the list.
4. Set the index of temp_node to 1, indicating that it is now the last node in
the list.
5. Move temp_node to the next node in the list.
6. Repeat steps 4 and 5 until temp_node reaches the node with index 0, which is
the original head of the list.
7. Update the head of the list (*stack_x) to point to the previous node of the
original head, effectively reversing the order of the list.

Outputs
None. The function modifies the list in-place.

*/
void	rev_rotate(t_node **stack_x)
{
	t_node	*temp_node;

	if (stack_x == NULL || *stack_x == NULL)
		return ;
	temp_node = *stack_x;
	temp_node->prev->index = 0;
	temp_node->index = 1;
	temp_node = temp_node->next;
	while (temp_node->index != 0)
	{
		temp_node->index += 1;
		temp_node = temp_node->next;
	}
	*stack_x = (*stack_x)->prev;
}

/*

void	rra(t_node **stack_a, t_node **stack_b, int *opp_counter);

Summary
The rra function is used to reverse rotate a doubly linked list called stack_a.
It checks if stack_a is empty and returns if it is. Otherwise, it calls the
rev_rotate function to perform the reverse rotation on stack_a. It then
increments the opp_counter variable by 1 and prints "rra" using the ft_printf
function.

Inputs
stack_a: A pointer to a pointer to the head of the doubly linked list stack_a.
stack_b: A pointer to a pointer to the head of the doubly linked list stack_b.
opp_counter: A pointer to an integer variable that keeps track of the number
of operations performed.

Flow
1. Check if stack_a is empty. If it is, return without making any changes.
2. Call the rev_rotate function to reverse rotate stack_a.
3. Increment the opp_counter by 1.
4. Print "rra" using the ft_printf function.

Outputs
None. The function only performs the reverse rotation on stack_a and prints
"rra".

*/
void	rra(t_node **stack_a, t_node **stack_b, int *opp_counter)
{
	(void)stack_b;
	if (*stack_a == NULL)
		return ;
	rev_rotate(stack_a);
	(*opp_counter)++;
	ft_printf("rra\n");
}

/*

void	rrb(t_node **stack_a, t_node **stack_b, int *opp_counter);

Summary
The rrb function is used to reverse rotate a doubly linked list called stack_b.
It checks if stack_b is empty and returns if it is. Otherwise, it calls the
rev_rotate function to perform the reverse rotation on stack_b. It then
increments the opp_counter variable by 1 and prints "rrb" using the ft_printf
function.

Inputs
stack_a: A pointer to a pointer to the head of the doubly linked list stack_a.
stack_b: A pointer to a pointer to the head of the doubly linked list stack_b.
opp_counter: A pointer to an integer variable that keeps track of the number
of operations performed.

Flow
1. Check if stack_b is empty. If it is, return without making any changes.
2. Call the rev_rotate function to reverse rotate stack_b.
3. Increment the opp_counter by 1.
4. Print "rrb" using the ft_printf function.

Outputs
None. The function only performs the reverse rotation on stack_b and prints
"rrb".

*/
void	rrb(t_node **stack_a, t_node **stack_b, int *opp_counter)
{
	(void)stack_a;
	if (*stack_b == NULL)
		return ;
	rev_rotate(stack_b);
	(*opp_counter)++;
	ft_printf("rrb\n");
}

/*

void	rrr(t_node **stack_a, t_node **stack_b, int *opp_counter);

Summary
The rrr function is used to perform a reverse rotation on two doubly linked
lists, stack_a and stack_b. It checks if either of the lists is empty and
returns if they are. Otherwise, it calls the rev_rotate function to perform
the reverse rotation on both lists. It then increments the opp_counter
variable by 1 and prints "rrr" using the ft_printf function.

Inputs
stack_a: A pointer to a pointer to the head of the doubly linked list stack_a.
stack_b: A pointer to a pointer to the head of the doubly linked list stack_b.
opp_counter: A pointer to an integer variable that keeps track of the number
of operations performed.

Flow
1. Check if either stack_a or stack_b is empty. If either of them is empty,
return without making any changes.
2. Call the rev_rotate function to perform the reverse rotation on stack_a.
3. Call the rev_rotate function to perform the reverse rotation on stack_b.
4. Increment the opp_counter by 1.
5. Print "rrr" using the ft_printf function.

Outputs
None. The function only performs the reverse rotation on stack_a and stack_b
and prints "rrr".

*/
void	rrr(t_node **stack_a, t_node **stack_b, int *opp_counter)
{
	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	(*opp_counter)++;
	ft_printf("rrr\n");
}
