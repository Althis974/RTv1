/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_shade_inter.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 11:25:12 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 11:10:20 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Return distance traveled by the ray before a shadow intersection
**	in case of a sphere
*/

int		ft_shadsphere(t_obj *obj, t_vec *ray_ori, t_vec *ray_dir, double len)
{
	t_vec	center;
	double	a;
	double	b;
	double	c;
	double	d;

	center = ft_vsub(ray_ori, &obj->pos);
	a = ft_vdot(ray_dir, ray_dir);
	b = ft_vdot(&center, ray_dir);
	c = ft_vdot(&center, &center) - obj->size * obj->size;
	d = b * b - a * c;
	if (d > 0.001)
	{
		d = (-b - sqrt(d)) / a;
		return ((d > 0.001) && (d < len));
	}
	return (0);
}

double	ft_inter_sphere(t_env *rt, t_obj *tmp, t_vec ray, t_vec pos)
{
	double disc;

	rt->di = ft_vsub(&pos, &tmp->pos);
	rt->a = ft_vdot(&ray, &ray);
	rt->b = 2 * ft_vdot(&ray, &rt->di);
	rt->c = ft_vdot(&rt->di, &rt->di) - (tmp->size * tmp->size);
	disc = rt->b * rt->b - 4 * rt->a * rt->c;
	if (disc < 0)
		return (-1);
	rt->t0 = (-rt->b + sqrtf(disc)) / (2 * rt->a);
	rt->t1 = (-rt->b - sqrtf(disc)) / (2 * rt->a);
	if (rt->t0 > rt->t1)
		rt->t0 = rt->t1;
	return (rt->t0);
}

/*
**	Return distance traveled by the ray before a shadow intersection
**	in case of a cylinder
*/

int		ft_shadcylinder(t_obj *obj, t_vec *ray_ori, t_vec *ray_dir, double len)
{
	t_vec	center;
	double	a;
	double	b;
	double	c;
	double	d;

	center = ft_vsub(ray_ori, &obj->pos);
	a = ray_dir->x * ray_dir->x + ray_dir->z * ray_dir->z;
	b = ray_dir->x * center.x + ray_dir->z * center.z;
	c = center.x * center.x + center.z * center.z - obj->size * obj->size;
	d = b * b - a * c;
	if (d > 0.001)
	{
		d = (-b - sqrt(d)) / a;
		return ((d > 0.001) && (d < len));
	}
	return (0);
}

/*
**	Return distance traveled by the ray before a shadow intersection
**	in case of a cone
*/

int		ft_shadcone(t_obj *obj, t_vec *ray_ori, t_vec *ray_dir, double len)
{
	t_vec	center;
	double	a;
	double	b;
	double	c;
	double	d;

	center = ft_vsub(ray_ori, &obj->pos);
	a = ray_dir->x * ray_dir->x - ray_dir->y * ray_dir->y + ray_dir->z * \
	ray_dir->z;
	b = ray_dir->x * center.x - ray_dir->y * center.y + ray_dir->z * center.z;
	c = center.x * center.x + center.z * center.z - center.y * center.y;
	d = b * b - a * c;
	if (d > 0.001)
	{
		d = (-b - sqrt(d)) / a;
		return ((d > 0.001) && (d < len));
	}
	return (0);
}
