/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:32:25 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:32:27 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		res[i] = (*f)(i, res[i]);
		i++;
	}
	return (res);
}
