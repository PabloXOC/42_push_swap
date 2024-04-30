/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paxoc01 <paxoc01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/09 13:54:03 by paxoc01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

int	ft_check_input(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 1)
		return (FALSE);
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i]))
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				if ((argv[i][j] == '-' && j != 0) || argv[i][j] != '-')
					return (FALSE);
				if ((int) ft_strlen(argv[i]) < 2)
					return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	count_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != 0)
		i++;
	return (i);
}

void	ft_free_split(char **split, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

t_list_int	*ft_put_in_a(int argc, char **argv, int i)
{
	t_list_int	*list_a;
	t_list_int	*temp;

	list_a = ft_lstnew_int(ft_atoi(argv[i]));
	if (!list_a)
	{
		free(list_a);
		return (NULL);
	}
	i++;
	while (i < argc)
	{
		temp = ft_lstnew_int(ft_atoi(argv[i]));
		if (!temp)
		{
			ft_lstclear_int(&list_a);
			return (NULL);
		}
		ft_lstadd_back_int(&list_a, temp);
		i++;
	}
	return (list_a);
}

t_list_int	*ft_make_list_a(int argc, char **argv)
{
	t_list_int	*list_a;
	char		**split;

	if (argc == 1 && ft_check_spaces(argv) == TRUE)
	{
		split = ft_split(argv[0], 32);
		if (split == NULL)
			return (NULL);
		argc = count_argv(split);
		if (ft_check_input(argc, split) == FALSE
			|| ft_additional_rules(split) == FALSE)
			return (NULL);
		list_a = ft_put_in_a(argc, split, 0);
		ft_free_split(split, argc);
	}
	else
	{
		if (ft_check_input(argc, argv) == FALSE
			|| ft_additional_rules(argv) == FALSE)
			return (NULL);
		list_a = ft_put_in_a(argc, argv, 0);
	}
	if (!list_a)
		return (NULL);
	return (list_a);
}
