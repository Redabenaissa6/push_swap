/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:43:31 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/28 10:07:52 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	just_nums(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '+'
			&& str[i] != '-' && !ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	is_int(char *str)
{
	int	i;

	i = 0;
	if (just_nums(str))
		return (1);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] != ' ' && (!ft_isdigit(str[i])
				|| str[i] == '+' || str[i] == '-'))
		{
			if (!ft_isdigit(str[i]) && ((str[i] == '-'
						|| str[i] == '+') && (!ft_isdigit(str[i + 1])
						|| ft_isdigit(str[i - 1]))))
				return (1);
		}
		i++;
	}
	return (0);
}

char	**args(int arc, char **arv)
{
	int		i;
	char	*str;
	char	**splited;

	i = 1;
	if (only_space(arv))
		return (ft_putstr_fd("Error\n", 2), NULL);
	str = ft_strdup("");
	while (i < arc)
	{
		if (is_int(arv[i]) || !arv[i][0])
		{
			free(str);
			return (ft_putstr_fd("Error\n", 2), NULL);
		}
		str = ft_strjoin(str, arv[i]);
		if (i < arc - 1)
			str = ft_strjoin(str, " ");
		i++;
	}
	splited = ft_split(str, ' ');
	return (free(str), splited);
}

int	duplicate(t_stack *stack_a)
{
	t_stack	*i;
	t_stack	*j;

	i = stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}
