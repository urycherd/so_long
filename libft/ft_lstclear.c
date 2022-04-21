/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:46:35 by urycherd          #+#    #+#             */
/*   Updated: 2021/10/27 17:02:51 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;

	if (lst)
	{
		while (*lst)
		{
			if ((*lst)->content)
				del((*lst)->content);
			a = *lst;
			*lst = a->next;
			free(a);
		}
		lst = NULL;
	}
}
