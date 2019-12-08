/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:32:16 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:32:20 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*res;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(res = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	ft_strcpy(res, s);
	while (res[i])
	{
		res[i] = (*f)(res[i]);
		i++;
	}
	return (res);
}
