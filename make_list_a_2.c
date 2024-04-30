/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_a_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:11 by pximenez          #+#    #+#             */
/*   Updated: 2024/02/05 13:59:52 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

int	ft_check_same_input(char **argv, int i, int j)
{
	int	len;

	len = ft_strlen(argv[i]);
	if (len < (int) ft_strlen(argv[j]))
		len = (int) ft_strlen(argv[j]);
	return (ft_strncmp(argv[i], argv[j], len));
}

int	ft_additional_rules(char **argv)
{
	int	j;
	int	i;

	i = 0;
	while (argv[i] != 0)
	{
		j = i + 1;
		while (argv[j] != 0)
		{
			if (ft_check_same_input(argv, i, j) == 0)
				return (FALSE);
			j++;
		}
		if (argv[i][0] == '-')
		{
			if (ft_strlen(argv[i]) > 11 || (ft_strlen(argv[i]) == 11
					&& ft_strncmp(argv[i], "-2147483648", 11) > 0))
				return (FALSE);
		}
		else if (ft_strlen(argv[i]) > 10 || (ft_strlen(argv[i]) == 10
				&& ft_strncmp(argv[i], "2147483647", 10) > 0))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_check_spaces(char **argv)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < (int)ft_strlen(argv[0]))
	{
		if (ft_isdigit(argv[0][i]) == 0 && argv[0][i] != ' '
				&& argv[0][i] != '-')
			return (FALSE);
		i++;
		if (argv[0][i] == ' ')
			counter++;
	}
	if (counter == 0)
		return (FALSE);
	return (TRUE);
}
