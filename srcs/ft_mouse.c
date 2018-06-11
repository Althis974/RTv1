/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mouse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 12:49:34 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/11 14:01:39 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Events mouse
*/

int		ft_mouse(int button, int x, int y, t_env *rt)
{
	R1 = ft_vsub(&rt->cam.dir, &rt->cam.ori);
	ft_vnorm(&R1);
	if ((button == 1 || button == 4) && (x >= 0 && x <= MAX_H)
		&& (y >= 0 && y <= MAX_W))
	{
		rt->zoom += 1;
		CAMD = (t_vec){CAMD.x + 5.0 * R1.x, CAMD.y + 5.0 * R1.y, \
		CAMD.z + 5.0 * R1.z};
		CAMO = (t_vec){CAMX + 5.0 * R1.x, CAMY + 5.0 * R1.y, CAMZ + 5.0 * R1.z};
	}
	else if ((button == 2 || button == 5) && (x >= 0 && x <= MAX_H)
			&& (y >= 0 && y <= MAX_W) && rt->zoom)
	{
		rt->zoom -= 1;
		CAMD = (t_vec){CAMD.x - 5.0 * R1.x, CAMD.y - 5.0 * R1.y, \
		CAMD.z - 5.0 * R1.z};
		CAMO = (t_vec){CAMX - 5.0 * R1.x, CAMY - 5.0 * R1.y, CAMZ - 5.0 * R1.z};
	}
	ft_launch(rt);
	return (0);
}
