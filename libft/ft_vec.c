/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vec.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/14 10:58:37 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 13:54:54 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_vec	ft_vsub(t_vec *v1, t_vec *v2)
{
	t_vec	v;

	v.x = v1->x - v2->x;
	v.y = v1->y - v2->y;
	v.z = v1->z - v2->z;
	return (v);
}

t_vec	ft_vinter(t_vec *v1, t_vec *v2)
{
	t_vec v;

	v.x = v1->y * v2->z - v1->z * v2->y;
	v.y = v1->z * v2->x - v1->x * v2->z;
	v.z = v1->x * v2->y - v1->y * v2->x;
	return (v);
}

void	ft_vreg(t_vec *v)
{
	double	n;

	n = 1.0 / sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x *= n;
	v->y *= n;
	v->z *= n;
}

double	ft_vpoint(t_vec *v1, t_vec *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}
