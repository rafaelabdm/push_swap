/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:22:43 by rabustam          #+#    #+#             */
/*   Updated: 2022/10/24 21:29:03 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_info *info)
{
	info->stack_a = NULL;
	info->stack_b = NULL;
	info->top_a = NULL;
	info->top_b = NULL;
	info->len_a = 0;
	info->len_b = 0;
	info->pivot = 0;
	info->max = 0;
}

void	create_stacks(int *a, int list_size, t_info *info)
{
	int		i;
	t_stack	*new;
	t_stack	*prev;

	new = malloc(sizeof(t_stack));
	info->stack_a = new;
	info->len_a = list_size;
	prev = NULL;
	i = 0;
	while (i < list_size)
	{
		new->value = a[i];
		new->index = 0;
		new->next = NULL;
		new->prev = prev;
		if (i + 1 < list_size)
		{
			new->next = malloc(sizeof(t_stack));
			prev = new;
			new = new->next;
		}
		i++;
	}
	info->top_a = new;
}

void	find_max(t_info *info)
{
	t_stack	*temp;
	int		max;

	temp = info->stack_a;
	max = temp->value;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	info->max = max;
}

void	init_index(t_info *info)
{
	t_stack	*temp;
	t_stack	*temp_min;
	int		index;
	int		min;

	find_max(info);
	temp = info->stack_a;
	temp_min = NULL;
	index = 1;
	while (index <= info->len_a)
	{
		min = info->max;
		while (temp)
		{
			if (temp->value <= min && temp->index == 0)
			{
				min = temp->value;
				temp_min = temp;
			}
			temp = temp->next;
		}
		temp_min->index = index;
		temp = info->stack_a;
		index++;
	}
}

void	case3(t_info *info)
{
	if (info->top_a->value > info->stack_a->value && \
		info->stack_a->value > info->stack_a->next->value)
		rotate_a(info, 0);
	else if (info->top_a->value > info->stack_a->next->value && \
			info->top_a->value < info->stack_a->value)
		swap_a(info);
	else if (info->top_a->value > info->stack_a->next->value && \
			info->stack_a->next->value > info->stack_a->value)
	{
		rotate_a(info, 0);
		swap_a(info);
	}
	else if (info->top_a->value < info->stack_a->next->value && \
			info->top_a->value > info->stack_a->value)
		reverse_rotate_a(info, 0);
	else if (info->top_a->value < info->stack_a->next->value && \
			info->stack_a->next->value > info->stack_a->value)
	{
		reverse_rotate_a(info, 0);
		swap_a(info);
	}
}
