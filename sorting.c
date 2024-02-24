/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmolnya <asmolnya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:49:50 by asmolnya          #+#    #+#             */
/*   Updated: 2024/02/19 19:25:28 by asmolnya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack **a, t_stack **b)
{
	if (!sort_stack(a))
		return ;
	if (count_stack(*a) > 3)
		make_a_three(a, b);
	mini_sort(a);
	while (*b)
	{
		prepare_stacks(a, b);
		move_node(a, b);
	}
	final_rotate(a);
}

int	sort_stack(t_stack **a)
{
	t_stack	*head;

	head = (*a);
	while ((*a)->next_node != NULL)
	{
		if ((*a)->value > (*a)->next_node->value)
		{
			(*a) = head;
			return (1);
		}
		(*a) = (*a)->next_node;
	}
	(*a) = head;
	return (0);
}

void	final_rotate(t_stack **a)
{
	t_stack	*smallest;

	set_middle(a);
	if (sort_stack(a))
	{
		smallest = find_smallest(*a);
		if (smallest->above_middle)
		{
			while ((smallest)->prev_node != NULL)
				rra(a);
		}
		else
		{
			while ((smallest)->prev_node != NULL)
				ra(a);
		}
		*a = smallest;
	}
}

void	mini_sort(t_stack **a)
{
	t_stack	*top;

	top = *a;
	if (count_stack(*a) == 3)
	{
		if (top->value > top->next_node->value
			&& top->value > top->next_node->next_node->value)
			ra(a);
		else if (top->next_node->value > top->value
			&& top->next_node->value > top->next_node->next_node->value)
			rra(a);
		top = *a;
		if (top->value > top->next_node->value)
			sa(a);
	}
	else if (count_stack(*a) == 2)
	{
		if (top->value > top->next_node->value)
			sa(a);
	}
}

void	make_a_three(t_stack **a, t_stack **b)
{
	int	i;

	i = count_stack(*a);
	while (i > 3)
	{
		pb(a, b);
		i--;
	}
}
