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
	if (*arg == '-')
	{
		arg++;
		if (*arg == '\0')
			return (0);
		if (*arg == '0' && *(arg + 1) != '\0')
			return (0);
		if (*arg == '0' && *(arg + 1) == '\0')
			return (0);
	}
	if (*arg == '0' && *(arg + 1) != '\0')
		return (0);
	while (*arg)
	{
		if (*arg < '0' || *arg > '9')
			return (0);
		arg++;
	}
	return (1);
}

int	arg_is_zero(const char *arg)
{
	while (*arg == '0')
		arg++;
	return (*arg == '\0');
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

int	handle_argument(char *arg, int *nb_zeros)
{
	char	*token;

	if (is_empty_or_whitespace(arg))
		return (0);
	if (ft_strchr(arg, ' '))
	{
		token = ft_strtok(arg, " ");
		while (token)
		{
			if (!arg_is_number(token))
				return (0);
			*nb_zeros += arg_is_zero(token);
			token = ft_strtok(NULL, " ");
		}
	}
	else
	{
		if (!arg_is_number(arg))
			return (0);
		*nb_zeros += arg_is_zero(arg);
	}
	return (1);
}

int	is_correct_input(char **av)
{
	int	i;
	int	nb_zeros;

	i = 0;
	nb_zeros = 0;
	while (av[i])
	{
		if (!handle_argument(av[i], &nb_zeros))
			return (0);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (have_duplicates(av))
		return (0);
	if (i == 0)
		return (0);
	return (1);
}
