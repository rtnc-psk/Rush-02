/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trio_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:13:45 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/09 16:03:57 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

// function to count the number of groups of three digits in a string
int	ft_nbr_count(char *nb)
{
	int	len;
	
	//  use ft_strlen to count string lenght then divine it by 3
	len = ft_strlen(nb) / 3;

	//  plus 1 to the len if number modulate 3 nut equal to 0
	if (ft_strlen(nb) % 3 != 0)
		len++;

	//  return lenght of number in group of three
	return (len);
}

// function to split a number string into groups of three digits
char	**ft_split_trio_nbr(char *nbr, int size)
{
	char	**trio_nbr;
	int		i;
	int		k;
	int		item_len;

	//  allocate memmory for array of group of 3 number of string
	//  using size we got from ft_nbr_count();
	trio_nbr = malloc(sizeof(char *) * (size + 1));

	//  if malloc doesn't allocate any memmory, return 0;
	if (!trio_nbr)
		return (0);

	//  add null terminater to fisrt index of array
	*trio_nbr = 0;

	//  check if all group of number are 3 digit or not by modulate it by 3
	item_len = ft_strlen(nbr) % 3;
	i = 0;
	k = 0;

	//  if result of modulate above equal to 0 (that's mean all group of number have 3 digit)
	//  change item_len to 3
	if (item_len == 0)
		item_len = 3;
	while (nbr[i])
	{
		//  split string of number then copy it into array
		trio_nbr[k++] = ft_add_word(nbr + i, item_len);

		//  skip [item_len] index, so we moved to next group of number 
		i += item_len;

		//  'item_len' not equal to 3 mean, there's one group of number that doesn't have 3 digit
		//  above we all ready add that group into array, so set 'item_len' back to 3 
		if (item_len != 3)
			item_len = 3;
	}

	//  close the array with null terminater
	trio_nbr[size] = 0;

	//  return table of number back
	return (trio_nbr);
}
