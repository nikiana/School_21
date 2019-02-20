/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:56:30 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/29 19:15:58 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft.h"

typedef struct	s_flags
{
	int s;
	int w;
	int c;
	int f;
	int count;
}				t_flags;

/*
** Checker functions
*/
void			sa(t_list *a);
void			sb(t_list *b);
void			ss(t_list *a, t_list *b);
void			pa(t_list **b, t_list **a);
void			pb(t_list **a, t_list **b);
void			ra(t_list **a);
void			rb(t_list **b);
void			rr(t_list **a, t_list **b);
void			rra(t_list **a);
void			rrb(t_list **a);
void			rrr(t_list **a, t_list **b);

int				read_instructions(t_list **a, t_list **b, int sign);

/*
** Push_swap functions
*/
void			p_sa(t_list *a, t_list *b, t_flags *flag);
void			p_sb(t_list *a, t_list *b, t_flags *flag);
void			p_ss(t_list *a, t_list *b, t_flags *flag);
void			p_pa(t_list **b, t_list **a, t_flags *flag);
void			p_pb(t_list **a, t_list **b, t_flags *flag);
void			p_ra(t_list **a, t_list *b, t_flags *flag);
void			p_rb(t_list *a, t_list **b, t_flags *flag);
void			p_rr(t_list **a, t_list **b, t_flags *flag);
void			p_rra(t_list **a, t_list *b, t_flags *flag);
void			p_rrb(t_list *a, t_list **b, t_flags *flag);
void			p_rrr(t_list **a, t_list **b, t_flags *flag);

int				check_flags(char *str, t_flags *flag);

int				find_max(t_list *a, int *val);
int				find_min(t_list *a, int *val);
int				find_min_ind(t_list *a);
int				find_max_ind(t_list *a);
int				find_place(int ind, t_list *a);

void			sort_small(t_list **a, t_list **b, int sz, t_flags *flag);
void			sort_medium(t_list **a, t_list **b, int sz, t_flags *flag);
void			sort_large(t_list **a, t_list **b, int sz, t_flags *flag);

int				find_el_to_move(t_list *a, t_list *b, int *b_idx);
void			parse_a_list(t_list **a, t_list **b, int *delim, t_flags *flag);
void			from_b_to_a(t_list **a, t_list **b, t_flags *flag);
void			print_stack(t_list *a, t_list *b, t_flags *flag);

void			total_steps_num(t_flags *flag);

/*
** Joint functions
*/
int				is_sorted(t_list *a);
int				is_rev_sorted(t_list *b);
int				is_valid(t_list *a, long int i);
void			delete_element(t_list *prev, t_list **elem, t_list *next);
int				read_from_file(t_list **a, char *file);
int				get_nums(char *str, t_list **a);
int				error();
int				clean_all(t_list *a, t_list *b, t_flags *flag, char **res);

#endif
