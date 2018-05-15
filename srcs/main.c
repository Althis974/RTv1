/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 11:50:57 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 13:54:54 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
void	ft_initialization(t_env *rt)
{
	return ;
}*/

int		main(int ac, char **av)
{
	t_env rt;

	if (ac != 2)
		write(2, "usage : ./rtv1 <scene>\n", 23);
	printf("\n%s\n", av[0]);
	ft_bzero(&rt, sizeof(t_env));
//	ft_initialization(&rt);
//	ft_env_init(&rt);
//	free(&rt);
//	ft_bzero(&rt, sizeof(t_env));
	return (0);
}
