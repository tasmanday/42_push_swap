/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:34:07 by tday              #+#    #+#             */
/*   Updated: 2023/11/01 23:15:29 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"
#include <stdio.h>

/*

void	make_circle(t_node *head, t_node *tail);

Summary
The make_circle function creates a circular doubly linked list by connecting
the head and tail nodes.

Code Analysis

Inputs
head (t_node*): a pointer to the head node of the list
tail (t_node*): a pointer to the tail node of the list

Flow
1. Check if both head and tail are not NULL.
2. If they are not NULL, set the next pointer of the tail node to the head node.
3. Set the prev pointer of the head node to the tail node.

Outputs
None. The function modifies the next and prev pointers of the head and tail
nodes to create a circular doubly linked list.

*/
void	make_circle(t_node *head, t_node *tail)
{
	if (head != NULL && tail != NULL && head->prev != tail && tail->next \
	!= head)
	{
		tail->next = head;
		head->prev = tail;
	}
}

/*

t_node	*create_new_node(char *arg, int index);

Summary
The create_new_node function is responsible for creating a new node for a doubly
linked list. It allocates memory for the new node, initializes its attributes,
and returns a pointer to the newly created node.

Code Analysis

Inputs
arg (char*): The value to be stored in the new node.
index (int): The index of the new node.

Flow
1. Allocate memory for a new node using malloc.
2. If the memory allocation is successful, assign the value of arg to the value
attribute of the new node.
3. Set the rank attribute of the new node to 0.
4. Set the index attribute of the new node to the provided index.
5. Set the next and prev attributes of the new node to NULL.
6. Return a pointer to the newly created node.

Outputs
current (t_node*): A pointer to the newly created node.

*/
t_node	*create_new_node(char *arg, int index)
{
	t_node	*current;

	current = malloc(sizeof(t_node));
	if (current == NULL)
		return (NULL);
	current->value = ft_atolong(arg);
	current->rank = 0;
	current->index = index;
	current->next = NULL;
	current->prev = NULL;
	return (current);
}

/*
t_node	*fill_stack_a(int argc, char*argv[]);

Summary
The fill_stack_a function is responsible for creating and filling a stack with
nodes based on the command line arguments passed to the program. It creates a
new node for each argument, assigns the value and index to the node, and connects
the nodes in a circular doubly linked list.

Code Analysis

Inputs
argc (int): The number of command line arguments.
argv (char*[]): An array of strings representing the command line arguments.

Flow
1. Initialize variables stack_a, current, last, and i.
2. Iterate over the command line arguments starting from index 1.
3. Create a new node using the create_new_node function, passing the argument and
the index.
4. Set the prev attribute of the new node to the last node.
5. If last is not NULL, set the next attribute of last to the new node.
Otherwise, set stack_a to the new node.
6. Update last to the new node.
7. Increment i.
8. Make the stack circular by calling the make_circle function, passing stack_a
and last.
9. Return stack_a.

Outputs
stack_a (t_node*): A pointer to the head node of the created stack.

*/
t_node	*fill_stack_a(int argc, char*argv[])
{
	t_node	*stack_a;
	t_node	*current;
	t_node	*last;
	int		i;

	i = 1;
	stack_a = NULL;
	last = NULL;
	while (i < argc)
	{
		current = create_new_node(argv[i], i - 1);
		if (current == NULL)
			return (NULL);
		current->prev = last;
		if (last != NULL)
			last->next = current;
		else
			stack_a = current;
		last = current;
		i++;
	}
	make_circle(stack_a, last);
	return (stack_a);
}

/*

t_node	*find_next_min_node(t_node *current);

Summary
The find_next_min_node function is responsible for finding the next minimum node
in a circular doubly linked list. It iterates through the list, starting from the
current node, and checks each node's rank and value. If a node has a rank of 0
and a value lower than the current minimum, it is considered the new minimum
node.
The function returns a pointer to the node with the minimum value.

Code Analysis

Inputs
current (t_node*): A pointer to the current node in the list.

Flow
1. Initialize variables min to the maximum integer value and first_flag to 1.
2. Initialize min_node to NULL.
3. Enter a loop that continues until the first_flag is true or the current node's
index is 0.
4. Check if the current node's rank is 0 and its value is lower than the current
minimum.
5. If the condition is true, update the minimum value and set min_node to the
current node.
6. Move to the next node in the list.
7. Set first_flag to 0 to indicate that the loop has executed at least once.
8. Exit the loop.
9. Return min_node, which points to the node with the minimum value.

Outputs
min_node (t_node*): A pointer to the node with the minimum value.

*/
t_node	*find_next_min_node(t_node *current)
{
	long	min;
	int		first_flag;
	t_node	*min_node;

	min = INT_MAX;
	first_flag = 1;
	min_node = NULL;
	while (first_flag || current->index != 0)
	{
		if (current->rank == 0 && current->value < min)
		{
			min = current->value;
			min_node = current;
		}
		current = current->next;
		first_flag = 0;
	}
	return (min_node);
}

/*

void	assign_ranks(t_node *current);

Summary
The assign_ranks function is responsible for assigning ranks to the nodes in a
circular doubly linked list. It iterates through the list, starting from the
provided node, and finds the next minimum node based on its rank and value. The
function then assigns a rank to that node and continues the process until all
nodes have been assigned a rank.

Code Analysis

Inputs
current (t_node*): A pointer to the current node in the list.

Flow
1. Check if the current node is NULL. If it is, return.
2. Initialize the rank variable to 1.
3. Enter a loop that continues indefinitely.
4. Find the next minimum node in the list by calling the find_next_min_node
function, passing the current node.
5. If a minimum node is found, assign the current rank value to the rank
attribute of the minimum node and increment the rank variable.
6. If no minimum node is found, break out of the loop.
7. Repeat steps 4-6 until all nodes have been assigned a rank.

Outputs
None. The function modifies the rank attribute of the nodes in the circular
doubly linked list.

*/
void	assign_ranks(t_node *current)
{
	int		rank;
	t_node	*min_node;

	if (current == NULL)
		return ;
	rank = 1;
	while (1)
	{
		min_node = find_next_min_node(current);
		if (min_node != NULL)
		{
			min_node->rank = rank;
			rank++;
		}
		else
			break ;
	}
}
