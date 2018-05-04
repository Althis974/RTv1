/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 14:25:50 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 14:44:54 by rlossy      ###    #+. /#+    ###.fr     */
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

	rt->nb_iter = 10000.0;
	rt->objs = ft_get_obj_inter(rt);
	if (rt->nb_iter > 0.0001 && rt->objs)
	{
		rt->col = (t_col){rt->objs->col.red, rt->objs->col.green, rt->objs->col.blue};
		if (rt->nb_iter < 10000.0)
		{
			pos = (t_vec){rt->rot.ori.x + rt->nb_iter * rt->rot.dir.x, rt->rot.ori.y + rt->nb_iter * \
			rt->rot.dir.y, rt->rot.ori.z + rt->nb_iter * rt->rot.dir.z};
			ft_get_lite(rt, &pos);
		}
	}
}
