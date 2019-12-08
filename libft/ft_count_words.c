/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_words.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 18:20:58 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/23 18:20:59 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(const char *s)
{
	int amount_of_words;
	int tmp;

	if (!s)
		return (0);
	tmp = 0;
	amount_of_words = 0;
	while (*s)
	{
		if (*s == ' ' || *s == '\n' || *s == '\t' ||
						*s == '\v' || *s == '\f' || *s == '\r')
			tmp = 0;
		else if (tmp == 0 && (*s != ' ' || *s != '\n' || *s != '\t' ||
						*s != '\v' || *s != '\f' || *s != '\r'))
		{
			tmp = 1;
			amount_of_words++;
		}
		s++;
	}
	return (amount_of_words);
}