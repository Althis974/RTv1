/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trace.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:26:27 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/25 13:10:10 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Tracing
*/

void	*ft_trace(void *th)
{
	t_env		*rt;
	double		x;
	double		y;
	double		stop;
	double		start;

	rt = (t_env *)th;
	start = (MAX_H / THREADS) * rt->th;
	stop = (MAX_H / THREADS) * (rt->th + 1);
	y = start - 1.0;
	while (++y < stop)
	{
		x = -1.0;
		while (++x < MAX_W)
		{
			rt->col = (t_vec) {0.0, 0.0, 0.0};
			ft_set_cam(rt, x, y);
			ft_get_obj_col(rt);
			ft_set_pixel(rt, x, y, (((int)(rt->col.x * 255) & 0xff) << 16) + \
			(((int)(rt->col.y * 255) & 0xff) << 8) + ((int)(rt->col.z * 255) & \
			0xff));
		}
	}
	return (NULL);
}
