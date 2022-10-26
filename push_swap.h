/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:08:01 by rabustam          #+#    #+#             */
/*   Updated: 2022/10/17 13:47:10 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len_a;
	int		len_b;
	int		pivot;
	t_stack	*top_a;
	t_stack	*top_b;
	int		max;
}	t_info;

//project obrigatory functions:
void	swap_a(t_info *info);
void	swap_b(t_info *info);
void	swap_s(t_info *info);
void	push_a(t_info *info);
void	push_b(t_info *info);
void	rotate_a(t_info *info, int rr);
void	rotate_b(t_info *info, int rr);
void	rotate_r(t_info *info);
void	reverse_rotate_a(t_info *info, int rrr);
void	reverse_rotate_b(t_info *info, int rr);
void	reverse_rotate_r(t_info *info);

//check for error functions:
int		check_number(char *argv);
int		check_error(char **argv);
int		*check_for_duplicates(int *input, char **argv, int list_size);
int		is_ordenated(int input_len, int *input);

//algorithm functions:
void	init_stacks(t_info *info);
void	create_stacks(int *a, int list_size, t_info *info);
void	find_max(t_info *info);
void	init_index(t_info *info);
void	case3(t_info *info);
void	case_bigger_stacks(t_info *info);
void	set_cost(t_info *info);
void	push_back(t_info *info);
int		find_max_index(t_info *info);
int		ft_abs(int i);

#endif