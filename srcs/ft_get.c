/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 14:25:50 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/14 16:50:27 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Getting object color
*/

void	ft_get_obj_col(t_env *rt)
{
	t_vec	pos;

	rt->dist = 10000.0;
	rt->objs = ft_get_obj_inter(rt);
	if (rt->dist > 0.0001 && rt->objs)
	{
		rt->col = (t_col){rt->objs->col.red, rt->objs->col.green, \
		rt->objs->col.blue};
		if (rt->dist < 10000.0)
		{
			pos = (t_vec){rt->rot.ori.x + rt->dist * rt->rot.dir.x, \
			rt->rot.ori.y + rt->dist * rt->rot.dir.y, rt->rot.ori.z + \
			rt->dist * rt->rot.dir.z};
			ft_get_lite(rt, &pos);
		}
	}
}

/*
**	Getting distance traveled by the ray
*/

t_obj	*ft_get_obj_inter(t_env *rt)
{
	t_obj	*objs;
	t_obj	*obj;
	double	tmp;

	obj = NULL;
	objs = rt->cur;
	tmp = rt->dist;
	while (objs)
	{
		if (objs->type == 0)
			tmp = ft_interplane(objs, rt);
		else if (objs->type == 1)
			tmp = ft_intersphere(objs, rt);
		else if (objs->type == 2)
			tmp = ft_intercylinder(objs, rt);
		else if (objs->type == 3)
			tmp = ft_intercone(objs, rt);
		if (tmp > 0.0001 && tmp < rt->dist)
		{
			obj = objs;
			rt->dist = tmp;
		}
		objs = objs->next;
	}
	return (obj);
}
