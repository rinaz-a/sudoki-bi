/*
** sudoki-bi.c for sudoki-bi in /home/rinaz_a/rendu/B2_CPE/sudoki-bi
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Sat Feb 27 11:46:15 2016 selim rinaz
** Last update Sat Feb 27 21:40:59 2016 
*/

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

bool absentSurLigne (int k, int **grille, int i)
{
  for (int j=0; j < 9; j++)
    if (grille[i][j] == k)
      return false;
  return true;
}

bool absentSurColonne (int k, int **grille, int j)
{
  for (int i=0; i < 9; i++)
    if (grille[i][j] == k)
      return false;
  return true;
}

bool absentSurBloc (int k, int **grille, int i, int j)
{
  int _i = i-(i%3), _j = j-(j%3);  // ou encore : _i = 3*(i/3), _j = 3*(j/3);
  for (i=_i; i < _i+3; i++)
    for (j=_j; j < _j+3; j++)
      if (grille[i][j] == k)
	return false;
  return true;
}

bool estValide (int **grille, int position)
{
  if (position == 9*9)
    return true;

  int i = position/9, j = position%9;

  if (grille[i][j] != 0)
    return estValide(grille, position+1);

  for (int k=1; k <= 9; k++)
    {
      if (absentSurLigne(k,grille,i) && absentSurColonne(k,grille,j) && absentSurBloc(k,grille,i,j))
	{
	  grille[i][j] = k;

	  if ( estValide (grille, position+1) )
	    return true;
	}
    }
  grille[i][j] = 0;

  return false;
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

  x[0] = 2;
  y[0] = 1;
  x[1] = 0;
  y[1] = 0;
  if ((grid = malloc(sizeof(int *) * 9)) == NULL)
    exit(EXIT_FAILURE);
  while (x[0] <= 19 && y[0] <= 10)
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
      x[0] = 2;
    }
  return (grid);
}

int	main()
{
  char	**tab;
  int	**grid;

  tab = fill_my_char_2d();
  printf("basic map\n\n");
  my_putstr_2d(tab);
  grid = create_int_2d(tab);
  my_display(grid);
  return (0);
}
