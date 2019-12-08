/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 16:15:22 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/01/17 12:15:10 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_c(const char *s, char c)
{
	int amount_of_words;
	int tmp;

	if (!s)
		return (0);
	tmp = 0;
	amount_of_words = 0;
	while (*s)
	{
		if (*s == c)
			tmp = 0;
		if (tmp == 0 && *s != c)
		{
			tmp = 1;
			amount_of_words++;
		}
		s++;
	}
	return (amount_of_words);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	amount_of_words;

	if (!s || !c)
		return (NULL);
	amount_of_words = ft_count_c(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * amount_of_words + 1)))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < amount_of_words)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		str[j] = ft_strsub(s, start, i - start);
		i++;
	}
	str[j] = 0;
	return (str);
}
