/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_obj_get.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 16:18:52 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/08 14:12:55 by rlossy      ###    #+. /#+    ###.fr     */
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

	rt->dist = 1000.0;
	rt->objs = ft_get_obj_inter(rt);
	if (rt->dist > 0.001 && rt->objs)
	{
		rt->col = (t_vec){rt->objs->col.x, rt->objs->col.y, \
		rt->objs->col.z};
		if (rt->dist < 1000.0)
		{
			pos = (t_vec){rt->ray.ori.x + rt->dist * rt->ray.dir.x, \
			rt->ray.ori.y + rt->dist * rt->ray.dir.y, rt->ray.ori.z + \
			rt->dist * rt->ray.dir.z};
			ft_get_light(rt, &pos);
		}
	}
}

/*
**	Getting distance traveled by the ray before object intersection
*/

t_obj	*ft_get_obj_inter(t_env *rt)
{
	t_obj	*cur;
	t_obj	*objs;
	double	tmp;

	objs = NULL;
	cur = rt->cur;
	tmp = rt->dist;
	while (cur)
	{
		if (cur->type == 0)
			tmp = ft_interplane(rt, cur);
		else if (cur->type == 1)
			tmp = ft_intersphere(rt, cur);
		else if (cur->type == 2)
			tmp = ft_intercylinder(rt, cur);
		else if (cur->type == 3)
			tmp = ft_intercone(rt, cur);
		if (tmp > 0.001 && tmp < rt->dist)
		{
			objs = cur;
			rt->dist = tmp;
		}
		cur = cur->next;
	}
	return (objs);
}
