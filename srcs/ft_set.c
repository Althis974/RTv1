/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/14 14:55:20 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/14 14:55:20 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Setting camera
*/

void	ft_set_cam(t_env *rt, double x, double y)
{
	double	u;
	double	v;
	t_vec	v1;
	t_vec	v2;
	t_vec	v3;

	u = (MAX_W - x * FOV) / MAX_H;
	v = (MAX_H - y * FOV) / MAX_H;
	v1 = ft_vsub(&rt->cam.dir, &rt->cam.ori);
	ft_vreg(&v1);
	v2 = ft_vinter(&v1, &(t_vec){0.0, 1.0, 0.0});
	ft_vreg(&v2);
	v3 = ft_vinter(&v2, &v1);
	rt->rot.dir = (t_vec){u * v2.x + v * v3.x + FOV * v1.x, u * v2.y + v * \
	v3.y + FOV * v1.y, u * v2.z + v * v3.z + FOV * v1.z};
	rt->rot.ori = rt->cam.ori;
	rt->objs = NULL;
}
