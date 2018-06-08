/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keycode.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 16:39:34 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/08 09:31:16 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Events
*/

int		ft_getting_keys(int key, t_env *rt)
{
	if (key == ESC && rt)
		exit(0);
	if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
		ft_moove(key, rt);
	ft_create(rt);
	return (0);
}

void	ft_moove(int key, t_env *rt)
{
	if (key == LEFT || key == A)
	{
		rt->cam.ori.z -= 0.5;
	}
	else if (key == RIGHT || key == D)
	{
		rt->cam.ori.z += 0.5;
	}
	else if (key == UP || key == W)
	{
		rt->cam.ori.y += 0.5;
	}
	else if (key == DOWN || key == S)
	{
		rt->cam.ori.y -= 0.5;
	}
}
