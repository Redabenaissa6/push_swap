/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:43:31 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/25 00:13:48 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  only_space(char **arv)
{
    int i;
    int j;

    i = 0;
    while(arv[i])
    {
        j = 0;
        if(arv[i][j] == ' ')
        {
            while(arv[i][j] == ' ')
                j++;
            if(!arv[i][j])
                return(1);
        }
        i++;
    }
    return (0);
}
static int just_nums(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if(str[i] != ' ' && str[i] != '+' && str[i] != '-' && !ft_isdigit(str[i]))
            return(1);
        i++;
    }
    return(0);
}
static int is_same(char *s1, char *s2)
{
    int i;

    i = 0;
    while(s1[i] || s2[i])
    {
        if((s1[i] == '-' || s1[i] == '+')
            && s1[i + 1] == '0' && s1[i + 2] == '\0')
        {
            s1[i] = '0';
            s1[i + 1] = '\0';
        }
        if(s1[i] == s2[i])
            i++;
        else
            return (1);
    }
    return (0);
}
static int unique(char **arv)
{
    int i;
    int j;
    
    i = 0;
    while(arv[i])
    {
        j = 0;
        while(arv[j])
        {
            if(j != i && !is_same(arv[j], arv[i]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
static int     is_int(char *str)
{
    int i;
    
    i = 0;
    if(just_nums(str))
        return(1);
    while (str[i])
    {
        while (str[i] && str[i] == ' ')
            i++;
        if(str[i] && str[i] != ' ' && (!ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-'))
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
char    **args(int arc, char **arv)
{
    int i;
    char *str;
    char **splited;
    
    i = 1;
    if(only_space(arv))
        return(ft_putstr_fd("Error\n", 2), NULL);
    str = ft_strdup("");
    while (i < arc)
    {
        if(is_int(arv[i]) || !arv[i][0])
        {
            free(str);
            return(ft_putstr_fd("Error\n", 2), NULL);
        }
        str = ft_strjoin(str, arv[i]);
        if(i < arc - 1)
            str = ft_strjoin(str, " ");
        i++;
    }
    splited = ft_split(str, ' ');
    if (unique(splited))
    {
        free_matrix(splited);
        return(ft_putstr_fd("Error\n", 2), NULL);
    }
    free(str);
    return (splited);
}
