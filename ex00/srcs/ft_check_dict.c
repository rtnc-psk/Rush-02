/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:57:36 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/09 05:30:24 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

// function to get the size of the file at the given path
int	ft_get_file_size(char *dictpath)
{
	char	c;
	int		file;
	int		count;

	// open the dictionary file from dictpath in read-only mode (O_RDONLY = Open in read only mode)
	// then set file descriptor into 'file' var
	// open() gonna return -1 if it failed
	file = open(dictpath, O_RDONLY);

	// if it failed to open the file return -1
	if (file == -1)
		return (-1);

	// counting every character in dictionary file with loop
	count = 0;
	while (read(file, &c, 1))
		count++;
	
	// close the dictionary file after we used it
	close(file);

	// return file_size
	return (count);
}

// checking if the given dictionary file path is valid,
// by try to open the file with open() and check the size of dictionary file
int	ft_check_dict(char *dictpath)
{
	int	file;
	int	file_size;

	// open the dictionary file from dictpath in read-only mode (O_RDONLY = Open in read only mode)
	// then set file descriptor into 'file' var
	// open gonna return -1 if it failed
	file = open(dictpath, O_RDONLY);

	// if it failed to open the file return 0
	if (file == -1)
		return (0);

	// assign file size into 'file_size'
	file_size = ft_get_file_size(dictpath);

	// if 'file_size' equal to 0 (that mean nothing in dictionary), return 0
	if (file_size == 0)
		return (0);

	// close the dictionary file after we used it
	close(file);

	// dictionary file pass all the check, return 1
	return (1);
}
