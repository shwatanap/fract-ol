/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:24:07 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/22 17:23:03 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Iterates the list ’lst’
 * and applies the function ’f’ on the content of each node.
 * Creates a new list resulting of the successive applications of
 * the function ’f’. The ’del’ function is used
 * to delete the content of a node if needed.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*updated_lst;
	t_list	*updated_ele;

	if (lst == NULL || f == NULL)
		return (NULL);
	updated_lst = NULL;
	while (lst != NULL)
	{
		updated_ele = ft_lstnew(f(lst->content));
		if (updated_ele == NULL)
		{
			ft_lstclear(&updated_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&updated_lst, updated_ele);
		lst = lst->next;
	}
	return (updated_lst);
}
