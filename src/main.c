/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:14:49 by adeboose          #+#    #+#             */
/*   Updated: 2024/11/15 15:14:51 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*merge_args(int ac, char **av)
{
	int		total_length;
	int		i;
	char	*merged_str;

	i = 1;
	total_length = 0;
	while (i < ac)
	{
		if (ft_strlen(av[i]) == 0 || is_empty_or_whitespace(av[i]))
			exit_error(NULL, NULL);
		i++;
	}
	i = 1;
	while (i < ac)
		total_length += ft_strlen(av[i++]) + 1;
	merged_str = malloc(total_length * sizeof(char));
	if (!merged_str)
		exit(1);
	ft_strcpy(merged_str, av[1]);
	i = 2;
	while (i < ac)
	{
		ft_strcat(merged_str, " ");
		ft_strcat(merged_str, av[i++]);
	}
	return (merged_str);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

static void	free_resources(t_stack *stack_a, t_stack *stack_b
			, char **split_args)
{
	int	i;

	i = 0;
	free_stack(&stack_a);
	free_stack(&stack_b);
	while (split_args[i])
		free(split_args[i++]);
	free(split_args);
}

static char	**parse_args(int ac, char **av)
{
	char	*merged_str;
	char	**split_args;

	merged_str = merge_args(ac, av);
	split_args = ft_split(merged_str, ' ');
	free(merged_str);
	if (!is_correct_input(split_args))
	{
		ft_free_table(split_args);
		exit_error(NULL, NULL);
	}
	return (split_args);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split_args;
	int		stack_size;

	if (ac < 2)
		return (0);
	split_args = parse_args(ac, av);
	stack_a = fill_stack_values(split_args);
	if(check_duplicate(stack_a))
	{
		ft_free_table(split_args);
		exit_error(&stack_a, NULL);
	}
	stack_size = get_stack_size(stack_a);
	stack_b = NULL;
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_resources(stack_a, stack_b, split_args);
	return (0);
}
