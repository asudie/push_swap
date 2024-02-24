/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmolnya <asmolnya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:55:30 by asmolnya          #+#    #+#             */
/*   Updated: 2024/02/20 13:42:24 by asmolnya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*top;
	t_stack	*first;

	if (*a != NULL)
	{
		top = find_last_node(*a);
		first = *a;
		top->next_node = first;
		first->prev_node = top;
		first->next_node->prev_node = NULL;
		*a = first->next_node;
		first->next_node = NULL;
	}
}

void	rev_rotate(t_stack **a)
{
	t_stack	*top;
	t_stack	*first;

	if (*a != NULL)
	{
		top = find_last_node(*a);
		first = *a;
		top->prev_node->next_node = NULL;
		top->prev_node = NULL;
		top->next_node = first;
		first->prev_node = top;
		*a = top;
	}
}

void	push_top(t_stack **to, t_stack **from)
{
	t_stack	*top_to;
	t_stack	*top_from;

	if (count_stack(*from) > 0)
	{
		top_to = *to;
		top_from = *from;
		if (top_to == NULL)
		{
			new_node(to, from);
		}
		else
		{
			top_to->prev_node = top_from;
			*from = top_from->next_node;
			if (*from != NULL)
				(*from)->prev_node = NULL;
			*to = top_from;
			top_from->prev_node = NULL;
			top_from->next_node = top_to;
		}
	}
}

void	new_node(t_stack **to, t_stack **from)
{
	t_stack	*top_to;
	t_stack	*top_from;

	top_to = *to;
	top_from = *from;
	*to = top_from;
	top_to = *to;
	top_from->next_node->prev_node = NULL;
	*from = top_from->next_node;
	top_to->next_node = NULL;
	top_to->prev_node = NULL;
}

void	swap_top(t_stack **a)
{
	t_stack	*top;
	t_stack	*next;
	t_stack	*nnext;

	if (count_stack(*a) > 1)
	{
		top = *a;
		next = top->next_node;
		if (count_stack(*a) == 2)
		{
			top->next_node = NULL;
			top->prev_node = next;
			next->next_node = top;
			next->prev_node = NULL;
			*a = next;
			return ;
		}
		nnext = next->next_node;
		top->next_node = nnext;
		top->prev_node = next;
		next->next_node = top;
		next->prev_node = NULL;
		nnext->prev_node = top;
		*a = next;
	}
}
