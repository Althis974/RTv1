/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_light_get.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 16:19:43 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/12 16:45:03 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Getting features of light
*/

void	ft_get_light(t_env *rt, t_vec *pos)
{
	ft_set_normal(rt, pos);
	ft_get_shade(rt, pos);
	ft_get_diffuse(rt, pos);
	ft_get_specular(rt, pos);
	rt->light.lite = ft_vmulx(&rt->light.lite, rt->light.shade);
	rt->light.spec = ft_vmul(&rt->light.spec, &rt->light.lite);
	rt->col = ft_vadd(&rt->col, &rt->light.spec);
	ft_vreg(&rt->col, 0.0, 1.0);
	rt->col = ft_vmul(&rt->col, &rt->light.lite);
}

/*
**	Getting color of the object itself under pure white light
*/

void	ft_get_diffuse(t_env *rt, t_vec *pos)
{
	t_vec	tmp;
	t_obj	*obj;

	obj = rt->cur;
	rt->light.lite = (t_vec){0.0, 0.0, 0.0};
	while (obj)
	{
		if (obj->type == 4)
		{
			tmp = ft_lambert(obj, pos, &rt->light.normal);
			rt->light.lite = ft_vadd(&rt->light.lite, &tmp);
		}
		obj = obj->next;
	}
	rt->light.lite = ft_vmulx(&rt->light.lite, 1.0);
	ft_vreg(&rt->light.lite, 0.0, 1.0);
}

/*
**	Getting color of the light of a specular reflection
*/

void	ft_get_specular(t_env *rt, t_vec *pos)
{
	t_obj	*obj;

	obj = rt->cur;
	rt->light.spec = (t_vec){0.0, 0.0, 0.0};
	while (obj)
	{
		if (obj->type == 4)
			rt->light.spec = ft_vaddx(&rt->light.spec, ft_phong(rt, obj, pos));
		obj = obj->next;
	}
	ft_vreg(&rt->light.spec, 0.0, 1.0);
}
