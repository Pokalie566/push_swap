/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <adeboose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:48:02 by adeboose          #+#    #+#             */
/*   Updated: 2024/10/22 15:19:43 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_is_number(const char *arg)
{
	if (*arg == '-' || *arg == '+')
	{
		arg++;
		if (*arg == '\0')
			return (0);
	}
	while (*arg)
	{
		if (*arg < '0' || *arg > '9')
			return (0);
		arg++;
	}
	return (1);
}

int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	handle_argument(char *arg)
{

	if (is_empty_or_whitespace(arg))
		return (0);
	if (!arg_is_number(arg))
		return (0);
	return (1);
}

int	is_correct_input(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!handle_argument(av[i]))
			return (0);
		i++;
	}
	if (have_duplicates(av))
		return (0);
	if (i == 0)
		return (0);
	return (1);
}

int	check_duplicate(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;

	current = stack;
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			if (current->value == compare->value)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}
