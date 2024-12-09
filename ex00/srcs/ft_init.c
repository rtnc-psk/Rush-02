/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:02:38 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/09 19:10:20 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>

//  function to read the files at the given path
//  and return it content as an array of strings
char	**ft_read_file(char *dictpath)
{
	char	*buffer;
	char	**split;
	int		file;
	int		size;
	int		bytes_read;

	//  function to get the size of the file at the given path
	//  defined in "ft_check_dict.c"
	size = ft_get_file_size(dictpath);
	if (size < 0)
		return (0);
	
	//  open the dictionary file from dictpath in read-only mode (O_RDONLY = Open in read only mode)
	//  then set file descriptor into 'file' var
	//  open() gonna return -1 if it failed
	file = open(dictpath, O_RDONLY);

	//  if fail to open the file return 0;
	if (file == -1)
		return (0);

	//  use 'size' that we get value from ft_get_file_size() above
	//  to allocte memmory for 'buffer'
	buffer = malloc (sizeof(char) * (size + 1));
	
	//  if malloc doesn't allocate any memmory, close the file then return NULL)
	if (!buffer)
		return ((void)close(file), NULL);

	//  read the value in dictionary then assign it to 'bytes_read'
	//	this function will return number of bytes read on success
	bytes_read = read(file, buffer, size);

	//  checking if the bytes that readed are equal to
	//  the bytes counted from ft_get_file_size()
	//  if not equal free 'buffer', close dictionary file, return NULL.
	if (bytes_read != size)
		return (free(buffer), (void)close(file), NULL);

	//  close array of string with null terminater
	buffer[size] = '\0';

	//  split string that got from dictionary file into array of string separate by newline
	split = ft_split(buffer, "\n");

	//  free 'buffer', because it already split all string and asigned into 'split'
	free(buffer);

	// close the dictionary file after we used it
	close(file);

	// return array of string
	return (split);
}

// function to initialize a zero value string
char	*ft_init_zerovalue(void)
{
	int		i;
	char	*zerovalue;

	i = 0;
	
	//  this function should return "000'\0'"
	//  so it need 4 bytes of char
	zerovalue = malloc(sizeof(char) * 4);
	
	//  if malloc fail, return 0
	if (!zerovalue)
		return (0);

	//  set first index to null terminater
	*zerovalue = 0;

	//  this loop add '0' into array
	while (i < 3)
	{
		zerovalue[i] = '0';
		i++;
	}

	//  close an array with null terminater
	zerovalue[i] = 0;

	//  return array of three zero back
	return (zerovalue);
}

// function to check if there is a next value greater than zero value
int	ft_check_next_value(char **tab_nbr, char *zerovalue, int index)
{
	int		i;

	i = index;
	while (tab_nbr[i])
	{
		if (ft_strcmp(tab_nbr[i], zerovalue) > 0)
			return (1);
		i++;
	}
	return (0);
}

// function to start processing the numbers and printing their representations
int	ft_start(char **dict, char **tab_nbr, int tab_nbr_size, char *zerovalue)
{
	int	i;

	i = 0;
	while (tab_nbr[i])
	{
		//  checking if current group of 3 number equal to "000'\0'"
		//  if equal print 1 space
		if (i > 0 && ft_strcmp(tab_nbr[i], zerovalue) > 0)
			ft_putchar(' ');

		ft_print_trio(tab_nbr[i], dict);
		if (tab_nbr_size - i > 1 && ft_strcmp(tab_nbr[i], zerovalue) > 0)
		{
			ft_print_power_ten(tab_nbr_size - i, dict);
			if (ft_check_next_value(tab_nbr, zerovalue, i + 1))
				ft_putchar(',');
		}
		i++; 
	}
	ft_putchar('\n');
	return (1);
}

int	ft_init(char *dictpath, char *nbr)
{
	char	**tab_nbr;
	char	**dict;
	char	*zerovalue;
	int		tab_nbr_size;

	//	read dictionary file and split each entry into array of string
	dict = ft_read_file(dictpath);

	//  find the lenght of number, but in a group of three
	//  exmaple. size of '0' is 1, size of '10' is 1, size of '100' is 1
	//			 size of '1001' is 2,  size of '100100100' is 3
	tab_nbr_size = ft_nbr_count(nbr);

	//  split a number string into groups of three digits, then assign it into 'tab_nbr'
	tab_nbr = ft_split_trio_nbr(nbr, tab_nbr_size);

	//  function to initialize a group of three zero number string
	zerovalue = ft_init_zerovalue();

	//  if lenght of numner equal to 1 and that number is 0
	//  (user input '0' in)
	if (ft_strlen(nbr) == 1 && nbr[0] == '0')
	{
		//  Function to print the exact value corresponding to the given number (nbr) 
		//  by searching through the provided dictionary (dict). 
		//  Returns 1 if a match is found and printed, otherwise returns 0.
		ft_print_exact_value(nbr, dict);
		ft_putchar('\n');

		//  free all allocated variable before return
		ft_free(dict, tab_nbr, nbr, zerovalue);
		return (1);
	}
	if (ft_start(dict, tab_nbr, tab_nbr_size, zerovalue))
	{
		ft_free(dict, tab_nbr, nbr, zerovalue);
		return (1);
	}
	ft_free(dict, tab_nbr, nbr, zerovalue);
	return (0);
}
