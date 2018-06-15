/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 11:50:57 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/15 11:25:32 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Free objs and quit
*/

void	ft_quit(t_env *rt, t_obj *objs)
{
	t_obj	*tmp;
	t_obj	*next;

	tmp = objs;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	mlx_destroy_image(rt->mlx.mlx_ptr, rt->mlx.img.img_ptr);
	mlx_clear_window(rt->mlx.mlx_ptr, rt->mlx.win);
	mlx_destroy_window(rt->mlx.mlx_ptr, rt->mlx.win);
	exit(0);
}

/*
**	Initializing the scene
*/

void	ft_initialization(t_env *rt, int scene)
{
	rt->aa = 1.0;
	if (scene == 1)
		ft_first(rt);
	else if (scene == 2)
		ft_second(rt);
	else if (scene == 3)
		ft_third(rt);
	else if (scene == 4)
		ft_fourth(rt);
	else if (scene == 5)
		ft_fifth(rt);
	else if (scene == 6)
		ft_sixth(rt);
	else if (scene == 7)
		ft_seventh(rt);
	else if (scene == 8)
	{
		rt->nb_spot = 2.0;
		ft_eighth(rt);
	}
}

int		main(int ac, char **av)
{
	t_env rt;

	if (ac != 2 || ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 8)
	{
		write(2, "usage : ./rtv1 <scene>\n", 23);
		return (1);
	}
	ft_bzero(&rt, sizeof(t_env));
	ft_initialization(&rt, ft_atoi(av[1]));
	ft_env_init(&rt);
	return (0);
}
