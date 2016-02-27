/*
** functions.c for functions in /home/rouillard/Rendu/PSU_2015_minitalk/client
** 
** Made by rouill_d
** Login   <rouill_d@epitech.net>
** 
** Started on  Fri Feb  5 13:17:08 2016 Paul Rouillard
** Last update Sun Feb 21 18:53:14 2016 rouill_d
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;
  
  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int	my_put_nbr(int nbr)
{
  int	a;

  a = 1;
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * (-1);
    }
  while ((nbr / a) >= 10)
    a = a * 10;
  while (a > 0)
    {
      my_putchar((nbr / a) % 10 + '0');
      a = a / 10;
    }
  return (0);
}
