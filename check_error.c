/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:06:36 by rabustam          #+#    #+#             */
/*   Updated: 2022/10/24 17:23:28 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *argv)
{
	unsigned int	num;
	int				i;
	int				neg;

	i = 0;
	neg = 0;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			neg = 1;
		i++;
	}
	num = ft_atoi(&argv[i]);
	if (neg && num > 2147483648)
		return (-1);
	if (!neg && num > 2147483647)
		return (-1);
	return (0);
}

int	check_error(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		if (ft_strlen(argv[i]) > 11)
			return (-1);
		if (ft_strlen(argv[i]) >= 10)
		{
			if (check_number(argv[i]) == -1)
				return (-1);
		}
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (!ft_isdigit(argv[i][j++]))
				return (-1);
		}
	}
	return (0);
}

static int	compare(int input, int *tmp, int z)
{
	int	i;

	i = 0;
	while (i < z)
	{
		if (input == tmp[i])
		{
			free(tmp);
			return (1);
		}
		i++;
	}
	return (0);
}

int	*check_for_duplicates(int *input, char **argv, int list_size)
{
	int	i;
	int	j;
	int	z;
	int	*tmp;

	input = malloc((list_size) * sizeof(int));
	tmp = malloc((list_size) * sizeof(int));
	i = 0;
	j = list_size - 1;
	z = 0;
	while (argv[++i])
	{
		input[j] = ft_atoi(argv[i]);
		if (compare(input[j], tmp, z))
		{
			free(input);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		tmp[z++] = input[j--];
	}
	free(tmp);
	return (input);
}

int	is_ordenated(int input_len, int *input)
{
	int	i;

	i = 0;
	while (i < (input_len - 1))
	{
		if (input[i] < input[i + 1])
			return (0);
		i++;
	}
	free(input);
	return (1);
}
