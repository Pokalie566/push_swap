/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:36:56 by adeboose          #+#    #+#             */
/*   Updated: 2024/10/22 15:37:02 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*next_token;
	char		*start;

	if (str)
		next_token = str;
	if (!next_token)
		return (NULL);
	while (*next_token && ft_strchr(delim, *next_token))
		next_token++;
	if (!*next_token)
		return (NULL);
	start = next_token;
	while (*next_token && !ft_strchr(delim, *next_token))
		next_token++;
	if (*next_token)
		*next_token++ = '\0';
	return (start);
}

int	is_empty_or_whitespace(const char *arg)
{
	while (*arg)
	{
		if (*arg != ' ')
			return (0);
		arg++;
	}
	return (1);
}
