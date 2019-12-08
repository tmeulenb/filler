/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:29:03 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:29:04 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (!(s = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	if (s != NULL)
		ft_memset(s, '\0', size);
	return (s);
}
