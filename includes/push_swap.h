/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:43:43 by tday              #+#    #+#             */
/*   Updated: 2023/11/02 14:09:22 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN	-2147483648
# define INT_MAX	2147483647

typedef struct s_node
{
	long			value;
	int				rank;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_pair
{
	struct s_node	*a;
	struct s_node	*b;
	struct s_node	*low;
	struct s_node	*high;
	struct s_node	*median;
}				t_pair;

/* function prototypes */

/* initialisation */

void	make_circle(t_node *head, t_node *tail);
t_node	*create_new_node(char *arg, int index);
t_node	*fill_stack_a(int argc, char*argv[]);
t_node	*find_next_min_node(t_node *current);
void	assign_ranks(t_node *current);

/* errors */

int		check_errors(int argc, char*argv[]);
int		check_non_numeric(const char *arg);
int		check_int_range(const char *arg);
int		check_duplicate(int i, int argc, char *argv[]);

/* swap */

void	swap_list_over_2_nodes(t_node **stack_x, t_node	*swap_node);
void	swap(t_node **stack_x);
void	sa(t_node **stack_a, t_node **stack_b, int *opp_counter);
void	sb(t_node **stack_a, t_node **stack_b, int *opp_counter);
void	ss(t_node **stack_a, t_node **stack_b, int *opp_counter);

/* push */

void	push(t_node **stack_x, t_node **stack_y);
t_node	*remove_node(t_node **stack_x);
void	add_node(t_node **stack_y, t_node *push_node);
void	pa(t_node **stack_a, t_node **stack_b, int *opp_counter);
void	pb(t_node **stack_a, t_node **stack_b, int *opp_counter);

/* rotate */

void	rotate(t_node **stack_x);
void	ra(t_node **stack_a, t_node **stack_b, int *opp_counter);
void	rb(t_node **stack_a, t_node **stack_b, int *opp_counter);
void	rr(t_node **stack_a, t_node **stack_b, int *opp_counter);

/* rev_rotate */

void	rev_rotate(t_node **stack_x);
void	rra(t_node **stack_a, t_node **stack_b, int *opp_counter);
void	rrb(t_node **stack_a, t_node **stack_b, int *opp_counter);
void	rrr(t_node **stack_a, t_node **stack_b, int *opp_counter);

/* push_swap */

void	push_swap_a_to_b(t_node **stack_a, t_node **stack_b, int *op_counter);
void	push_swap_b_to_a(t_node **stack_a, t_node **stack_b, int *op_counter);

/* min_med_max */

t_node	*min_rank(t_node *current, int i);
t_node	*next_min_rank(t_node *min, int i);
t_node	*max_rank(t_node *current, int i);
t_node	*next_max_rank(t_node *max, int i);
t_node	*median_rank(t_node *current, int i);

/* best */

int		atob_pair_and_min_ops(t_node *stack_a, t_node *stack_b, t_pair *pair);
t_pair	*best_a_to_b(t_node *stack_a, t_node *stack_b, t_pair *pair);
int		btoa_pair_and_min_ops(t_node *stack_a, t_node *stack_b, t_pair *pair);
t_pair	*best_b_to_a(t_node *stack_a, t_node *stack_b, t_pair *pair);
t_node	*okayest(t_node *stack_a, t_pair *pair);

/* move_pair_to_top */

void	move_pair_to_top(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter);
void	rotate_both_ra(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter);
void	rotate_both_rb(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter);
void	rev_rot_both_ra(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter);
void	rev_rot_both_rb(t_pair *pair, t_node **stack_a, t_node **stack_b, \
int *op_counter);

/* find_pos_and_move */

t_node	*find_pos_a_to_b(t_node *node, t_node *target_stack);
t_node	*find_pos_b_to_a(t_node *node, t_node *target_stack);
void	move_to_top_a(t_node *node, t_node **stack_a, t_node **stack_b, \
int *op_counter);
void	move_to_top_b(t_node *node, t_node **stack_a, t_node **stack_b, \
int *op_counter);

/* misc_utils */

int		stack_size(t_node *stack);
int		count_ops(t_node *node, t_node *stack_x);
int		is_sorted(t_node *stack_x);
void	free_null_stack(t_node **stack);

/* sort_1 */

void	sort(t_node **stack_a, t_node **stack_b, int *op_counter, t_pair *pair);
void	rotate_if_needed(t_node **stack_a, t_node **stack_b, int *op_counter);
void	sort_3(t_node **stack_a, t_node **stack_b, int *op_counter);
void	sort_small(t_node **stack_a, t_node **stack_b, int *op_counter);

/* sort_2 */

void	push_back_to_a(t_node **stack_a, t_node **stack_b, int *op_counter);
void	sort_medium(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair);
void	sort_large(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair);

/* alt_sort */

void	alt_sort(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair);
void	push_around_median(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair);
void	sort_alt_med(t_node **stack_a, t_node **stack_b, int *op_counter, \
t_pair *pair);

/* testing */
/* void	print_nodes(t_node *stack_a, t_node *stack_b); */

#endif