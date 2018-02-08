/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muamdah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:00:24 by muamdah           #+#    #+#             */
/*   Updated: 2018/01/04 16:58:43 by muamdah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "include/libft.h"

char	**ft_open(char **argv);

int     ft_check1(char *tab);
int     ft_check_last(char *tab);
int		ft_check_valide(char *tab);
int		ft_main_check(char **tab_check);

int     *ft_coor(char *str, int z);
int 	ft_check(char **tab_1er_check);
int     **ft_tab_coor(char **tab, int len);
char    **ft_map(int c);
void    ft_position(int **tab);
//int     taille_map();

#endif