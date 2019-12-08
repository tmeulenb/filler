/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:29:46 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:29:47 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*src;

	dst = dest;
	src = source;
	if (src < dst)
	{
		src = src + n - 1;
		dst = dst + n - 1;
		while (n--)
			*dst-- = *src--;
	}
	else
		while (n--)
			*dst++ = *src++;
	return (dest);
}
