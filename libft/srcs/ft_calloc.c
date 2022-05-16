/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 08:22:21 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/22 17:22:04 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	m_size;

	if (size != 0 && SIZE_MAX / size < count)
		return (NULL);
	m_size = count * size;
	if (m_size == 0)
		m_size = 1;
	p = malloc(m_size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, m_size);
	return (p);
}
