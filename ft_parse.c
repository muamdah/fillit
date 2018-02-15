/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muamdah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:12:49 by muamdah           #+#    #+#             */
/*   Updated: 2018/02/15 18:37:24 by muamdah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>

/* -[ 5 ]---- Parse aucun tetriminos ou au dela de 26 -----*/

int				ft_void(int i)
{
	if (i <= 0 || i > 26)
	{
		ft_putendl("error");
		exit(0);
	}
	return (1);
}

/* -[ 4 ]----- Verification des tetriminos 3eme etape : 6 ou 8 liens entre les '#' ------*/

static int		ft_check_valide(char *tab)
{
	int		i;
	int		d;

	i = 0;
	d = 0;
	while (tab[i])
	{
		if (tab[i] == '#' && tab[i + 1] == '#')
			d++;
		if ((i < 15) && tab[i] == '#' && tab[i + 5] == '#')
			d++;
		if ((i > 0) && tab[i] == '#' && tab[i - 1] == '#')
			d++;
		if ((i > 4) && tab[i] == '#' && tab[i - 5] == '#')
			d++;
		if (tab[i])
			i++;
	}
	if (d == 6 || d == 8)
		return (1);
	return (0);
}

/* -[ 3 ]----- Verification des tetriminos 2eme etape : dernier tetriminos '\n' ------*/

static int		ft_check_last(char *tab)
{
	int		i;
	int		p;
	int		dz;
	int		n;

	i = 0;
	p = 0;
	dz = 0;
	n = 0;
	while (tab[i])
	{
		if (tab[i] == '.')
			p++;
		if (tab[i] == '#')
			dz++;
		if (tab[i] == '\n' &&  tab[4] == '\n' && tab[9] == '\n' && tab[14] ==
			'\n' && tab[19] == '\0')
			n++;
		i++;
	}
	if (p == 12 && dz == 4 && n == 3)
		return (ft_check_valide(tab));
	return (0);
}

/* -[ 2 ]----- Verification des tetriminos 1er etape : 4 '#' ------ */

static int		ft_check1(char *tab)
{
	int		i;
	int		p;
	int		dz;
	int		n;

	i = 0;
	p = 0;
	dz = 0;
	n = 0;
	while (tab[i])
	{
		if (tab[i] == '.')
			p++;
		if (tab[i] == '#')
			dz++;
		if (tab[i] == '\n' && tab[4] == '\n' && tab[9] == '\n' && tab[14] ==
			'\n' && tab[19] == '\n' && tab[20] == '\n')
			n++;
		i++;
	}
	if (p == 12 && dz == 4 && n == 5)
		return (ft_check_valide(tab));
	return (0);
}

/* -[ 1 ]----- Verification complete retour sur MAIN ------*/

int				ft_main_check(char **tab_check, int len)
{
	int		i;
	int		b;

	i = 0;
	while (i < len)
	{
		if (i < len - 1)
			b = ft_check1(tab_check[i]);
		if (i + 1 == len)
			b = ft_check_last(tab_check[i]);
		if (b == 0)
		{
			ft_putendl("error");
			return (0);
		}
		i++;
	}
	return (1);
}
