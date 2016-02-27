/*
** sudoki-bi.c for sudoki-bi in /home/rinaz_a/rendu/B2_CPE/sudoki-bi
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Sat Feb 27 11:46:15 2016 selim rinaz
** Last update Sat Feb 27 23:56:29 2016 
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "sudoki-bi.h"

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

int	check_line(int k, int **grid, int i)
{
  int	j;

  j = 0;
  while (j < 9)
    if (grid[i][j++] == k)
      return (0);
  return (1);
}

int	check_collumns(int k, int **grid, int j)
{
  int	i;

  i = 0;
  while (i < 9)
    if (grid[i++][j] == k)
      return (0);
  return (1);
}

int	check_square(int k, int **grid, int i, int j)
{
  int	idx[2];

  idx[0] = i-(i%3);
  idx[1] = j-(j%3);
  i = idx[0];
  while (i < (idx[0] + 3))
    {
      j = idx[1];
      while (j < (idx[1] + 3))
	{
	  if (grid[i][j] == k)
	    return (0);
	  j++;
	}
      i++;
    }
  return (1);
}

int	check_grid(int **grid, int position)
{
  int	i;
  int	j;
  int	k;

  k = 1;
  i = position/9;
  j = position%9;
  if (position == 9*9)
    return (1);
  if (grid[i][j] != 0)
    return (check_grid(grid, position + 1));
  while (k <= 9)
    {
      if (check_line(k,grid,i) && check_collumns(k,grid,j) && check_square(k,grid,i,j))
	{
	  grid[i][j] = k;
	  if (check_grid(grid, position + 1))
	    return (1);
	}
      k++;
    }
  grid[i][j] = 0;
  return (0);
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
  if ((grid = malloc(sizeof(int *) * 9)) == NULL)
    exit(EXIT_FAILURE);
  while ((x[0] = 2) && (y[0] <= 10))
    {
      if ((grid[y[1]] = malloc(sizeof(int) * 9)) == NULL)
	exit(EXIT_FAILURE);
      while (x[0] <= 19)
	{
	  if (tab[y[0]][x[0]] != ' ')
	    grid[y[1]][x[1]] = (tab[y[0]][x[0]]) - 48;
	  x[0] = x[0] + 2;
	  x[1]++;
	}
      y[0]++;
      y[1]++;
      x[1] = 0;
    }
  return (grid);
}

int	main()
{
  char	**tab;
  int	**grid;

  tab = fill_my_char_2d();
  grid = create_int_2d(tab);
  check_grid(grid, 0);
  my_putint_2d(grid);
  return (0);
}
