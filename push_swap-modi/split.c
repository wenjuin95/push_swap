/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:11:45 by utente            #+#    #+#             */
/*   Updated: 2024/01/16 14:34:55 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	p = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[p] == separator)
		++p;
	while ((str[p + len] != separator) && str[p + len])
		++len;
	next_str = malloc(sizeof(char) * (size_t)len + 1);
	if (!next_str)
		return (NULL);
	while ((str[p] != separator) && str[p])
		next_str[i++] = str[p++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char separator)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = count_words(str, separator);
	if (!words_number)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (!vector_strings)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (i == 0)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (!vector_strings[i])
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(str, separator);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}

// static size_t	count_sub_len(char *s, char separator)
// {
// 	size_t	count;
// 	size_t	i;

// 	if (s == 0 || separator == 0)
// 		return (0);
// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		while (s[i] == separator)
// 			i++;
// 		if (s[i] != '\0')
// 			count++;
// 		while (s[i] != separator && s[i])
// 			i++;
// 	}
// 	return (count);
// }

// static char	*copy_sub(char *str, size_t n)
// {
// 	size_t	i;
// 	char	*result;

// 	if (str == NULL)
// 		return (NULL);
// 	result = malloc(sizeof(char) * n + 1);
// 	if (result == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < n)
// 	{
// 		result[i] = str[i];
// 		i++;
// 	}
// 	result[i] = '\0';
// 	return (result);
// }

// char	**ft_split(char *s, char separator)
// {
// 	size_t	i;
// 	char	**split;
// 	char	*sub_str;

// 	if (s == NULL)
// 		return (NULL);
// 	split = (char **)malloc(sizeof(char *)
// 			* ((count_sub_len(s, separator)) + 1));
// 	if (split == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (*s)
// 	{
// 		while (*s && *s == separator)
// 			s++;
// 		if (*s == '\0')
// 			break ;
// 		sub_str = s;
// 		while (*s && *s != separator)
// 			s++;
// 		split[i] = copy_sub(sub_str, s - sub_str);
// 		i++;
// 	}
// 	split[i] = NULL;
// 	return (split);
// }
