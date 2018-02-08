/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muamdah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:00:24 by muamdah           #+#    #+#             */
/*   Updated: 2018/01/25 18:45:29 by muamdah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	**tab_check;
	int		i;

	i = 0;
	tab_check = ft_open(argv);
	while (tab_check[i])
		i++;
	if (argc == 2)
	{
		if(ft_main_check(tab_check))
		{
			ft_tab_coor(tab_check, i);
			printf("oui dans le main");
		}
	}
	return (0);
}