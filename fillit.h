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

# include "libft/libft.h"

char	**ft_open(char **argv);
int		ft_main_check(char **tab_check, int len);
int		ft_fill(int **gps, char **map, int i);
void	ft_aff(char **tab);
char	**ft_map2(char **tab, int i);
int		ft_void(int i);

#endif