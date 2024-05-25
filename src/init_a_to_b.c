/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:20:39 by qbarron           #+#    #+#             */
/*   Updated: 2024/05/14 13:20:39 by qbarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int median;

	i = 0;
	if(!stack)
		return ;
	median = stack_len(stack) / 2;
	while(stack)
	{
		stack->index = i;
		if(i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	set_target_a(t_stack_node *a, t_stack_node *b) //on cherche une node cible pour envoyer A dans B
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while(a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while(current_b)
		{
			if(current_b->nbr < a->nbr
				&& current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if(best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node; //on set la target
		a = a->next;
	}
}

static void	ft_cost_analysis_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		if (stack_a->above_median && stack_a->target_node->above_median)
		{
			stack_a->push_cost = stack_a->index;
			if (stack_a->index < stack_a->target_node->index)
				stack_a->push_cost = stack_a->target_node->index;
		}
		if (!(stack_a->above_median) && !(stack_a->target_node->above_median))
		{
			stack_a->push_cost = len_a - stack_a->index;
			if ((len_a - stack_a->index) < (len_b - stack_a->target_node->index))
				stack_a->push_cost = len_b - stack_a->target_node->index;
		}
		if (stack_a->above_median && !(stack_a->target_node->above_median))
			stack_a->push_cost = stack_a->index + (len_b - stack_a->target_node->index);
		if (!stack_a->above_median && stack_a->target_node->above_median)
			stack_a->push_cost = (len_a - stack_a->index) + stack_a->target_node->index;
		stack_a = stack_a->next;
	}
}

void set_cheapest(t_stack_node *stack)
{
	long	cheapest_value;
	t_stack_node *cheapest_node;

	if(!stack)
		return ;
	cheapest_value = LONG_MAX;
	while(stack)
	{
		if(cheapest_node < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}