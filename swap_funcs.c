/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:08:28 by rabustam          #+#    #+#             */
/*   Updated: 2022/10/08 04:01:27 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_info *info)
{
	t_stack	*temp;
	int		swapv;
	int		swapi;

	temp = info->stack_a;
	while (temp->next != info->top_a)
		temp = temp->next;
	swapv = temp->value;
	swapi = temp->index;
	temp->value = info->top_a->value;
	temp->index = info->top_a->index;
	info->top_a->value = swapv;
	info->top_a->index = swapi;
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_info *info)
{
	t_stack	*temp;
	int		swapv;
	int		swapi;

	temp = info->stack_b;
	while (temp->next != info->top_b)
		temp = temp->next;
	swapv = temp->value;
	swapi = temp->index;
	temp->value = info->top_b->value;
	temp->index = info->top_b->value;
	info->top_b->value = swapv;
	info->top_b->index = swapi;
	ft_putstr_fd("sa\n", 1);
}

void	swap_s(t_info *info)
{
	swap_a(info);
	swap_b(info);
	ft_putstr_fd("ss\n", 1);
}
