/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:09:24 by rabustam          #+#    #+#             */
/*   Updated: 2022/10/11 17:59:02 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	erase_b(t_info *info)
{
	t_stack	*temp;

	temp = info->stack_b;
	while (temp->next != info->top_b && \
	temp->next != NULL)
		temp = temp->next;
	if (temp->next == NULL)
	{
		info->stack_b = NULL;
		info->top_b = NULL;
		return ;
	}
	temp->next = NULL;
	info->top_b = temp;
}

void	push_a(t_info *info)
{
	t_stack	*temp;

	temp = info->stack_a;
	if (info->stack_b == NULL)
		return ;
	if (temp == NULL)
	{
		info->stack_a = info->top_b;
		info->stack_a->prev = NULL;
		info->top_a = info->stack_a;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = info->top_b;
		temp->next->prev = temp;
		info->top_a = info->top_b;
	}
	erase_b(info);
	ft_putstr_fd("pa\n", 1);
}

static void	erase_a(t_info *info)
{
	t_stack	*temp;

	temp = info->stack_a;
	while (temp->next != info->top_a)
		temp = temp->next;
	temp->next = NULL;
	info->top_a = temp;
}

void	push_b(t_info *info)
{
	t_stack	*temp;

	temp = info->stack_b;
	if (info->stack_a == NULL)
		return ;
	if (temp == NULL)
	{
		info->stack_b = info->top_a;
		info->stack_b->prev = NULL;
		info->top_b = info->stack_b;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = info->top_a;
		temp->next->prev = temp;
		info->top_b = info->top_a;
	}
	erase_a(info);
	ft_putstr_fd("pb\n", 1);
}
