/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:48:40 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/08 21:38:10 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

# define DEFAULT_DICT "./data/numbers.dict"

int		ft_check_args(int argc, char **argv, char **dictpath, char **nbr);

int		ft_check_dict(char *dictpath);
int		ft_get_file_size(char *dictpath);

int		ft_init(char *dictpath, char *nbr);

int		ft_nbr_count(char *nb);
char	**ft_split_trio_nbr(char *nbr, int size);

void	ft_free(char **dict, char **tab_nbr, char *nbr, char *zerovalue);

int		ft_print_power_ten(int tab_nbr_size, char **dict);
int		ft_print_hundred(char *nbr, char **dict);
int		ft_print_tens(char *nbr, char **dict);
int		ft_print_trio(char *nbr, char **dict);

int		ft_print_figure(char *nbr, char **dict);
int		ft_print_exact_value(char *nbr, char **dict);

int		ft_word_len(char *str);
int		ft_number_len(char *str);
char	*ft_get_dict_word(char *str);
char	*ft_get_dict_number(char *line);

char	**ft_split(char *str, char *charset);
char	*ft_add_word(char *src, int size);

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strcmp(char *s1, char *s2);	
int		ft_strlen(char *str);

int		ft_is_whitespace(char c);
int		ft_is_alpha(char c);
int		ft_is_lower(char c);
int		ft_is_upper(char c);
int		ft_is_number(char c);

#endif