/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_obj_inter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 16:17:15 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/12 14:32:54 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Return distance traveled by the ray before an object intersection
**	in case of a plane
*/

double	ft_interplane(t_env *rt, t_obj *obj)
{
	double	t;

	t = -((ft_vdot(&obj->rot, &rt->ray.ori) - ft_vdot(&obj->rot, &obj->pos)) / \
	ft_vdot(&obj->rot, &rt->ray.dir));
	if (t < 0.001)
		return (-1.0);
	return (t);
}

/*
**	Return distance traveled by the ray before an object intersection
**	in case of a sphere
*/

double	ft_intersphere(t_env *rt, t_obj *obj)
{
	t_vec	center;
	double	a;
	double	b;
	double	c;
	double	d;

	center = ft_vsub(&rt->ray.ori, &obj->pos);
	a = ft_vdot(&rt->ray.dir, &rt->ray.dir);
	b = ft_vdot(&center, &rt->ray.dir);
	c = ft_vdot(&center, &center) - obj->size * obj->size;
	d = b * b - a * c;
	if (d < 0.001)
		return (-1.0);
	return ((-b - sqrt(d)) / a);
}

/*
**	Return distance traveled by the ray before an object intersection
**	in case of a cylinder
*/

double	ft_intercylinder(t_env *rt, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	d;

	rt->center = ft_vsub(&rt->ray.ori, &obj->pos);
	ft_vnorm(&obj->rot);
	a = ft_vdot(&rt->ray.dir, &rt->ray.dir) - pow(ft_vdot(&rt->ray.dir, \
	&obj->rot), 2);
	b = 2 * (ft_vdot(&rt->ray.dir, &rt->center) - \
	(ft_vdot(&rt->ray.dir, &obj->rot) * ft_vdot(&rt->center, &obj->rot)));
	c = ft_vdot(&rt->center, &rt->center) - \
	pow(ft_vdot(&rt->center, &obj->rot), 2) - pow(obj->size, 2);
	d = b * b - 4 * a * c;
	if (d < 0.001)
		return (-1.0);
	rt->t1 = (-b + sqrtf(d)) / (2 * a);
	rt->t2 = (-b - sqrtf(d)) / (2 * a);
	if (rt->t1 > rt->t2)
		rt->t1 = rt->t2;
	return (rt->t1);
}

/*
**	Return distance traveled by the ray before an object intersection
**	in case of a cone
*/

double	ft_intercone(t_env *rt, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	d;

	rt->center = ft_vsub(&rt->ray.ori, &obj->pos);
	ft_vnorm(&obj->rot);
	a = ft_vdot(&rt->ray.dir, &rt->ray.dir) - (1 + pow(tan(obj->size), 2)) * \
	pow(ft_vdot(&rt->ray.dir, &obj->rot), 2);
	b = 2 * (ft_vdot(&rt->ray.dir, &rt->center) - (1 + pow(tan(obj->size), 2)) *
	ft_vdot(&rt->ray.dir, &obj->rot) * ft_vdot(&rt->center, &obj->rot));
	c = ft_vdot(&rt->center, &rt->center) - (1 + \
	pow(tan(obj->size), 2)) * pow(ft_vdot(&rt->center, &obj->rot), 2);
	d = b * b - 4 * a * c;
	if (d < 0.001)
		return (-1.0);
	rt->t1 = (-b + sqrtf(d)) / (2 * a);
	rt->t2 = (-b - sqrtf(d)) / (2 * a);
	if (rt->t1 > rt->t2)
		rt->t1 = rt->t2;
	return (rt->t1);
}
