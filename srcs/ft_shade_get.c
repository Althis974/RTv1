/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_shade_get.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 11:24:26 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/30 14:10:16 by rlossy      ###    #+. /#+    ###.fr     */
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
			tmp = ft_get_shade_inter(rt, pos, &obj->pos);
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
/*
double	ft_get_shade_inter(t_env *rt, t_vec *pos, t_vec *objpos)
{
	double	tmp;
	double	shade;
	t_vec	lite;
	t_obj	*objs;
//	double	len;

	tmp = 0;
	objs = rt->cur;
//	len = ft_vlen(&lite);
	lite = ft_vsub(objpos, pos);
	shade = sqrtf(ft_vdot(&lite, &lite));
	ft_vnorm(&lite);
	while (objs)
	{
		if (objs->type == 0)
			tmp = ft_interplane(rt, objs, lite, *pos);
//		else if (objs->type == 1)
//			tmp = ft_shadsphere(objs, pos, &lite, len);
		else if (objs->type == 2)
			tmp = ft_intercylinder(rt, objs, lite, *pos);
//		else if (objs->type == 3)
//			tmp = ft_shadcone(objs, pos, &lite, len);
		if (tmp > 0.0001  && tmp < shade)
			return (1);
		objs = objs->next;
	}
	return (0);
}*/

double	ft_get_shade_inter(t_env *rt, t_vec *pos, t_vec *objpos)
{
	int		tmp;
	int		shade;
	t_vec	lite;
	t_obj	*objs;
	double	len;

	tmp = 0;
	shade = 0;
	objs = rt->cur;
	lite = ft_vsub(objpos, pos);
	len = ft_vlen(&lite);
	lite = ft_vdivx(&lite, len);
	while (objs)
	{
		if (objs->type == 1)
			tmp = ft_shadsphere(objs, pos, &lite, len);
		else if (objs->type == 2)
			tmp = ft_shadcylinder(objs, pos, &lite, len);
		else if (objs->type == 3)
			tmp = ft_shadcone(objs, pos, &lite, len);
		shade = (tmp == 1 ? 1 : shade);
		objs = objs->next;
	}
	return (shade);
}
