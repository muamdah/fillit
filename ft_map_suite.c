/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_suite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muamdah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:06:31 by muamdah           #+#    #+#             */
/*   Updated: 2018/02/08 15:06:35 by muamdah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_delete(char *tab_coor, char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[y])
	{
		if (map[y][x] == tab_coor[6])
			map[y][x] = '.';
		x++;
		if (map[y][x] == '\0')
		{
			x = 0;
			y++;
		}
	}
}

void	ft_aff(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		ft_putendl(tab[i++]);
}

char	**ft_map2(char **tab, int i)
{
	char	**map2;
    char	**tab_final;
    int     size;
    int    lettre;

    size = 0;
    lettre = 65;
    if (!(tab_final = (char**)malloc(sizeof(char*) * (i + 1))))
        return (NULL);
	while (tab[size])
	{
        tab_final[size] = ft_coor(tab[size], lettre++);
		size++;
	}
	tab_final[size] = 0;
	size = 2;
	map2 = ft_map(size);
	while (ft_fill(tab_final, map2, 0) == 0)
	{
		map2 = ft_map(size);
		size++;
	}
		return (map2);
}
