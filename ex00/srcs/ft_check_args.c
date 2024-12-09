/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:52:56 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/09 15:23:44 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

// checking if string contains number
int	ft_is_contain_number(char *str)
{
	int	i;

	i = 0;
	// while str[i] != '\0'
	while (str[i])
	{
		// if str[i] is number (0-9), return 1
		// if not, continue searching on next index
		if (ft_is_number(str[i]))
			return (1);
		i++;
	}

	// this mean, from loop above we didn't find any number in index string
	// and it reached null terminater, return 0
	return (0);
}

// checking if argument are valid number
// it work similar like ft_atoi, 
// but instead of return number back it return 0 or 1
// 0 mean argv[1] is not valid number
// 1 mean argv[1] is valid number
int	ft_check_nbr(char *nbr)
{
	int		i;
	int		sign;

	// checking if string is empty or if string not contain number
	// if true (string is empty or not contain any number), return 0
	// if false (string is not empty or contain number), continue
	if (ft_strlen(nbr) == 0 || !ft_is_contain_number(nbr))
		return (0);

	i = 0;

	// skiping space
	while (ft_is_whitespace(nbr[i]))
		i++;
	sign = 1;

	//checking if string contains '+' or '-' character if true loop continue
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		// if string index [i] equal to '-' minus
		// sign = sign * -1 (sign = -sign)
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}

	// return 0 if sign equal to -1
	// because we cant take negative number
	if (sign == -1)
		return (0);

	// just (while nbr[i] != '\0')
	while (nbr[i])
	{
		// if nbr index [i] is not numbers (0-9), return 0
		if (nbr[i] < '0' || nbr[i] > '9')
			return (0);
		i++;
	}

	// if it reach this line that mean number in argv[1]
	// is not negative number, not empty and not contain any character
	return (1);
}

// this is just ft_strlen, but only count the numbers character (0-9), and it skip space, '-', '+', '0'
int	ft_count_nbr_char_len(char *src, int *index)
{
	int	i;
	int	nbr_len;
	int	only_zero;

	i = 0;
	only_zero = 1;

	// while scr index [i] != '\0' and src index [1] is space (' ', '\t', etc)
	// skip that index
	while (src[i] && ft_is_whitespace(src[i]))
		i++;

	// if src[i] is '-' or '+' or '0' skip the '-', '+', '0' character
	while (src[i] == '-' || src[i] == '+' || src[i] == '0')
		i++;

	//send i value back to index var in ft_clean_nbr()
	*index = i;

	// count the number lenght
	nbr_len = 0;
	while (src[i] >= '0' && src[i] <= '9')
	{
		// if we found another number that are not '0', set only_zero to 0
		if (src[i] != '0')
			only_zero = 0;
		nbr_len++;
		i++;
	}
	
	// if only_zero = true(1), this mean this string(src) contain only '0'
	// set i - 1 to index so it can start from index 0 
	// (look at line:96 we already skip '0' character so we have to go back)
	if (only_zero)
	{
		*index = i - 1;
		return (1);
	}

	// return lenght of string that already skip space, '-', '+', '0'
	return (nbr_len);
}

// this is just string duplicate/copy that skip space, '-', '+', '0'
char	*ft_clean_nbr(char *src)
{
	char	*dest;
	int		nbr_len;
	int		index;
	int		i;

	// count number lenght in src
	nbr_len = ft_count_nbr_char_len(src, &index);

	// use nbr_len to allocate memmory for dest var
	dest = malloc(sizeof(char) * (nbr_len + 1));

	// if dest == 0 (malloc doesn't allocate any memmory) that mean lenght of number is 0, return 0
	if (!dest)
		return (0);
	*dest = 0;
	i = 0;

	// duplicate string of number form src to dest
	// for src we use index counter that we got from ft_count_nbr_char_len() 
	// 		(the index that already skiped space, '-', '+', '0')
	// for dest, it just start from index [0]
	while (src[index])
	{
		dest[i] = src[index];
		i++;
		index++;
	}

	// close the string with null terminater
	dest[nbr_len] = '\0';

	// return dest back
	return (dest);
}

// checking if argument are valid
// assign dictpath and nbr then send them back to main()
// return 0 if argument are invalid, return 1 if argument are valid
int	ft_check_args(int argc, char **argv, char **dictpath, char **nbr)
{
	// if user input 3 argument ./[program_name] [number] [dict]
	if (argc == 3)
	{
		// if ft_check_nbr() return 0 back, return 0
		if (!ft_check_nbr(argv[1]))
			return (0);

		// assign argv[2] into dicpath var, and send it back to main
		*dictpath = argv[2];

		// copy numbers form arv[1] into nbr, and send it back to main
		*nbr = ft_clean_nbr(argv[1]);

		// if ft_clean_nbr doesn't return any value back, return 0
		if (*nbr == 0)
			return (0);

		// pass all the check return 1
		return (1);
	}

	// if user input 2 argument ./[program_name] [number] 
	else if (argc == 2)
	{
		// if ft_check_nbr() return 0 back, return 0
		if (!ft_check_nbr(argv[1]))
			return (0);

		// set dict file path into dicpath, and send it back to main
		// DEFAULT_DICT mean default dictionary file path, in case of argc is 2 (user didn't provide the dictionary)
		// (DEFAULT_DICT is defined in "function.h")
		*dictpath = DEFAULT_DICT;

		// copy numbers form arv[1] into nbr, and send it back to main
		*nbr = ft_clean_nbr(argv[1]);

		// if ft_clean_nbr doesn't return any value back, return 0
		if (*nbr == 0)
			return (0);

		// pass all the check return 1
		return (1);
	}

	// amount of argument are not equal to 2 or 3
	// that mean user input invalid number of argument, return 0;
	return (0);
}
