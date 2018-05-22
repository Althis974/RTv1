/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trace.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:26:27 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/22 14:50:52 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Tracing
*/

int		ft_trace(t_env *rt, int part)
{
	int		x;
	int		y;
	int		stop;
	int		start;

	start = (MAX_H / THREADS) * part;
	stop = (MAX_H / THREADS) * (part + 1);
	y = start - 1;
	while (++y < stop)
	{
		x = -1;
		while (++x < MAX_W)
		{
			rt->col = (t_vec){0.0, 0.0, 0.0};
			ft_set_cam(rt, x, y);
			ft_get_obj_col(rt);
			ft_set_pixel(rt, x, y, (((int)(rt->col.x * 255) & 0xff) << 16) + \
			(((int)(rt->col.y * 255) & 0xff) << 8) + ((int)(rt->col.z * 255) & \
			0xff));
		}
	}
	return (0);
}
