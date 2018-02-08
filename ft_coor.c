/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muamdah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:25:20 by muamdah           #+#    #+#             */
/*   Updated: 2018/01/29 19:08:53 by muamdah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "fillit.h"
#include <stdio.h>

/* -[ 2 ]----- Coordonnee de chaque tetriminos pour determiner la forme ------ */

int     *ft_coor(char *str,int z)
{
	int	*tab;
	int		i;
	int		a;
	int    	x;
	int		y;

	a = 0;
	i = 0;
	y = 0;
	if (!(tab = (int*)malloc(sizeof(int) * 9)))
		return (NULL);
	while (str[i] && str[i] != '#')
		i++;
	x = i;
	while (str[x])
	{
		if (str[x] == '\n' && (i = i + 5))
			y++;
		if (str[x] == '#')
		{
			tab[a++] = y;
			tab[a++] = (x - i);
		}
		x++;
	}
	tab[8] = 65 + z;
	return (tab);
}

/* -[ 1 ]----- Creation d'un tableau pour recuperer les coordonnees + lettre : Retour MAIN ------*/

int **ft_tab_coor(char **tab, int len)
{
	int i;
	int z;
	int **tab_coor;

	i = 0;
	z = 0;
	if (!(tab_coor = (int**)malloc(sizeof(int *) * len)))
		return (NULL);
	while (i < len)
	{
		tab_coor[i] = ft_coor(tab[i], z + i);
		i++;
	}
	i = 0;
	ft_position(tab_coor);
	return (tab_coor);
}