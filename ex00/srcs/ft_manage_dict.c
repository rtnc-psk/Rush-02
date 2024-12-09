/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_dict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:04:37 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/09 17:23:58 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

//  this's just ft_strlen()
int	ft_word_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// ft_strlen() but only count the number
int	ft_number_len(char *str)
{
	int	i;

	i = 0;
	while (ft_is_number(str[i]))
		i++;
	return (i);
}

// function to extract the word from a dictionary
char	*ft_get_dict_word(char *str)
{
	int		i;
	int		j;
	int		word_len;
	char	*dest;

	i = 0;

	//  skip the number before ':' and ':', ' ', character
	while (str[i] != ':')
		i++;
	if (str[i] == ':')
		i++;
	while (str[i] == ' ')
		i++;

	//  find lenght string that already skipped unnecessary character
	word_len = ft_word_len(str + i);

	//  use lenght that got from above to allocate memmory for 'dest'
	dest = malloc(sizeof(char) * (word_len + 1));

	//  if malloc fail return 0
	if (!dest)
		return (0);

	//  start array of character with null terminater
	*dest = 0;

	//  duplicate sting from 'str' to 'dest'
	j = 0;
	while (str[i])
		dest[j++] = str[i++];
	
	//  close an array with null terminater
	dest[word_len] = '\0';

	//  return 'dest' back
	return (dest);
}

// function to extract the number from a dictionary entry
char	*ft_get_dict_number(char *line)
{
	int		i;
	int		nbr_len;
	char	*nbr;

	i = 0;

	//  count the number from given entry with ft_number_len() 
	//  then assign it into nbr_len
	nbr_len = ft_number_len(line);

	//  use nbr_len that got from above to allocate memmory for 'nbr'
	nbr = malloc(sizeof(char) * (nbr_len + 1));

	//  if malloc fail, return 0
	if (!nbr)
		return (0);

	//  start array of character with null terminater
	*nbr = 0;

	//  duplicate sting from 'line' to 'nbr'
	while (ft_is_alpha(line[i]))
	{
		nbr[i] = line[i];
		i++;
	}

	//  close an array with null terminater
	nbr[nbr_len] = '\0';

	//  return 'nbr' back
	return (nbr);
}
