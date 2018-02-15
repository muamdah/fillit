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

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	**tab_check;
	int		len;

	len = 0;
	if (argc == 2)
	{
		tab_check = ft_open(argv);
		while (tab_check[len])
			len++;
		ft_void(len);
		if(ft_main_check(tab_check, len))
			ft_aff(ft_map2(tab_check, len));
	}
	return (0);
}