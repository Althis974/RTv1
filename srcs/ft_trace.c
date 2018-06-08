/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trace.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:26:27 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/08 09:31:17 by rlossy      ###    #+. /#+    ###.fr     */
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

	rt = (t_env *)th;
	y = 0.0;
	while (y < MAX_H)
	{
		x = MAX_W * rt->th / THREADS;
		while (x < MAX_W * (rt->th + 1) / THREADS)
		{
			rt->aax = (int)x;
			rt->aay = (int)y;
			ft_aa(rt, x, y);
			x++;
		}
		y++;
	}
	return (NULL);
}

/*
**	Implementing Anti-Aliasing
*/

void	ft_aa(t_env *rt, double x, double y)
{
	double	p;

	p = 0.0;
	ft_bzero(&rt->rgb, sizeof(t_vec));
	while (y < rt->aay + 1 && (x = rt->aax) > -1)
	{
		while (x < rt->aax + 1 && (p += 1) > 0)
		{
			rt->col = (t_vec) {0.0, 0.0, 0.0};
			ft_set_cam(rt, x, y);
			ft_get_obj_col(rt);
			rt->col.x = pow(rt->col.x, 1.0);
			rt->col.y = pow(rt->col.y, 1.0);
			rt->col.z = pow(rt->col.z, 1.0);
			rt->rgb.x += ft_reg(rt->col.x, 0.0, 1.0);
			rt->rgb.y += ft_reg(rt->col.y, 0.0, 1.0);
			rt->rgb.z += ft_reg(rt->col.z, 0.0, 1.0);
			x += (1.0 / rt->aa);
		}
		y = y + (1.0 / rt->aa);
	}
	ft_set_pixel(rt, rt->aax, rt->aay, (((int)(rt->rgb.x / p * 255) & 0xff)
			<< 16) + (((int)(rt->rgb.y / p * 255) & 0xff) << 8) +
			((int)(rt->rgb.z / p * 255) & 0xff));
}
