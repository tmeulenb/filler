/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:29:25 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:29:26 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*d1;
	const unsigned char	*d2;

	d1 = s1;
	d2 = s2;
	while (n--)
		if (*d1++ != *d2++)
			return (*--d1 - *--d2);
	return (0);
}
