/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmolnya <asmolnya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:58:39 by asmolnya          #+#    #+#             */
/*   Updated: 2024/02/19 19:26:22 by asmolnya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_stack(t_stack **a)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	while (*a)
	{
		temp = (*a)->next_node;
		free(*a);
		(*a) = temp;
	}
	*a = NULL;
}

void	*copy_args(int argc, char **argv, char ***args)
{
	int	i;

	*args = (char **)malloc((argc) * sizeof(char *));
	if (!args)
		return (NULL);
	i = 0;
	while ((i + 1) < argc)
	{
		(*args)[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	(*args)[i] = 0;
	return (args);
}

int	count_lenght(char **args)
{
	int	i;

	i = 0;
	while (args[i] != 0)
		i++;
	return (i);
}

t_stack	*find_last_node(t_stack *l)
{
	if (l == NULL)
		return (NULL);
	while (l->next_node)
	{
		l = l->next_node;
	}
	return (l);
}

void	make_node(t_stack **l, long n)
{
	t_stack	*new_node;
	t_stack	*last_node;

	last_node = find_last_node(*l);
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*l = new_node;
	else
		last_node->next_node = new_node;
	new_node->next_node = NULL;
	new_node->prev_node = last_node;
	new_node->value = n;
}
