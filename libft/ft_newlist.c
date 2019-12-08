/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_newlist.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:46:40 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/04/25 13:47:08 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_newlist(void)
{
	t_list			*list;

	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (!list)
		return (NULL);
	return (list);
}
