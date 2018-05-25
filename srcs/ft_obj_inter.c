/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_obj_inter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 16:17:15 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/24 10:29:43 by rlossy      ###    #+. /#+    ###.fr     */
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

double	ft_intercylinder(t_env *rt, t_obj *obj)
{
	t_vec	center;
	double	a;
	double	b;
	double	c;
	double	d;

	center = ft_vsub(&rt->ray.ori, &obj->pos);
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
