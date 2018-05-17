/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/14 14:55:20 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 16:28:52 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Setting camera
*/

void	ft_set_cam(t_env *rt, double x, double y)
{
	double	u;
	double	v;
	t_vec	v1;
	t_vec	v2;
	t_vec	v3;

	u = (MAX_W - x * FOV) / MAX_H;
	v = (MAX_H - y * FOV) / MAX_H;
	v1 = ft_vsub(&rt->cam.dir, &rt->cam.ori);
	ft_vnorm(&v1);
	v2 = ft_vcross(&v1, &(t_vec){0.0, 1.0, 0.0});
	ft_vnorm(&v2);
	v3 = ft_vcross(&v2, &v1);
	rt->ray.dir = (t_vec){u * v2.x + v * v3.x + FOV * v1.x, u * v2.y + v * \
		v3.y + FOV * v1.y, u * v2.z + v * v3.z + FOV * v1.z};
	rt->ray.ori = rt->cam.ori;
//	rt->objs = NULL;
}

/*
**	Setting normal at the point of intersection
*/

t_vec	ft_set_normal(t_obj *obj, t_vec *pos)
{
	t_vec	normal;

	normal = (t_vec){0.0, 1.0, 0.0};
	if (obj->type == 1)
		normal = ft_vsub(pos, &obj->pos);
	else if (obj->type == 2 || obj->type == 3)
		normal = (t_vec){pos->x - obj->pos.x, 0.0, pos->z - obj->pos.z};
	ft_vnorm(&normal);
	return (normal);
}

/*
**	Setting pixel on mlx image
*/

void	ft_set_pixel(t_env *rt, int x, int y)
{
	int		r;
	int		g;
	int		b;

	r = (int)(rt->col.x * 256) % 256;
	g = ((int)(rt->col.y * 256) % 256) * 256;
	b = ((int)(rt->col.z * 256) % 256) * 256 * 256;
	if (y >= 0 && x >= 0 && y < MAX_H && x < MAX_W)
	{
		rt->mlx.img.data[(y * rt->mlx.img.size_l)
						+ ((rt->mlx.img.bpp / 8) * x) + 2] = (char)r;
		rt->mlx.img.data[(y * rt->mlx.img.size_l)
						+ ((rt->mlx.img.bpp / 8) * x) + 1] = (char)g;
		rt->mlx.img.data[(y * rt->mlx.img.size_l)
						+ ((rt->mlx.img.bpp / 8) * x)] = (char)b;
	}
}
