/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:11:48 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/09 18:02:56 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

/* Function to print the figure corresponding to the given number (nbr) 
   by searching through the provided dictionary (dict). 
   Returns 1 if a match is found and printed, otherwise returns 0. */
int	ft_print_figure(char *nbr, char **dict)
{
	int		i;
	char	*dict_word;
	char	*dict_number;

	i = 0;
	while (dict[i])
	{

		//  this function get word from entry [i] in dictionary
		//  example. 9: nine
		//			 this function gonna return "nine'\0'"
		dict_word = ft_get_dict_word(dict[i]);

		//  this function get number from entry [i] in dictionary
		//  example. 60: sixty
		//			 this function gonna return "60'\0'"
		dict_number = ft_get_dict_number(dict[i]);

		//  compare 'nbr' and 'dict_number'
		//  if it equal print 'dict_word', then free both dict_word and dic_number, then return 
		if (ft_strcmp(nbr, dict_number) == 0)
		{
			ft_putstr(dict_word);
			free(dict_word);
			free(dict_number);
			return (1);
		}

		//  if current number doesn't match free both dict_word and dic_number
		//  and go to next loop, next loop gonna get word and number form next entry
		free(dict_word);
		free(dict_number);
		i++;
	}

	//  return 0 after process are finished
	return (0);
}

/* Function to print the exact value corresponding to the given number (nbr) 
   by searching through the provided dictionary (dict). 
   Returns 1 if a match is found and printed, otherwise returns 0. */
int	ft_print_exact_value(char *nbr, char **dict)
{
	int		i;
	char	*dict_word;
	char	*dict_number;

	i = 0;
	while (dict[i])
	{
		//  this function get word from entry [i] in dictionary
		//  example. 9: nine
		//			 this function gonna return "nine'\0'"
		dict_word = ft_get_dict_word(dict[i]);

		//  this function get number from entry [i] in dictionary
		//  example. 60: sixty
		//			 this function gonna return "60'\0'"
		dict_number = ft_get_dict_number(dict[i]);

		//  compare 'nbr' and 'dict_number'
		//  if it equal print 'dict_word', then free both dict_word and dic_number, then return 
		if (ft_strcmp(nbr, dict_number) == 0)
		{
			ft_putstr(dict_word);
			free(dict_word);
			free(dict_number);
			return (1);
		}

		//  if current number doesn't match free both dict_word and dic_number
		//  and go to next loop, next loop gonna get word and number form next entry
		free(dict_word);
		free(dict_number);
		i++;
	}

	//  return 0 after process are finished
	return (0);
}
