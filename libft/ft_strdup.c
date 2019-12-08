/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:31:27 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:31:28 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		x;
	int		i;

	i = 0;
	x = ft_strlen(str);
	if (!(dest = (char*)malloc(sizeof(char) * x + 1)))
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
