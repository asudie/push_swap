/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmolnya <asmolnya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:44:33 by asmolnya          #+#    #+#             */
/*   Updated: 2024/02/21 14:52:59 by asmolnya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = NULL;
	b = NULL;
	args = NULL;
	if (args_valid(&argc, argv, &args))
	{
		make_stack(&a, argc, args);
		if (!check_stack(a))
		{
			sorting(&a, &b);
		}
	}
	clean(&a, &b, args);
	return (0);
}

int	check_stack(t_stack *a)
{
	t_stack	*ptr;
	t_stack	*check;

	ptr = NULL;
	check = a;
	while (check != NULL)
	{
		if (check_int(check))
			return (1);
		ptr = a;
		if (!check_elem(&ptr, &check))
			check = check->next_node;
		else
			return (1);
	}
	return (0);
}

int	args_valid(int *argc, char **argv, char ***args)
{
	if (*argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else if (*argc == 2)
	{
		*args = ft_split(argv[1], ' ');
		*argc = count_lenght(*args);
	}
	else
	{
		copy_args(*argc, argv, args);
		(*argc) -= 1;
	}
	if (check_arg(*argc, *args))
		return (1);
	return (0);
}

void	make_stack(t_stack **a, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		make_node(a, ft_atol(argv[i]));
		i++;
	}
}

int	check_arg(int argc, char **args)
{
	if (argc > 0)
	{
		if (check_each(argc, args))
			return (1);
	}
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (0);
}
