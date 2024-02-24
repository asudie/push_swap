/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmolnya <asmolnya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:53:03 by asmolnya          #+#    #+#             */
/*   Updated: 2024/02/19 19:42:02 by asmolnya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_cheapest(t_stack *b)
{
	while (b->cheapest != 1)
		b = b->next_node;
	return (b);
}

t_stack	*find_first(t_stack **stack)
{
	while ((*stack)->prev_node != NULL)
		(*stack) = (*stack)->prev_node;
	return (*stack);
}

int	count_stack(t_stack *a)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		i++;
		a = a->next_node;
	}
	return (i);
}

void	print_stack(t_stack *a)
{
	t_stack	*head;

	head = a;
	while (a != NULL)
	{
		printf("value  = %ld\n", a->value);
		a = a->next_node;
	}
	a = head;
}

void	clean(t_stack **a, t_stack **b, char **args)
{
	int	i;

	clean_stack(a);
	clean_stack(b);
	if (args != NULL)
	{
		i = 0;
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}
