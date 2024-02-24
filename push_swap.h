/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmolnya <asmolnya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:44:07 by asmolnya          #+#    #+#             */
/*   Updated: 2024/02/21 14:49:12 by asmolnya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	long int		value;
	struct s_stack	*next_node;
	struct s_stack	*prev_node;
	struct s_stack	*target_node;
	int				current_position;
	int				push_price;
	int				above_middle;
	int				cheapest;
}					t_stack;

void				make_stack(t_stack **a, int argc, char **argv);
int					push_swap(int argc, char **argv);
int					check_arg(int argc, char **args);
int					args_valid(int *argc, char **argv, char ***args);
int					count_lenght(char **args);
void				make_node(t_stack **l, long n);
t_stack				*find_last_node(t_stack *l);
void				*copy_args(int argc, char **argv, char ***args);
int					check_stack(t_stack *a);
void				clean(t_stack **a, t_stack **b, char **args);
void				clean_stack(t_stack **a);
int					check_int(t_stack *check);
int					check_elem(t_stack **ptr, t_stack **check);
void				new_node(t_stack **to, t_stack **from);
int					check_each(int argc, char **args);

// functions

void				swap_top(t_stack **a);
void				print_stack(t_stack *a);
void				ss(t_stack **a, t_stack **b);
int					count_stack(t_stack *a);
void				push_top(t_stack **to, t_stack **from);
void				rotate(t_stack **a);
void				rr(t_stack **a, t_stack **b);
void				rev_rotate(t_stack **a);
void				rrr(t_stack **a, t_stack **b);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rrb(t_stack **b);
void				rra(t_stack **a);

// sorting

void				sorting(t_stack **a, t_stack **b);
void				mini_sort(t_stack **a);
void				make_a_three(t_stack **a, t_stack **b);
void				find_target(t_stack *a, t_stack *b);
// void	find_target(t_stack **a, t_stack **b);
void				set_position(t_stack **a, t_stack **b);
void				set_price(t_stack **a, t_stack **b);
void				set_middle(t_stack **stack);
void				set_cheapest(t_stack **b);
t_stack				*find_first(t_stack **stack);
void				prepare_stacks(t_stack **a, t_stack **b);
void				move_node(t_stack **a, t_stack **b);
t_stack				*find_cheapest(t_stack *b);
void				move_above(t_stack **a, t_stack **b, t_stack *cheapest);
void				move_dif(t_stack **a, t_stack **b, t_stack *cheapest);
void				move_below(t_stack **a, t_stack **b, t_stack *cheapest);
void				final_rotate(t_stack **a);
int					sort_stack(t_stack **a);

t_stack				*find_max(t_stack *a);
t_stack				*find_smallest(t_stack *stack);

#endif
