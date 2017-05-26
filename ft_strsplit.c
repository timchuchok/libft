/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:41:08 by vtymchen          #+#    #+#             */
/*   Updated: 2016/11/30 16:17:56 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words_count(const char *s, char c)
{
	int count;

	count = 0;
	if (*s != c && *s)
	{
		count++;
		s++;
	}
	while (*s)
	{
		if (*s == c)
			if (*(s + 1) != c && *(s + 1) != '\0')
				count++;
		s++;
	}
	return (count);
}

static char		*ft_next_word(const char *s, char c, int *i)
{
	int		j;
	char	*str;

	j = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[*i] != c && s[*i] != '\0')
		str[j++] = s[(*i)++];
	str[j] = '\0';
	return (str);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**table;
	int		w_i;
	int		i;

	w_i = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	table = (char **)malloc(sizeof(char *) * (ft_words_count(s, c) + 1));
	if (table == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			table[w_i++] = ft_next_word(s, c, &i);
	}
	table[w_i] = NULL;
	return (table);
}
