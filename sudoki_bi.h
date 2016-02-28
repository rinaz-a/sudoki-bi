/*
** sudoki-bi.h for sudoki-bi in /home/rinaz_a/rendu/B2_CPE/sudoki-bi
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Sat Feb 27 11:47:38 2016 selim rinaz
** Last update Sun Feb 28 01:08:46 2016 
*/

#ifndef SUDOKI_BI_H_
# define SUDOKI_BI_H_

# ifndef READ_SIZE
#  define READ_SIZE (32)
# endif /* !READ_SIZE */

typedef struct	s_data
{
  char		buf[READ_SIZE];
  int		idx;
  int		ret;
}		t_data;

typedef struct	s_tmp
{
  char		*line;
  int		kill;
  int		pos;
}		t_tmp;

char		*get_next_line(const int fd);
char		*alloc(int idx, int pos, char *buf, char *line);
int		my_strlen(char *str);
void		my_putchar(char c);
void		my_putstr(char *str);
void		my_putstr_2d(char **str);
void		my_puterr(char *str);
int		check_line(int k, int **grid, int i);
int		check_collumns(int k, int **grid, int j);
int		check_square(int k, int **grid, int i, int j);
int		check_grid(int **grid, int position);
char		**fill_my_char_2d();
int		**create_int_2d(char **tab);
void		my_putint_2d(int **grid);
int		main();

#endif /* !SUDOKI_BI_H_ */
