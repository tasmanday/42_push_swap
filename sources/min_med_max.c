/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_med_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:40:04 by tday              #+#    #+#             */
/*   Updated: 2023/11/01 17:11:50 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

t_node	*min_rank(t_node *current, int i);

Summary
The min_rank function is used to find the node with the minimum rank in a
linked list of nodes. It takes a pointer to the current node and an integer i
as inputs.

Inputs
current: a pointer to the current node in the linked list
i: an integer representing an offset value

Flow
1. et the min pointer to the current node.
2. Move the current pointer to the next node.
3. Iterate through the linked list until the index of the current node is 0.
4. If the rank of the current node is less than the rank of the min node, update
the min pointer to point to the current node.
5. Move the current pointer to the next node.
6. If i is greater than 0, call the next_min_rank function with the min node and
i as inputs and return its result.
7. Otherwise, return the min node.

Outputs
Returns a pointer to the node with the minimum rank in the linked list.

*/
t_node	*min_rank(t_node *current, int i)
{
	t_node	*min;

	min = current;
	current = current->next;
	while (current->index != 0)
	{
		if (current->rank < min->rank)
			min = current;
		current = current->next;
	}
	if (i > 0)
		return (next_min_rank(min, i));
	else
		return (min);
}

/*

t_node	*next_min_rank(t_node *min, int i);

Summary
The next_min_rank function is used to find the node with the ith next minimum 
rank in a linked list of nodes. It takes a pointer to the current minimum node
and an integer i as inputs.

Inputs
min: a pointer to the current minimum node in the linked list
i: an integer representing an offset value

Flow
1. Create a temporary node temp_node with the maximum possible rank value.
2. Initialize a temporary minimum node pointer temp_min to point to temp_node.
3. Set the current pointer to the next node after the current minimum node.
4. Iterate through the linked list until the current node is equal to the min 
node.
5. If the rank of the current node is less than the rank of the temp_min node and
greater than the rank of the min node, update the temp_min pointer to point to
the
current node.
6. Move the current pointer to the next node.
7. Repeat steps 4-6 i times.
8. Update the min pointer to point to the temp_min node.
9. Return the min node.

Outputs
Returns a pointer to the node who's rank is 'i' nodes above the node with the
minimum rank in the linked list.

*/
t_node	*next_min_rank(t_node *min, int i)
{
	t_node	temp_node;
	t_node	*temp_min;
	t_node	*current;

	temp_node.rank = INT_MAX;
	while (i > 0)
	{
		current = min->next;
		temp_min = &temp_node;
		while (current != min)
		{
			if (current->rank < temp_min->rank && current->rank > min->rank)
				temp_min = current;
			current = current->next;
		}
		min = temp_min;
		i--;
	}
	return (min);
}

/*

t_node	*max_rank(t_node *current, int i);

Summary
The max_rank function is used to find the node with the maximum rank in a linked
list of nodes. It takes a pointer to the current node and an integer i as inputs.

Inputs
current: a pointer to the current node in the linked list
i: an integer representing an offset value

Flow
1. Set the max pointer to the current node.
2. Move the current pointer to the next node.
3. Iterate through the linked list until the index of the current node is 0.
4. If the rank of the current node is greater than the rank of the max node,
update the max pointer to point to the current node.
5. Move the current pointer to the next node.
6. If i is greater than 0, call the next_max_rank function with the max node and
i as inputs and return its result.
7. Otherwise, return the max node.

Outputs
Returns a pointer to the node with the maximum rank in the linked list.

*/
t_node	*max_rank(t_node *current, int i)
{
	t_node	*max;

	max = current;
	current = current->next;
	while (current->index != 0)
	{
		if (current->rank > max->rank)
			max = current;
		current = current->next;
	}
	if (i > 0)
		return (next_max_rank(max, i));
	else
		return (max);
}

/*

t_node	*next_max_rank(t_node *max, int i);

Summary
The next_max_rank function is used to find the node with the ith next maximum
rank in a linked list of nodes. It takes a pointer to the current maximum node
and an integer i as inputs.

Inputs
max: a pointer to the current maximum node in the linked list
i: an integer representing an offset value

Flow
1. Create a temporary node temp_node with the minimum possible rank value.
2. Initialize a temporary maximum node pointer temp_max to point to temp_node.
3. Set the current pointer to the next node after the current maximum node.
4. Iterate through the linked list until the current node is equal to the max
node.
5. If the rank of the current node is greater than the rank of the temp_max
node and less than the rank of the max node, update the temp_max pointer to
point to the current node.
6. Move the current pointer to the next node.
7. Repeat steps 4-6 i times.
8. Update the max pointer to point to the temp_max node.
9. Return the max node.

Outputs
Returns a pointer to the node whose rank is i nodes above the node with the
maximum rank in the linked list.

*/
t_node	*next_max_rank(t_node *max, int i)
{
	t_node	temp_node;
	t_node	*temp_max;
	t_node	*current;

	temp_node.rank = INT_MIN;
	while (i > 0)
	{
		current = max->next;
		temp_max = &temp_node;
		while (current != max)
		{
			if (current->rank > temp_max->rank && current->rank < max->rank)
				temp_max = current;
			current = current->next;
		}
		max = temp_max;
		i--;
	}
	return (max);
}

/*

t_node	*median_rank(t_node *current, int i);

Summary
The median_rank function is used to find the node with the median rank in a
linked list of nodes. It takes a pointer to the current node and an integer
i as inputs.

Inputs
current: a pointer to the current node in the linked list
i: an integer representing an offset value

Flow
1. Set the median pointer to the current node.
2. Calculate the mid value by dividing the index of the previous node by 2 and
adding i.
3. Call the min_rank function with current and mid as inputs, and assign the
result to median.
4. Return the median node.

Outputs
Returns a pointer to the node with the median rank in the linked list.

*/
t_node	*median_rank(t_node *current, int i)
{
	t_node	*median;
	int		mid;

	median = current;
	mid = current->prev->index / 2 + i;
	median = min_rank(current, mid);
	return (median);
}
