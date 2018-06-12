/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_shade_inter.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 11:25:12 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/12 14:32:54 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Return distance traveled by the ray before a shadow intersection
**	in case of a plane
*/

double	ft_shadplane(t_env *rt, t_obj *obj, t_vec ray, t_vec pos)
{
	rt->t1 = ((ft_vdot(&obj->rot, &obj->pos) - ft_vdot(&obj->rot, &pos)) / \
	ft_vdot(&obj->rot, &ray));
	if (rt->t1 < 0.001)
		return (-1.0);
	return (rt->t1);
}

/*
**	Return distance traveled by the ray before a shadow intersection
**	in case of a sphere
*/

double	ft_shadsphere(t_env *rt, t_obj *obj, t_vec ray, t_vec pos)
{
	t_vec	center;
	double	a;
	double	b;
	double	c;
	double	d;

	center = ft_vsub(&pos, &obj->pos);
	a = ft_vdot(&ray, &ray);
	b = 2 * ft_vdot(&ray, &center);
	c = ft_vdot(&center, &center) - (obj->size * obj->size);
	d = b * b - 4 * a * c;
	if (d < 0.0)
		return (-1.0);
	rt->t1 = (-b + sqrtf(d)) / (2 * a);
	rt->t2 = (-b - sqrtf(d)) / (2 * a);
	if (rt->t1 > rt->t2)
		rt->t1 = rt->t2;
	return (rt->t1);
}

/*
**	Return distance traveled by the ray before a shadow intersection
**	in case of a cylinder
*/

double	ft_shadcylindr(t_env *rt, t_obj *obj, t_vec ray, t_vec pos)
{
	double	a;
	double	b;
	double	c;
	double	d;

	rt->center = ft_vsub(&pos, &obj->pos);
	ft_vnorm(&obj->rot);
	a = ft_vdot(&ray, &ray) - pow(ft_vdot(&ray, &obj->rot), 2);
	b = 2 * (ft_vdot(&ray, &rt->center) - (ft_vdot(&ray, &obj->rot) * \
	ft_vdot(&rt->center, &obj->rot)));
	c = ft_vdot(&rt->center, &rt->center) - pow(ft_vdot(&rt->center, \
	&obj->rot), 2) - pow(obj->size, 2);
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	rt->t1 = (-b + sqrtf(d)) / (2 * a);
	rt->t2 = (-b - sqrtf(d)) / (2 * a);
	if (rt->t1 > rt->t2)
		rt->t1 = rt->t2;
	return (rt->t1);
}

/*
**	Return distance traveled by the ray before a shadow intersection
**	in case of a cone
*/

double	ft_shadcone(t_env *rt, t_obj *obj, t_vec ray, t_vec pos)
{
	double	a;
	double	b;
	double	c;
	double	d;

	rt->center = ft_vsub(&pos, &obj->pos);
	ft_vnorm(&obj->rot);
	a = ft_vdot(&ray, &ray) - (1 + pow(obj->size, 2)) * \
	pow(ft_vdot(&ray, &obj->rot), 2);
	b = 2 * (ft_vdot(&ray, &rt->center) - (1 + pow(obj->size, 2)) * \
	ft_vdot(&ray, &obj->rot) * ft_vdot(&rt->center, &obj->rot));
	c = ft_vdot(&rt->center, &rt->center) - (1 + pow(obj->size, 2)) * \
	pow(ft_vdot(&rt->center, &obj->rot), 2);
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	rt->t1 = (-b + sqrtf(d)) / (2 * a);
	rt->t2 = (-b - sqrtf(d)) / (2 * a);
	if (rt->t1 > rt->t2)
		rt->t1 = rt->t2;
	return (rt->t1);
}
