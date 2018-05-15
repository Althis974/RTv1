/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_inter.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 10:39:06 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 11:10:02 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double	ft_interplane(t_obj *obj, t_env *rt)
{
	double	t;

	t = -((ft_vpoint(&obj->rot, &rt->rot.ori) - ft_vpoint(&obj->rot, &obj->pos))\
 / ft_vpoint(&obj->rot, &rt->rot.dir));
	if (t < 0.0001)
		return (-1.0);
	return (t);
}

double	ft_intersphere(t_obj *obj, t_env *rt)
{
	t_vec	center;
	double	a;
	double	b;
	double	c;
	double	h;

	center = ft_vsub(&rt->rot.ori, &obj->pos);
	a = ft_vpoint(&rt->rot.dir, &rt->rot.dir);
	b = ft_vpoint(&center, &rt->rot.dir);
	c = ft_vpoint(&center, &center) - obj->size * obj->size;
	h = b * b - a * c;
	if (h < 0.0001)
		return (-1.0);
	return ((-b - sqrt(h)) / a);
}

double	ft_intercylinder(t_obj *obj, t_env *rt)
{
	t_vec	center;
	double	a;
	double	b;
	double	c;
	double	h;

	center = ft_vsub(&rt->rot.ori, &obj->pos);
	a = rt->rot.dir.x * rt->rot.dir.x + rt->rot.dir.z * rt->rot.dir.z;
	b = (rt->rot.dir.x * center.x + rt->rot.dir.z * center.z);
	c = center.x * center.x + center.z * center.z - obj->size * obj->size;
	h = b * b - a * c;
	if (h < 0.0001)
		return (-1.0);
	return ((-b - sqrt(h)) / a);
}

double	ft_intercone(t_obj *obj, t_env *rt)
{
	t_vec	center;
	double	a;
	double	b;
	double	c;
	double	h;

	center = ft_vsub(&rt->rot.ori, &obj->pos);
	a = rt->rot.dir.x * rt->rot.dir.x - rt->rot.dir.y * rt->rot.dir.y \
 + rt->rot.dir.z * rt->rot.dir.z;
	b = rt->rot.dir.x * center.x - rt->rot.dir.y * center.y + rt->rot.dir.z \
 * center.z;
	c = center.x * center.x + center.z * center.z - center.y * center.y;
	h = b * b - a * c;
	if (h < 0.0001)
		return (-1.0);
	return ((-b - sqrt(h)) / a);
}
