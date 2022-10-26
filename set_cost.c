/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:31:13 by rabustam          #+#    #+#             */
/*   Updated: 2022/10/17 16:19:52 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int i)
{
	if (i < 0)
		return (i * (-1));
	return (i);
}

int	find_max_index(t_info *info)
{
	t_stack	*temp;
	int		max;

	temp = info->stack_a;
	max = temp->index;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

static int	insert_bigger_value(t_info *info, int index_b)
{
	t_stack	*temp;
	int		i;

	temp = info->top_a;
	i = 0;
	while (temp->index != (index_b - 1))
	{
		i++;
		temp = temp->prev;
		if (!temp)
		{
			index_b--;
			temp = info->top_a;
			i = 0;
		}
	}
	i++;
	if (i <= ((info->len_a - info->len_b) / 2))
		return (i);
	else
		return (i - (info->len_a - info->len_b));
}

static int	check_cost_a(t_info *info, int index_b)
{
	t_stack	*temp;
	int		i;
	int		max;

	temp = info->top_a;
	i = 0;
	max = find_max_index(info);
	if (index_b > max)
		return (insert_bigger_value(info, index_b));
	while (temp->index != (index_b + 1))
	{
		i++;
		temp = temp->prev;
		if (!temp)
		{
			index_b++;
			temp = info->top_a;
			i = 0;
		}
	}
	if (i <= ((info->len_a - info->len_b) / 2))
		return (i);
	else
		return (i - (info->len_a - info->len_b));
}

void	set_cost(t_info *info)
{
	t_stack	*temp;
	int		i;

	temp = info->top_b;
	if (info->len_b == 0)
		info->len_b = info->len_a - 3;
	i = 0;
	while (i++ <= (info->len_b / 2))
	{
		temp->cost_a = check_cost_a(info, temp->index);
		temp->cost_b = (i - 1);
		temp = temp->prev;
	}
	temp = info->stack_b;
	i = 0;
	while (i++ < info->len_b / 2)
	{
		temp->cost_a = check_cost_a(info, temp->index);
		temp->cost_b = (i) * (-1);
		temp = temp->next;
	}
}
