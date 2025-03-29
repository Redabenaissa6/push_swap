/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:50:16 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/28 10:08:08 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	only_space(char **arv)
{
	int	i;
	int	j;

	i = 0;
	while (arv[i])
	{
		j = 0;
		if (arv[i][j] == ' ')
		{
			while (arv[i][j] == ' ')
				j++;
			if (!arv[i][j])
				return (1);
		}
		i++;
	}
	return (0);
}

int	only_zeros(char *number, int *i)
{
	(*i) = 0;
	if (number[(*i)] == '+' || number[(*i)] == '-')
		(*i)++;
	while (number[(*i)] == '0')
		(*i)++;
	if (!number[(*i)])
	{
		number[0] = '0';
		number[1] = '\0';
		return (1);
	}
	return (0);
}

static int	space_signe(const char *str, int *i, int *signe)
{
	while (str[*i] && (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13)))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*signe = -1;
		(*i)++;
	}
	while (str[*i] == '0')
		(*i)++;
	return (*i);
}

int	ft_atoiv(const char *str, int *flag)
{
	long long	result;
	int			signe;
	int			i;

	i = 0;
	signe = 1;
	result = 0;
	space_signe(str, &i, &signe);
	while ((str[i]) && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		if (result * signe < INT_MIN || result * signe > INT_MAX)
		{
			*flag = 1;
			return (0);
		}
		i++;
	}
	return ((int)result * signe);
}
