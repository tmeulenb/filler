/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:33:34 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:33:35 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	x;
	char	*str;

	i = 0;
	x = start;
	if (!s)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && s[x])
	{
		str[i] = (char)s[x];
		i++;
		x++;
	}
	str[i] = '\0';
	return (str);
}
