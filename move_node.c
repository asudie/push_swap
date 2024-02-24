/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmolnya <asmolnya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:52:00 by asmolnya          #+#    #+#             */
/*   Updated: 2024/02/19 21:40:41 by asmolnya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_node(t_stack **a, t_stack **b)
{
	int		count;
	t_stack	*cheapest;

	count = count_stack(*b);
	if (count == 0)
	{
		*b = NULL;
		return ;
	}
	cheapest = find_cheapest(*b);
	if (cheapest->above_middle && cheapest->target_node->above_middle)
		move_above(a, b, cheapest);
	else if (!cheapest->above_middle && !cheapest->target_node->above_middle)
		move_below(a, b, cheapest);
	else
		move_dif(a, b, cheapest);
	pa(a, b);
	if (*b != NULL)
		(*b)->prev_node = NULL;
	if (count == 1)
		*b = NULL;
}

void	move_below(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest->target_node->prev_node != NULL
		&& cheapest->prev_node != NULL)
	{
		rr(a, b);
	}
	while (cheapest->target_node->prev_node != NULL)
	{
		ra(a);
	}
	while (cheapest->prev_node != NULL)
	{
		rb(b);
	}
}

void	move_above(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest->target_node->prev_node != NULL
		&& cheapest->prev_node != NULL)
	{
		rrr(a, b);
	}
	while (cheapest->target_node->prev_node != NULL)
	{
		rra(a);
	}
	while (cheapest->prev_node != NULL)
	{
		rrb(b);
	}
}

void	move_dif(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (cheapest->target_node->above_middle)
	{
		while (cheapest->target_node->prev_node != NULL)
			rra(a);
	}
	else
	{
		while (cheapest->target_node->prev_node != NULL)
			ra(a);
	}
	if (cheapest->above_middle)
	{
		while (cheapest->prev_node != NULL)
			rrb(b);
	}
	else
	{
		while (cheapest->prev_node != NULL)
			rb(b);
	}
}
