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
            map[y][x++] = '.';
        y++;
        x = 0;
    }
    return (map);
}

/* -[ 1 ]------- Permet d'inserer les coordonnees dans la map : Retour sur FT_TAB_COOR -------*/

void    ft_position(int **tab)
{
    int     y;
    int     x;
    int     i;
    int     b;
    int     a;
    char    **s;
    int     **t;

    y = 0;
    x = 0;
    i = 0;
    b = 3;
    a = 0;
    s = ft_map(3);
    t = tab;
    while (y < 3 && x < 3)
    {
       if ((s[y] || s[y][x] || s[y][x] == '.') && a <= 6)
        {
            printf("%d\n", y);
            y = t[b][a];
            x = t[b][a + 1];
            s[y][x] = t[b][8];
            a++;
            a++;
        }
        x++;
        y++;
    }
    printf("%d\n", a);
    while (i < 3)
    {
        ft_putendl(s[i]);
        i++;
    }
}