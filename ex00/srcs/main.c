/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:15:59 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/09 15:23:42 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>

int	main(int argc, char **argv)
{
	char	*dictpath;
	char	*nbr;

	// if ft_check_args return 0 back, print "Error\n" then stop the program
	// and also send the address of dictpath and nbr into function
	// for more info, go read in "ft_check_args.c"
	if (!ft_check_args(argc, argv, &dictpath, &nbr))
	{
		ft_putstr("Error\n");
		return (1);
	}

	// if ft_check_dict return 0 back, free nbr memmory, print "Dict Error\n" then stop the program
	if (!ft_check_dict(dictpath))
	{
		free(nbr);
		ft_putstr("Dict Error\n");
		return (1);
	}
	
	if (!ft_init(dictpath, nbr))
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	return (0);
}
