/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:48:20 by urycherd          #+#    #+#             */
/*   Updated: 2021/10/27 18:01:42 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*adress;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	adress = *lst;
	while (adress->next)
		adress = adress->next;
	adress->next = new;
}
