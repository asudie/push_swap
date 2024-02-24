/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmolnya <asmolnya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:37:04 by asmolnya          #+#    #+#             */
/*   Updated: 2024/02/19 21:40:11 by asmolnya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack **a, t_stack **b)
{
	t_stack	*top_a;
	t_stack	*top_b;
	int		i;

	top_a = find_last_node(*a);
	top_b = find_last_node(*b);
	i = 0;
	while (top_a != NULL)
	{
		top_a->current_position = i;
		top_a = top_a->prev_node;
		i++;
	}
	i = 0;
	while (top_b != NULL)
	{
		top_b->current_position = i;
		top_b = top_b->prev_node;
		i++;
	}
}

void	set_price(t_stack **a, t_stack **b)
{
	set_middle(a);
	set_middle(b);
}

void	set_middle(t_stack **stack)
{
	int		size;
	int		i;
	t_stack	*ptr;

	ptr = *stack;
	size = count_stack(*stack);
	i = 0;
	while (i <= size / 2)
	{
		ptr->push_price = i;
		i++;
		ptr->above_middle = 0;
		ptr = ptr->next_node;
	}
	i--;
	if (size % 2 == 0)
		i--;
	while (i > 0)
	{
		ptr->push_price = i;
		i--;
		ptr->above_middle = 1;
		ptr = ptr->next_node;
	}
}

void	set_cheapest(t_stack **b)
{
	t_stack	*ptr_b;
	t_stack	*temp_cheap;

	ptr_b = *b;
	temp_cheap = *b;
	while (ptr_b != NULL)
	{
		if (ptr_b->push_price
			+ ptr_b->target_node->push_price < temp_cheap->push_price
			+ temp_cheap->target_node->push_price)
			temp_cheap = ptr_b;
		ptr_b = ptr_b->next_node;
	}
	temp_cheap->cheapest = 1;
}

void	prepare_stacks(t_stack **a, t_stack **b)
{
	find_target(*a, *b);
	set_position(a, b);
	set_price(a, b);
	set_cheapest(b);
}
