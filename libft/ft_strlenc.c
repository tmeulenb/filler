/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlenc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 18:32:47 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/04/25 18:32:50 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t		ft_strlenc(const char *s, const char c)
{
	int		count;

	count = 0;
	while (s[count] != c)
	{
		count++;
	}
	return (count);
}
