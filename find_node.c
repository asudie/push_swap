/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmolnya <asmolnya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:39:10 by asmolnya          #+#    #+#             */
/*   Updated: 2024/02/21 14:53:35 by asmolnya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_smallest(t_stack *stack)
{
	long	smallest;
	t_stack	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next_node;
	}
	return (smallest_node);
}

void	find_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next_node;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next_node;
	}
}

int	check_int(t_stack *check)
{
	if (check->value > INT32_MAX || check->value < INT32_MIN)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	check_elem(t_stack **ptr, t_stack **check)
{
	while (*ptr != NULL)
	{
		if ((*check) == (*ptr))
		{
			*ptr = (*ptr)->next_node;
			continue ;
		}
		if ((*check)->value == (*ptr)->value)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		(*ptr) = (*ptr)->next_node;
	}
	return (0);
}

int	check_each(int argc, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if ((((j == 0 && (args[i][j] == '-')
						&& (ft_isdigit(args[i][j + 1]) == 1))
				|| (ft_isdigit(args[i][j]) == 1)) || (j != 0
				&& ft_isdigit(args[i][j]) == 1)))
			{
				j++;
			}
			else
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
