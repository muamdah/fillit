/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muamdah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 04:57:26 by muamdah           #+#    #+#             */
/*   Updated: 2018/01/25 15:34:15 by muamdah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 21
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/libft.h"
#include "fillit.h"
#include <stdio.h>

/* -[ 2 ]----- Recuperation du tableau, insertion des tetriminos ------ */

static char		**ft_open2(char **tab, char **argv)
{
	char	buf[BUF_SIZE + 1];
	char	**s;
	int		fd;
	int		ret;
	int		i;

	s = tab;
	i = 0;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		ft_putendl("error");
		return (0);
	}
	if (!(s))
		return (NULL);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		s[i++] = ft_strdup(buf);
	}
	s[i] = NULL;
	if (close(fd) == -1)
	{
		ft_putendl("erreur mec");
	}
	return (s);
}

int		ft_void(int i)
{
	if (i == 0)
	{
		ft_putendl("error");
		exit(0);
	}
	return (1);
}

/* -[ 1 ]---- Ouvrir le fichier, lecture et creation d'un tableau : Retour MAIN ------ */

char			**ft_open(char **argv)
{
	char	buf[BUF_SIZE + 1];
	int		fd;
	int		ret;
	int		i;
	char	**tab;

	i = 0;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		ft_putendl("error");
		return (0);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
		i++;
	if (!(tab = (char**)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	tab[i] = NULL;
	if (close(fd) == -1)
	{
		ft_putendl("erreur mec");
	}
	tab = ft_open2(tab, argv);
	return (tab);
}
