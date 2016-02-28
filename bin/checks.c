/*
** checks.c for checks in /home/rinaz_a/rendu/B2_CPE/sudoki-bi
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Sun Feb 28 00:59:12 2016 selim rinaz
** Last update Sun Feb 28 01:10:53 2016 
*/

#include "sudoki_bi.h"

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
      if (check_line(k,grid,i) && check_collumns(k,grid,j)
	  && check_square(k,grid,i,j))
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
