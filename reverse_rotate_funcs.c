/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:10:59 by rabustam          #+#    #+#             */
/*   Updated: 2022/09/26 18:33:59 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_info *info, int rrr)
{
	t_stack	*temp;

	temp = info->stack_a;
	info->stack_a = info->stack_a->next;
	info->stack_a->prev = NULL;
	temp->next = NULL;
	temp->prev = info->top_a;
	info->top_a->next = temp;
	info->top_a = temp;
	if (!rrr)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_info *info, int rrr)
{
	t_stack	*temp;

	temp = info->stack_b;
	info->stack_b = info->stack_b->next;
	info->stack_b->prev = NULL;
	temp->next = NULL;
	temp->prev = info->top_b;
	info->top_b->next = temp;
	info->top_b = temp;
	if (!rrr)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_r(t_info *info)
{
	reverse_rotate_a(info, 1);
	reverse_rotate_b(info, 1);
	ft_putstr_fd("rrr\n", 1);
}
