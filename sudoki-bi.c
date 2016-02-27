/*
** sudoki-bi.c for sudoki-bi in /home/rinaz_a/rendu/B2_CPE/sudoki-bi
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Sat Feb 27 11:46:15 2016 selim rinaz
** Last update Sat Feb 27 15:20:05 2016 rouill_d
*/

#include <stdlib.h>
#include "sudoki-bi.h"

char	**fill_my_char_2d()
{
  char	**tab;
  int	idx;

  if ((tab = malloc(sizeof(char *) * 12)) == NULL)
    return (NULL);
  while (idx <= 10)
    {
      if ((tab[idx] = malloc(sizeof(char) * 12)) == NULL)
	return (NULL);
      tab[idx] = get_next_line(0);
      idx++;
    }
  return (tab);
}

int	check_line(char **tab)
{
  int	nbr;
  int	idx;

  if (idx > 0 && idx <=9)
    {

    }
  else
    my_putstr_err("number must be between 1 and 9");
}

int	main()
{
  char	**tab;

  tab = fill_my_char_2d();
  my_putstr_2d(tab);
  return (0);
}
