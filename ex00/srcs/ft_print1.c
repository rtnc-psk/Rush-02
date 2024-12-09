/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:11:05 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/09 19:06:52 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	ft_print_power_ten(int tab_nbr_size, char **dict)
{
	char	*value;
	int		size;
	int		i;

	size = ((tab_nbr_size - 1) * 3) + 1;
	value = malloc(sizeof(char) * (size + 1));
	if (!value)
		return (0);
	value[0] = '1';
	i = 1;
	while (i < size)
	{
		value[i] = '0';
		i++;
	}
	value[size] = '\0';
	ft_putchar(' ');
	ft_print_exact_value(value, dict);
	free(value);
	return (1);
}

//  function for print out "[number] hundred"
//  if first digit in group are not '0'
int	ft_print_hundred(char *nbr, char **dict)
{
	char	*c;

	//  if 'nbr' index [0] equal to '0', return
	if (nbr[0] == '0')
		return (1);

	//  allocate memmory for first diglit and null terminater
	c = malloc(sizeof(char) * 2);

	//  if malloc failed, return 0
	if (!c)
		return (0);

	//  assign first number from group to 'c'
	*c = nbr[0];

	//  close an array with null terminater
	c[1] = '\0';

	//  print out "[number in letter word]", " ", "hundred"
	ft_print_figure(c, dict);
	ft_putchar(' ');
	ft_print_figure("100", dict);
	
	free(c);
	return (1);
}

int	ft_print_tens(char *nbr, char **dict)
{
	char	*d;

	//  skip number '0'
	while (*nbr == '0')
		nbr++;
	
	//  if after skiped 0 there number left in group, return
	if (!*nbr)
		return (1);
	
	//  if after skipped, left number are in 1-19 range or last digit is '0', 
	//  print out letter of that number and return
	if (*nbr && ft_print_exact_value(nbr, dict))
		return (1);

	//  allocate memmory for seccond diglit in group, '0', null terminater
	d = malloc(sizeof(char) * 3);

	//  if malloc failed, return
	if (!d)
		return (0);

	//  assign second number to first index, 
	//  follow by '0' on next, then close by null terminater
	*d = nbr[0];
	d[1] = '0';
	d[2] = '\0';
	
	//  print out "[number in letter word]"
	ft_print_exact_value(d, dict);

	free(d);
	return (0);
}

int	ft_print_trio(char *nbr, char **dict)
{
	int	nbr_len;

	//  check lenght of cuurent group of number
	nbr_len = ft_strlen(nbr);

	//  if group of number have 3 digit
	if (nbr_len == 3)
	{
		//  function for print out "[number] hundred"
		//  if first digit in group are not '0'
		ft_print_hundred(nbr, dict);
		
		//  print " and" if first number in group not equal to '0'
		//  and second and thrid digit are not both '0'
		if (nbr[0] != '0' && (nbr[1] != '0' || nbr[2] != '0'))
			ft_putstr(" and ");

		//  go to next number
		nbr++;
	}

	//  if in ft_print_tens number are in 1-19 range or last digit is '0'
	if (ft_print_tens(nbr, dict))
		return (1);

	//  go to next number
	nbr++;

	//print out separater
	ft_putchar('-');

	//print last number
	ft_print_figure(nbr, dict);
	return (1);
}
