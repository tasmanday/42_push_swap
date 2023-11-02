/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:21:13 by tday              #+#    #+#             */
/*   Updated: 2023/11/01 13:33:36 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

void	swap_list_over_2_nodes(t_node **stack_x, t_node	*swap_node);

Summary
This function swaps the first two nodes in a doubly linked list that contains
more than 2 nodes. It takes in a pointer to the head of the list (stack_x) and a
pointer to the node to be swapped (swap_node).

Code Analysis

Inputs
stack_x: a pointer to the head of the doubly linked list
swap_node: a pointer to the node to be swapped

Flow
1. Set the next pointer of swap_node to the next pointer of stack_x, effectively
inserting swap_node after stack_x.
2. Set the next pointer of stack_x to swap_node, making swap_node the new first
node in the list.
3. Set the prev pointer of stack_x to the prev pointer of swap_node, effectively
inserting stack_x before swap_node.
4. Set the prev pointer of swap_node to stack_x, making stack_x the new previous
node of swap_node.
5. If the prev pointer of stack_x is not NULL, update the next pointer of the
previous node to point to stack_x.
6. If the next pointer of swap_node is not NULL, update the prev pointer of the
next node to point to swap_node.

Outputs
None. The function modifies the doubly linked list by swapping the positions of
two nodes.

*/
void	swap_list_over_2_nodes(t_node **stack_x, t_node	*swap_node)
{
	if (stack_x == NULL || swap_node == NULL)
		return ;
	swap_node->next = (*stack_x)->next;
	(*stack_x)->next = swap_node;
	(*stack_x)->prev = swap_node->prev;
	swap_node->prev = *stack_x;
	if ((*stack_x)->prev != NULL)
		(*stack_x)->prev->next = *stack_x;
	if (swap_node->next != NULL)
		swap_node->next->prev = swap_node;
}

/*

void	swap(t_node **stack_x);

Summary
This function swaps the positions of the first two nodes in a doubly linked list.

Code Analysis

Inputs
stack_x: a pointer to the head of the doubly linked list

Flow
1. Check if stack_x or *stack_x is NULL. If either is NULL, return.
2. Set swap_node to the value of *stack_x.
3. Set *stack_x to the next node in the list.
4. If the previous node of swap_node has an index of 1, update the next and
previous pointers of *stack_x and swap_node to point to each other.
5. Otherwise, call the swap_list_over_2_nodes function to swap the positions of
*stack_x and swap_node.
6. Set the index of *stack_x to 0 and the index of swap_node to 1.

Outputs
None. The function modifies the doubly linked list by swapping the positions of
two nodes.

*/
void	swap(t_node **stack_x)
{
	t_node	*swap_node;

	if (stack_x == NULL || *stack_x == NULL)
		return ;
	swap_node = *stack_x;
	*stack_x = (*stack_x)->next;
	if (swap_node->prev->index == 1)
	{
		(*stack_x)->next = swap_node;
		(*stack_x)->prev = swap_node;
		swap_node->next = *stack_x;
		swap_node->prev = *stack_x;
	}
	else
	{
		swap_list_over_2_nodes(stack_x, swap_node);
	}
	(*stack_x)->index = 0;
	swap_node->index = 1;
}

/*

void	sa(t_node **stack_a, t_node **stack_b, int *opp_counter);

Summary
The sa function is used to swap the positions of the first two nodes in a doubly
linked list called stack_a. It also increments the opp_counter variable by 1 and
prints "sa" using the ft_printf function.

Code Analysis

Inputs
stack_a: a pointer to the head of the doubly linked list stack_a
stack_b: a pointer to the head of the doubly linked list stack_b
opp_counter: a pointer to an integer variable that keeps track of the number of
operations performed

Flow
1. Check if stack_a is NULL. If it is, return.
2. Call the swap function, passing stack_a as an argument, to swap the positions
of the first two nodes in stack_a.
3. Increment the value of opp_counter by 1.
4. Print "sa" using the ft_printf function.

Outputs
None. The function modifies the doubly linked list stack_a by swapping the
positions of the first two nodes.

*/
void	sa(t_node **stack_a, t_node **stack_b, int *opp_counter)
{
	(void)stack_b;
	if (*stack_a == NULL)
		return ;
	swap(stack_a);
	(*opp_counter)++;
	ft_printf("sa\n");
}

/*

void	sb(t_node **stack_a, t_node **stack_b, int *opp_counter);

Summary
The sb function swaps the positions of the first two nodes in a doubly linked
list called stack_b. It also increments the opp_counter variable by 1 and prints
"sb" using the ft_printf function.

Code Analysis

Inputs
stack_a: a pointer to the head of the doubly linked list stack_a
stack_b: a pointer to the head of the doubly linked list stack_b
opp_counter: a pointer to an integer variable that keeps track of the number of
operations performed

Flow
1. Check if stack_b is NULL. If it is, return.
2. Call the swap function, passing stack_b as an argument, to swap the positions
of the first two nodes in stack_b.
3. Increment the value of opp_counter by 1.
4. Print "sb" using the ft_printf function.

Outputs
None. The function modifies the doubly linked list stack_b by swapping the
positions of the first two nodes.

*/
void	sb(t_node **stack_a, t_node **stack_b, int *opp_counter)
{
	(void)stack_a;
	if (*stack_b == NULL)
		return ;
	swap(stack_b);
	(*opp_counter)++;
	ft_printf("sb\n");
}

/*

void	ss(t_node **stack_a, t_node **stack_b, int *opp_counter);

Summary
The ss function swaps the positions of the first two nodes in two doubly linked
lists, stack_a and stack_b. It also increments the opp_counter variable by 1 and
prints "ss" using the ft_printf function.

Code Analysis

Inputs
stack_a: a pointer to the head of the doubly linked list stack_a
stack_b: a pointer to the head of the doubly linked list stack_b
opp_counter: a pointer to an integer variable that keeps track of the number of
operations performed

Flow
1. Check if either stack_a or stack_b is NULL. If either is NULL, return.
2. Call the swap function, passing stack_a as an argument, to swap the positions
of the first two nodes in stack_a.
3. Call the swap function, passing stack_b as an argument, to swap the positions
of the first two nodes in stack_b.
4. Increment the value of opp_counter by 1.
5. Print "ss" using the ft_printf function.

Outputs
None. The function modifies the doubly linked lists stack_a and stack_b by
swapping the positions of the first two nodes.

*/
void	ss(t_node **stack_a, t_node **stack_b, int *opp_counter)
{
	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	swap(stack_a);
	swap(stack_b);
	(*opp_counter)++;
	ft_printf("ss\n");
}
