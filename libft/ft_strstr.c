/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:33:25 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:33:28 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strstr(char *haystack, char *needle)
{
	int		i;
	int		j;

	if (!haystack || !needle)
		return (NULL);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return (haystack + i);
		i++;
	}
	return (0);
}
