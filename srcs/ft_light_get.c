/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_light_get.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 16:19:43 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/16 16:58:25 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Getting features of light
*/

void	ft_get_light(t_env *rt, t_vec *pos)
{
	rt->light.normal = ft_set_normal(rt->objs, pos);
	rt->light.shade = ft_get_shade(rt, pos);
	rt->light.lite = ft_get_diffuse(rt, pos);
	rt->light.spec = ft_get_specular(rt, pos);
	rt->light.lite = ft_vmulx(&rt->light.lite, rt->light.shade);
	rt->light.spec = ft_vmul(&rt->light.spec, &rt->light.lite);
	rt->col = ft_vadd(&rt->col, &rt->light.spec);
	ft_vreg(&rt->col, 0.0, 1.0);
	rt->col = ft_vmul(&rt->col, &rt->light.lite);
}

/*
**	Getting distance traveled by the ray before shadow intersection
*/

double	ft_get_shade(t_env *rt, t_vec *pos)
{
	t_obj	*obj;
	double	shade;
	double	tmp;

	obj = rt->cur;
	shade = 1.0;
	while (obj)
	{
		if (obj->type == 4)
		{
			tmp = ft_get_shade_inter(rt, pos, &obj->pos);
			if (tmp == 1)
				shade -= (obj->pow + rt->nb_spot) / FOV;
		}
		obj = obj->next;
	}
	return (ft_reg(shade, 0.0, 1.0));
}

/*
**	Getting color of the object itself under pure white light
*/

t_vec	ft_get_diffuse(t_env *rt, t_vec *pos)
{
	t_obj	*obj;
	t_vec	lite;
	t_vec	tmp;

	obj = rt->cur;
	lite = (t_vec){0.0, 0.0, 0.0};
	while (obj)
	{
		if (obj->type == 4)
		{
			tmp = ft_lambert(obj, &rt->light.normal, pos);
			lite = ft_vadd(&lite, &tmp);
		}
		obj = obj->next;
	}
	lite = ft_vmulx(&lite, rt->nb_spot);
	ft_vreg(&lite, 0.0, 1.0);
	return (lite);
}

/*
**	Getting color of the light of a specular reflection
*/

t_vec	ft_get_specular(t_env *rt, t_vec *pos)
{
	t_obj	*obj;
	t_vec	spec;

	obj = rt->cur;
	spec = (t_vec){0.0, 0.0, 0.0};
	while (obj)
	{
		if (obj->type == 4)
			spec = ft_vaddx(&spec, ft_phong(obj, &rt->light.normal, \
			&rt->rot.dir, pos));
		obj = obj->next;
	}
	ft_vreg(&spec, 0.0, 1.0);
	return (spec);
}
