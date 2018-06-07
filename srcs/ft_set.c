/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/14 14:55:20 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 12:22:11 by rlossy      ###    #+. /#+    ###.fr     */
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
}

/*
**	Setting normal at the point of intersection
*/

void	ft_set_normal(t_env *rt, t_vec *pos)
{
	t_vec	temp;
	t_vec	temp2;

	rt->light.normal = (t_vec){0.0, 1.0, 0.0};
	if (rt->objs->type == 1)
		rt->light.normal = ft_vsub(pos, &rt->objs->pos);
	else if (rt->objs->type == 2 || rt->objs->type == 3)
//		rt->light.normal = (t_vec){pos->x - rt->objs->pos.x, 0.0, pos->z - \
//		rt->objs->pos.z};
//	else if (rt->objs->type == 2 || rt->objs->type == 3)
//		rt->light.normal = find_cylinder_normal(rt, rt->objs);
//	else if (rt->objs->type == 3)
//		rt->light.normal = find_cone_normal(rt, rt->objs);
	{
		temp = ft_vmulx(&rt->objs->rot,
							  (ft_vdot(&rt->ray.dir, &rt->objs->rot) * rt->t0
							   + ft_vdot(&rt->di, &rt->objs->rot)));
		if (rt->objs->type == 3)
			temp = ft_vmulx(&temp, (1 + pow(tan(rt->objs->size), 2)));
		temp2 = ft_vsub(pos, &rt->objs->pos);
		rt->light.normal = ft_vsub(&temp2, &temp);
	}
	ft_vnorm(&rt->light.normal);
}

/*
**	Setting pixel on mlx image
*/

void	ft_set_pixel(t_env *rt, int x, int y, int color)
{
	int	i;
	int	p;

	i = 0;
	p = (x * ((rt->mlx.img.bpp / 8)) + y * (rt->mlx.img.size_l));
	while (i < (rt->mlx.img.bpp / 8))
	{
		rt->mlx.img.data[p + i] = (char)color;
		color >>= 8;
		i++;
	}
}
