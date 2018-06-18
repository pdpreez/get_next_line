/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:11:46 by ppreez            #+#    #+#             */
/*   Updated: 2018/05/31 16:11:55 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcount(char const *s, char c)
{
	size_t		i;
	size_t		wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			wc++;
		i++;
	}
	return (wc);
}

static void		populate(char **wc, char const *s, char c)
{
	size_t		word;
	size_t		lc;
	size_t		i;

	word = 0;
	lc = 0;
	i = 0;
	while (word < wordcount(s, c))
	{
		while (s[i] != c && s[i])
		{
			lc++;
			i++;
		}
		if (lc > 0)
		{
			wc[word] = ft_strsub(s, i - lc, lc);
			lc = 0;
			word++;
		}
		i++;
	}
	wc[word] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char		**wc;

	if (!s || !c)
		return (NULL);
	if (!(wc = (char **)ft_memalloc(sizeof(char **) * wordcount(s, c) + 1)))
		return (NULL);
	populate(wc, s, c);
	return (wc);
}
