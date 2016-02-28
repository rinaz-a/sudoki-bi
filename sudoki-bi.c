/*
** sudoki-bi.c for sudoki-bi in /home/rinaz_a/rendu/B2_CPE/sudoki-bi
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Sat Feb 27 11:46:15 2016 selim rinaz
** Last update Sun Feb 28 01:10:06 2016 
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "sudoki_bi.h"

void	my_putint_2d(int **grid)
{
  int	idx[2];

  idx[0] = 0;
  idx[1] = 0;
  printf("|------------------|\n|");
  while (idx[0] < 9)
    {
      while (idx[1] < 9)
	  printf(" %d", grid[idx[0]][idx[1]++]);
      printf("|\n|");
      idx[1] = 0;
      idx[0]++;
    }
  printf("------------------|\n");
}

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

int    	**create_int_2d(char **tab)
{
  int  	y[2];
  int  	x[2];
  int	**grid;

  y[0] = 1;
  x[1] = 0;
  y[1] = 0;
  if (((grid = malloc(sizeof(int *) * 9)) == NULL) )
    return (NULL);
  while ((x[0] = 2) && (y[0] <= 10))
    {
      if (((grid[y[1]] = malloc(sizeof(int) * 9)) == NULL))
	return (NULL);
      while (x[0] <= 19)
	{
	  if (tab[y[0]] == NULL)
	    return (NULL);
	  else if (tab[y[0]][x[0]] != ' ')
	    grid[y[1]][x[1]] = (tab[y[0]][x[0]]) - 48;
	  x[0] = x[0] + 2, x[1]++;
	}
      y[0]++;
      y[1]++;
      x[1] = 0;
    }return (grid);
}

int	main()
{
  char	**tab;
  int	**grid;

  if (((tab = fill_my_char_2d()) == NULL)
      || ((grid = create_int_2d(tab)) == NULL))
    {
      my_puterr("malloc failed\n");
      return (0);
    }
  check_grid(grid, 0);
  my_putint_2d(grid);
  return (0);
}
