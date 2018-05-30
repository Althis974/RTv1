/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_obj_inter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 16:17:15 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/30 17:20:00 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Return distance traveled by the ray before an object intersection
**	in case of a plane
*/
/*
double	ft_interplane(t_env *rt, t_obj *obj, t_vec ray, t_vec pos)
{
	double t0;

	rt->aa = 1.0;
	t0 = ((ft_vdot(&obj->rot, &obj->pos) -
				ft_vdot(&obj->rot, &pos)) / ft_vdot(&obj->rot, &ray));
	if (t0 < 0.0001)
		return (-1);
	return (t0);
}*/

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
/*
double	ft_intercylinder(t_env *rt, t_obj *obj, t_vec ray, t_vec pos)
{
	double a;
	double b;
	double c;
	double d;
	double t0;
	double t1;
	t_vec	center;

	rt->aa = 1.0;
	center = ft_vsub(&pos, &obj->pos);
	ft_vnorm(&obj->rot);
	a = ft_vdot(&ray, &ray) - pow(ft_vdot(&ray, &obj->rot), 2);
	b = 2 * (ft_vdot(&ray, &center) -
				  (ft_vdot(&ray, &obj->rot) * ft_vdot(&center, &obj->rot)));
	c = ft_vdot(&center, &center) -
			 pow(ft_vdot(&center, &obj->rot), 2) - pow(obj->size, 2);
	d = b * b - 4 * a * c;
	if (d < 0.0)
		return (-1.0);
	t0 = (-b + sqrtf(d)) / (2 * a);
	t1 = (-b - sqrtf(d)) / (2 * a);
	if (t0 > t1)
		t0 = t1;
	return (t0);
}*/


double	ft_intercylinder(t_env *rt, t_obj *obj)
{
	t_vec	center;
	double	a;
	double	b;
	double	c;
	double	d;

	center = ft_vsub(&rt->ray.ori, &obj->pos);
	ft_vnorm(&obj->rot);
	a = rt->ray.dir.x * rt->ray.dir.x + rt->ray.dir.z * rt->ray.dir.z;
	b = (rt->ray.dir.x * center.x + rt->ray.dir.z * center.z);
	c = center.x * center.x + center.z * center.z - obj->size * obj->size;
	d = b * b - a * c;
	if (d < 0.001)
		return (-1.0);
	return ((-b - sqrt(d)) / a);
}

/*
**	Return distance traveled by the ray before an object intersection
**	in case of a cone
*/

double	ft_intercone(t_env *rt, t_obj *obj)
{
	t_vec	center;
	double	a;
	double	b;
	double	c;
	double	d;

	center = ft_vsub(&rt->ray.ori, &obj->pos);
	a = rt->ray.dir.x * rt->ray.dir.x - rt->ray.dir.y * rt->ray.dir.y \
		+ rt->ray.dir.z * rt->ray.dir.z;
	b = rt->ray.dir.x * center.x - rt->ray.dir.y * center.y + rt->ray.dir.z \
		* center.z;
	c = center.x * center.x + center.z * center.z - center.y * center.y;
	d = b * b - a * c;
	if (d < 0.001)
		return (-1.0);
	return ((-b - sqrt(d)) / a);
}
