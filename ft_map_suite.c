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
#include "libft/libft.h"

/* -[ 4 ]----- Afficher la map finale ----- */

void	ft_aff(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		ft_putendl(tab[i++]);
}

/* -[ 3 ]----- Coordonnee de chaque tetriminos pour determiner la forme ------ */

static int     *ft_coord(char *str,int z)
{
	int		*tab;
	int		i;
	int		a;
	int    	x;
	int		y;

	a = 0;
	i = 0;
	y = 0;
	 if (!(tab = (int*)malloc(sizeof(int) * (9))))
	 	return (NULL);
	while (str[i] && str[i] != '#')
		i++;
	x = i - 1;
	while (str[++x])
	{
		if (str[x] == '\n' && (i = i + 5))
			y++;
		if (str[x] == '#')
		{
			tab[a++] = y;
			tab[a++] = (x - i);
		}
	}
	tab[8] = z;
	return (tab);
}
/* -[ 2 ]------- Creation de la map avec en parametre la taille a creer ------*/

static char	**ft_map(int c)
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

/* -[ 1 ]----- Creation d'un tableau pour recuperer les coordonnees + lettre : Retour MAIN ------*/

char	**ft_map2(char **tab, int i)
{
	char	**map2;
    int		**tab_final;
    int     size;
    int    lettre;
    size = -1;
    lettre = 65;
    if (!(tab_final = (int**)malloc(sizeof(int*) * (i + 1))))
        return (NULL);
	while (tab[++size])
        tab_final[size] = ft_coord(tab[size], lettre++);
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
