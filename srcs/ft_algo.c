/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 13:58:26 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 14:59:29 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Translation of Lambert's law
*/

t_vec	ft_lambert(t_obj *obj, t_vec *pos, t_vec *normal)
{
	t_vec	lambert;
	t_vec	lite;
	double	val;
	double	dist;

	dist = ft_vdist(pos, &obj->pos);
	dist = ft_reg(sqrt(1.0 / (dist * (1.0 - obj->pow))), 0.0, 1.0);
	lite = ft_vsub(&obj->pos, pos);
	ft_vnorm(&lite);
	val = ft_reg(ft_vdot(normal, &lite), 0.0, 1.0);
	if (normal->x == 0.0 && normal->y == 1.0 && normal->z == 0.0)
		val = 1.0;
	lambert = ft_vmulx(&obj->col, val);
	lambert = ft_vmulx(&lambert, obj->pow);
	lambert = ft_vmulx(&lambert, dist);
	return (lambert);
}

/*
**	Translation of Phong shading
*/

double	ft_phong(t_obj *obj, t_vec *pos, t_vec *normal, t_vec *ray_dir)
{
	t_vec	reflect;
	t_vec	lite;
	double	phong;

	lite = ft_vsub(&obj->pos, pos);
	ft_vnorm(&lite);
	reflect = ft_vreflect(ray_dir, normal);
	ft_vnorm(&reflect);
	phong = ft_reg(pow(ft_reg(ft_vdot(&reflect, &lite), 0.0, 1.0), 50.0), \
	0.0, 1.0);
	phong *= pow(obj->pow, 0.5);
	return (phong);
}
