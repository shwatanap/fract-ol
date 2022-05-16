/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:58:32 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/22 17:22:46 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Deletes and frees the given node and every successor of that node,
 * using the function ’del’ and free(3).
 * Finally, the pointer to the list must be set to NULL.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clear_target_lst;
	t_list	*next_lst;

	if (lst == NULL || del == NULL)
		return ;
	clear_target_lst = *lst;
	while (clear_target_lst != NULL)
	{
		next_lst = clear_target_lst->next;
		ft_lstdelone(clear_target_lst, del);
		clear_target_lst = next_lst;
	}
	*lst = NULL;
}
