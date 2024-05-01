/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:37:09 by qbarron           #+#    #+#             */
/*   Updated: 2024/03/29 16:37:09 by qbarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(char *str)
{
	ft_putstr_fd("\e[31m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\e[0m", 2);
	exit(0);
}



