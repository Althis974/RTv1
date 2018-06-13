/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keycode.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 16:39:34 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 13:13:43 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Events keyboard
*/

int		ft_getting_keys(int key, t_env *rt)
{
	if (key == ESC)
		exit(0);
	R1 = ft_vsub(&rt->cam.dir, &rt->cam.ori);
	ft_vnorm(&R1);
	R2 = ft_vcross(&R1, &(t_vec){0.0, 1.0, 0.0});
	ft_vnorm(&R2);
	R3 = ft_vcross(&R2, &R1);
	if (key == LEFT || key == RIGHT || key == DOWN || key == UP)
		ft_moove(key, rt);
	if (key == A || key == D || key == W || key == S)
		ft_rotate(key, rt);
	if (key == MORE && rt->aa < 4)
		rt->aa *= 2;
	if (key == LESS && rt->aa > 1)
		rt->aa /= 2;
	ft_launch(rt, 1);
	return (0);
}

/*
**	Rotation of camera
*/

void	ft_rotate(int key, t_env *rt)
{
	double	tmp;

	if (key == A && (tmp = CAMX) < 1000.0)
	{
		CAMX = CAMX * cosf(0.05) + CAMZ * sinf(0.05);
		CAMZ = tmp * (-sinf(0.05)) + CAMZ * cosf(0.05);
	}
	else if (key == D && (tmp = CAMX) > -1000.0)
	{
		CAMX = CAMX * cosf(-0.05) + CAMZ * sinf(-0.05);
		CAMZ = tmp * (-sinf(-0.05)) + CAMZ * cosf(-0.05);
	}
	else if (key == W && (tmp = CAMY) > -1000.0)
	{
		CAMY = CAMY * cosf(-0.05) + CAMZ * (-sinf(-0.05));
		CAMZ = tmp * sinf(-0.05) + CAMZ * cosf(-0.05);
	}
	else if (key == S && (tmp = CAMY) < 1000.0)
	{
		CAMY = CAMY * cosf(0.05) + CAMZ * (-sinf(0.05));
		CAMZ = tmp * sinf(0.05) + CAMZ * cosf(0.05);
	}
}

/*
**	Movement of camera
*/

void	ft_moove(int key, t_env *rt)
{
	if (key == LEFT)
	{
		CAMD = (t_vec){CAMD.x + 5.0 * R2.x, CAMD.y + 5.0 * R2.y, \
		CAMD.z + 5.0 * R2.z};
		CAMO = (t_vec){CAMX + 5.0 * R2.x, CAMY + 5.0 * R2.y, CAMZ + 5.0 * R2.z};
	}
	else if (key == RIGHT)
	{
		CAMD = (t_vec){CAMD.x - 5.0 * R2.x, CAMD.y - 5.0 * R2.y, \
		CAMD.z - 5.0 * R2.z};
		CAMO = (t_vec){CAMX - 5.0 * R2.x, CAMY - 5.0 * R2.y, CAMZ - 5.0 * R2.z};
	}
	else if (key == UP)
	{
		CAMD = (t_vec){CAMD.x + 5.0 * R3.x, CAMD.y + 5.0 * R3.y, \
		CAMD.z + 5.0 * R3.z};
		CAMO = (t_vec){CAMX + 5.0 * R3.x, CAMY + 5.0 * R3.y, CAMZ - 5.0 * R3.z};
	}
	else if (key == DOWN)
	{
		CAMD = (t_vec){CAMD.x - 5.0 * R3.x, CAMD.y - 5.0 * R3.y, \
		CAMD.z - 5.0 * R3.z};
		CAMO = (t_vec){CAMX - 5.0 * R3.x, CAMY - 5.0 * R3.y, \
		CAMZ - 5.0 * R3.z};
	}
}
