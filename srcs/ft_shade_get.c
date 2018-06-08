/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_shade_get.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 11:24:26 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/08 15:28:58 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Getting distance traveled by the ray before shadow intersection
*/

void	ft_get_shade(t_env *rt, t_vec *pos)
{
	t_obj	*obj;
	double	tmp;

	obj = rt->cur;
	rt->light.shade = 1.0;
	while (obj)
	{
		if (obj->type == 4)
		{
			tmp = ft_get_shade_inter(rt, obj, *pos);
			if (tmp == 1)
				rt->light.shade -= (obj->pow + rt->nb_spot) / FOV;
		}
		obj = obj->next;
	}
	ft_reg(rt->light.shade, 0.0, 1.0);
}

/*
**	Getting distance traveled by the ray before shade intersection
*/

int		ft_get_shade_inter(t_env *rt, t_obj *light, t_vec pos)
{
	t_vec	ray;
	t_obj	*objs;
	double	tmp;

	tmp = 0.0;
	objs = rt->cur;
	ray = ft_vsub(&light->pos, &pos);
	rt->dist = sqrtf(ft_vdot(&ray, &ray));
	ft_vnorm(&ray);
	while (objs)
	{
		if (objs != rt->cur)
		{
			tmp = ft_intershade(rt, objs, ray, pos);
			if (tmp > 0.001 && tmp < rt->dist)
				return (1);
		}
		objs = objs->next;
	}
	return (0);
}

double	ft_intershade(t_env *rt, t_obj *objs, t_vec ray, t_vec pos)
{
	double	tmp;

	tmp = 0.0;
	if (objs->type == 0)
		tmp = ft_shadplane(rt, objs, ray, pos);
	else if (objs->type == 1)
		tmp = ft_shadsphere(rt, objs, ray, pos);
	else if (objs->type == 2)
		tmp = ft_shadcylindr(rt, objs, ray, pos);
	else if (objs->type == 3)
		tmp = ft_shadcone(rt, objs, ray, pos);
	return (tmp);
}
