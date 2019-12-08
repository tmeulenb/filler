/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_2d_strnew.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:04:04 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/04/25 14:04:42 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	**ft_2d_strnew(size_t size)
{
	char	**str;

	str = malloc(sizeof(char *) * size);
	return (str);
}
