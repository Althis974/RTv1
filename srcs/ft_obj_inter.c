/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_obj_inter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 16:17:15 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 11:56:44 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Return distance traveled by the ray before an object intersection
**	in case of a plane
*/

double	ft_inter_plane(t_env *rt, t_obj *tmp, t_vec ray, t_vec pos)
{
	rt->t0 = ((ft_vdot(&tmp->rot, &tmp->pos) -
				ft_vdot(&tmp->rot, &pos)) / ft_vdot(&tmp->rot, &ray));
	if (rt->t0 < 0.0001)
		return (-1);
	return (rt->t0);
}

double	ft_interplane(t_env *rt, t_obj *obj)
{
	double	t;

	t = -((ft_vdot(&obj->rot, &rt->ray.ori) - \
	ft_vdot(&obj->rot, &obj->pos)) / ft_vdot(&obj->rot, &rt->ray.dir));
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

double	ft_inter_cylinder(t_env *rt, t_obj *tmp, t_vec ray, t_vec pos)
{
	double disc;

	rt->di = ft_vsub(&pos, &tmp->pos);
	ft_vnorm(&tmp->rot);
	rt->a = ft_vdot(&ray, &ray) - pow(ft_vdot(&ray, &tmp->rot), 2);
	rt->b = 2 * (ft_vdot(&ray, &rt->di) - (ft_vdot(&ray, &tmp->rot) * ft_vdot(&rt->di, &tmp->rot)));
	rt->c = ft_vdot(&rt->di, &rt->di) - pow(ft_vdot(&rt->di, &tmp->rot), 2) - pow(tmp->size, 2);
	disc = rt->b * rt->b - 4 * rt->a * rt->c;
	if (disc < 0)
		return (-1);
	rt->t0 = (-rt->b + sqrtf(disc)) / (2 * rt->a);
	rt->t1 = (-rt->b - sqrtf(disc)) / (2 * rt->a);
	if (rt->t0 > rt->t1)
		rt->t0 = rt->t1;
	return (rt->t0);
}


double	ft_intercylinder(t_env *rt, t_obj *obj)
{
//	t_vec	center;
	double	a;
	double	b;
	double	c;
	double	d;

//	center = ft_vsub(&rt->ray.ori, &obj->pos);
	rt->di = ft_vsub(&rt->ray.ori, &obj->pos);
	ft_vnorm(&obj->rot);
	//a = rt->ray.dir.x * rt->ray.dir.x + rt->ray.dir.z * rt->ray.dir.z;
	a = ft_vdot(&rt->ray.dir, &rt->ray.dir) - pow(ft_vdot(&rt->ray.dir, &obj->rot), 2);
	//b = (rt->ray.dir.x * center.x + rt->ray.dir.z * center.z);
	b = 2 * (ft_vdot(&rt->ray.dir, &rt->di) -
				 (ft_vdot(&rt->ray.dir, &obj->rot) * ft_vdot(&rt->di, &obj->rot)));
	//c = center.x * center.x + center.z * center.z - obj->size * obj->size;
	c = ft_vdot(&rt->di, &rt->di) -
			pow(ft_vdot(&rt->di, &obj->rot), 2) - pow(obj->size, 2);
	d = b * b - 4 * a * c;
	if (d < 0.001)
		return (-1.0);
	rt->t0 = (-b + sqrtf(d)) / (2 * a);
	rt->t1 = (-b - sqrtf(d)) / (2 * a);
	if (rt->t0 > rt->t1)
		rt->t0 = rt->t1;
	return (rt->t0);
//	return ((-b - sqrt(d)) / a);
}

/*
**	Return distance traveled by the ray before an object intersection
**	in case of a cone
*/

double	ft_intercone(t_env *rt, t_obj *obj)
{
//	t_vec	center;
	double	a;
	double	b;
	double	c;
	double	d;

//	center = ft_vsub(&rt->ray.ori, &obj->pos);
	rt->di = ft_vsub(&rt->ray.ori, &obj->pos);
	ft_vnorm(&obj->rot);
//	a = rt->ray.dir.x * rt->ray.dir.x - rt->ray.dir.y * rt->ray.dir.y \
//		+ rt->ray.dir.z * rt->ray.dir.z;
	a = ft_vdot(&rt->ray.dir, &rt->ray.dir) - (1 + pow(tan(obj->size), 2)) *
							  pow(ft_vdot(&rt->ray.dir, &obj->rot), 2);
//	b = rt->ray.dir.x * center.x - rt->ray.dir.y * center.y + rt->ray.dir.z \
//		* center.z;
	b = 2 * (ft_vdot(&rt->ray.dir, &rt->di) - (1 + pow(tan(obj->size), 2))
									  * ft_vdot(&rt->ray.dir, &obj->rot) * ft_vdot(&rt->di, &obj->rot));
//	c = center.x * center.x + center.z * center.z - center.y * center.y;
	c = ft_vdot(&rt->di, &rt->di) - (1 +
									 pow(tan(obj->size), 2)) * pow(ft_vdot(&rt->di, &obj->rot), 2);
	d = b * b - 4 * a * c;
	if (d < 0.001)
		return (-1.0);
	rt->t0 = (-b + sqrtf(d)) / (2 * a);
	rt->t1 = (-b - sqrtf(d)) / (2 * a);
	if (rt->t0 > rt->t1)
		rt->t0 = rt->t1;
	return (rt->t0);
//	return ((-b - sqrt(d)) / a);
}

double	ft_inter_cone(t_env *rt, t_obj *tmp, t_vec ray, t_vec pos)
{
	double	disc;

	rt->di = ft_vsub(&pos, &tmp->pos);
	ft_vnorm(&tmp->rot);
	rt->a = ft_vdot(&ray, &ray) - (1 + pow(tmp->size, 2)) * pow(ft_vdot(&ray, &tmp->rot), 2);
	rt->b = 2 * (ft_vdot(&ray, &rt->di) - (1 + pow(tmp->size, 2)) * ft_vdot(&ray, &tmp->rot) * ft_vdot(&rt->di, &tmp->rot));
	rt->c = ft_vdot(&rt->di, &rt->di) - (1 + pow(tmp->size, 2)) * pow(ft_vdot(&rt->di, &tmp->rot), 2);
	disc = rt->b * rt->b - 4 * rt->a * rt->c;
	if (disc < 0)
		return (-1);
	rt->t0 = (-rt->b + sqrtf(disc)) / (2 * rt->a);
	rt->t1 = (-rt->b - sqrtf(disc)) / (2 * rt->a);
	if (rt->t0 > rt->t1)
		rt->t0 = rt->t1;
	return (rt->t0);
}
