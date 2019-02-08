/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 23:55:16 by bel-bouz          #+#    #+#             */
/*   Updated: 2019/01/24 03:32:34 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H

# define SWAP_H
# define BUFF_SIZE 1
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_ROS		"\x1b[35m"
# define ANSI_COLOR_RESET	"\x1b[0m"
# define ANSI_COLOR_BLUE	"\x1b[36m"
# define ABS(i)  ((i < 0) ? (-i) : (i))

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_pile
{
	int				value;
	struct s_pile	*prec;
	int				index;
	int				bl;
	int				mark_up;
}					t_pile;

typedef struct		s_var
{
	int		i;
	int		max;
	int		min;
	int		*min_p;
	int		*max_p;
	int		a;
	int		b;
	int		lena;
	int		lenb;
	int		*len_a;
	int		*len_b;
	int		nb;
}					t_var;

void				affiche_rota(int bl);
int					test_thre(t_pile **lst_a, int *len_a);
int					calcul_len(char **tab);
int					find_max_index(t_pile **pile, int len);
void				ajouter_mark_up(t_pile **pile, int len_a, int index);
void				best_mark_up(t_pile **pile, int len_a, int max_index);
int					ajouter_index(t_pile **pile, int len_a);
int					calcu_interva(int lena);
void				rev_retat2(t_pile **lst_a, t_pile **lst_b, t_var *var);
void				swap2(t_pile **lst_a, t_pile **lst_b, t_var *var);
char				**ft_split_whitespaces(char *str);
void				inisia_push(t_var *var);
int					check_double(t_pile **pile, int double_, int len);
int					check(t_pile **pile, int len);
void				ft_putnbr(int nb);
void				inisia(t_var *var);
void				affichag_2(t_pile **lst_a, t_pile **lst_b, t_var *var);
int					ajout_lst(int argc, char **argv,
					t_pile **lst_a, t_var *var);
void				ft_putchar(char c);
int					ft_atoi_check(const char *str);
void				excute_rotat_a(t_pile **lst_a, int min, int *len_a, int i);
void				excute_rotat_b(t_pile **lst_a, int min, int *len_a, int i);
size_t				ft_strlen(const char *s);
int					ft_atoi_check(const char *str);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strdel(char **as);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcat(char *s1, const char *s2);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
char				*ft_strchr(const char *s, int c);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_putchar(char c);
int					get_next_line(int fd, char **line);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
void				free_lst(t_pile **pile, int len);
int					find_max(t_pile **pile, int *max, int *min, int len);
int					style_ther(t_pile *pile, int temp, int len);
int					error(void);
char				*ft_strcat(char *s1, const char *s2);
int					ft_atoi(const char *str);
int					retation (t_pile **pile, int len, int bl);
int					revretation(t_pile **pile, int len, int bl);
void				pile_push(t_pile **pile, int valeur, int *len);
void				afficher(t_pile **pile, int len, int bl);
int					check_decroissant(t_pile **pile, int lena, int lenb);
int					push(t_pile **pile_a, t_pile **pile_b,
					int *len_a, int *len_b);
int					swap(t_pile **pile, int len, int bl);

#endif
