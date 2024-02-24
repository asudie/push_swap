/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmolnya <asmolnya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:49:32 by asmolnya          #+#    #+#             */
/*   Updated: 2024/02/19 21:50:13 by asmolnya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	swap_top(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap_top(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	if (count_stack(*b) > 0)
	{
		swap_top(a);
		swap_top(b);
		ft_printf("ss\n");
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push_top(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push_top(b, a);
	ft_printf("pb\n");
}
