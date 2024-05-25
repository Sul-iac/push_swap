/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:35:13 by qbarron           #+#    #+#             */
/*   Updated: 2024/05/25 11:35:13 by qbarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **root)
{
	if(!*root || (*root)->next)
		return;
	t_stack_node *first = *root;
	t_stack_node *second = (*root)->next;

	*root = second;
	first->next = second->next;
	if(second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
}

void	sa(t_stack_node *a, bool print)
{
	swap(a);
	if(!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node *b, bool print)
{
	swap(b);
	if(!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node *a, t_stack_node *b, bool print)
{
	swap(a);
	swap(b);
	if(!print)
		ft_printf("ss\n");
}