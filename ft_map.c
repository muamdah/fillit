/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muamdah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:20:47 by muamdah           #+#    #+#             */
/*   Updated: 2018/02/01 09:20:51 by muamdah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"
#include "include/libft.h"
#include <stdio.h>

/* -[ 2 ]------- Creation de la map avec en parametre la taille a creer ------*/

char    **ft_map(int c)
{
    char **map;
    int x;
    int y;

  
    x = 0;
    y = 0;
    if (!(map = (char **)malloc(sizeof(char*) * (c + 1))))
        return (NULL);
    map[c] = 0;
    while (y < c)
    {
        if (!(map[y] = (char *)malloc(sizeof(char) * (c + 1))))
            return (NULL);
        map[y][c] = '\0';
		while (x < c)
		{
            map[y][x] = '.';
			x++;
		}
		y++;
        x = 0;
    }
    return (map);
}

/* -[ 1 ]------- Permet d'inserer les coordonnees dans la map : Retour sur FT_TAB_COOR -------*/

int		ft_fill(char **tab_final, char **map, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!tab_final[i])
		return (1);
	while (map[y])
	{
		if (map[y][x] == '.')
			if (ft_position(tab_final[i], map, x, y))
			{
				if (ft_fill(tab_final, map, i + 1))
					return (1);
				ft_delete(tab_final[i], map);
			}
		x++;
		if (map[y][x] == '\0')
		{
			y++;
			x = 0;
		}
	}
	return (0);
}

int		ft_count(char **map)
{
	int y;
	int i;

	y = 0;
	i = 0;
	while (map[y][i] != '\0')
		i++;
	return (i);
}

int		ft_position(char *tab_coor, char **map, int x, int y)
{
	if (x + tab_coor[1] < 0 || y + tab_coor[0] >= ft_count(map) ||
	 	map[y + tab_coor[0]][x + tab_coor[1]] != '.')
	 	return (0);
	if (x + tab_coor[3] < 0 || y + tab_coor[2] >= ft_count(map) ||
		map[y + tab_coor[2]][x + tab_coor[3]] != '.')
		return (0);
	if (x + tab_coor[5] < 0 || y + tab_coor[4] >= ft_count(map) ||
		map[y + tab_coor[4]][x + tab_coor[5]] != '.')
		return (0);
	// if (x + tab_coor[7] < 0 || y + tab_coor[6] >= ft_count(map) ||
	 	// map[y + tab_coor[6]][x + tab_coor[7]] != '.')
	// 	return (0);
	map[y][x] = tab_coor[6];
	map[y + tab_coor[0]][x + tab_coor[1]] = tab_coor[6];
	map[y + tab_coor[2]][x + tab_coor[3]] = tab_coor[6];
	map[y + tab_coor[4]][x + tab_coor[5]] = tab_coor[6];
	//map[y + tab_coor[6]][x + tab_coor[7]] = tab_coor[8];
	return (1);
}