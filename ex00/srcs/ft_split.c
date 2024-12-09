/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:12:32 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/09 14:24:19 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

// function to allocate memory for a new word and copy it from the source
char	*ft_add_word(char *src, int size)
{
	int		i;
	char	*dest;

	i = 0;

	//  use size to allocate memmory for destination
	dest = malloc (sizeof(char) * (size + 1));

	//  if malloc doesn't allocate any memmory, return NULL
	if (!dest)
		return (NULL);
	
	//  keep copying src index [i] into dest index [i]
	//  until it reached null terminater or i < size (end of the entry line)
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	
	//  close the string with null terminater
	dest[i] = '\0';

	//  return splited entry back
	return (dest);
}

//  function to check if a character is part of the charset
//  so it just checking if character parsed is equal to charset
//  if equal return 1, if not return 0
int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

//  it just ft_strlen, but this will count till
//  reached null terminater OR reached the 'charset' 
int	ft_count_word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	// counting string lenght unill it reach charset(in this case charset is '\n')
	while (str[i] && !ft_is_charset(str[i], charset))
		i++;

	//  return lenght of the word
	return (i);
}


//  this function counting the entry in dictionary
//  by using charset(newline) as indicator
int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	count;
	int	word_len;

	i = 0;
	count = 0;
	word_len = 0;
	while (str[i])
	{
		//  skip all charset we found at start of string
		//  in this case, we skiping newline at start of dictionary file
		while (str[i] && ft_is_charset(str[i], charset))
			i++;

		//  counting how many entry in dictionary 
		//  by iterate through string and if it found newline, count = count + 1
		word_len = ft_count_word_len(str + i, charset);

		//  if number of entry found not equal to 0
		//  plus 1 to the entry count (last line don't have newline so it didn't counted)
		if (word_len)
			count++;

		//  what the fuck is this for?!
		i += word_len;
		word_len = 0;
	}

	// return number of word (amount of entry)
	return (count);
}

// function to split the string into a array of wordds based on the charset
char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		word_len;
	int		count_word;
	char	**tab;

	i = 0;
	j = 0;
	word_len = 0;

	//  count amount if entry in dictionary
	count_word = ft_count_word(str, charset);

	//  use amount of word we got from above to allocate memmory
	tab = malloc(sizeof(char *) * (count_word + 1));

	//  if malloc doesn't allocate any memmory, return NULL
	if (!tab)
		return (NULL);

	//  while str[i] != '\0'
	while (str[i])
	{
		//  skip all charset we found at start of string
		//  in this case, we skiping newline at start of dictionary file
		while (str[i] && ft_is_charset(str[i], charset))
			i++;

		//  use ft_count_word_len() to check if str index [i] is empty or it's charset.
		word_len = ft_count_word_len(str + i, charset);

		//  if word_len is true (true = any numbers that is not 0)
		if (word_len)
			//  assign entry that split by newline into array of string 
			tab[j++] = ft_add_word(str + i, word_len);

		//  what the fuck is this for?!
		i += word_len;
		word_len = 0;
	}

	//  close the entry array with null terminater
	tab[j] = 0;

	//  return array of splited dictionary back
	return (tab);
}
