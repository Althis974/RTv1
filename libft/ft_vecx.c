/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vecx.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 15:48:32 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/16 15:50:38 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_vec	ft_vaddx(t_vec *v1, double x)
{
	t_vec	v;

	v.x = v1->x + x;
	v.y = v1->y + x;
	v.z = v1->z + x;
	return (v);
}

t_vec	ft_vsubx(t_vec *v1, double x)
{
	t_vec	v;

	v.x = v1->x - x;
	v.y = v1->y - x;
	v.z = v1->z - x;
	return (v);
}

t_vec	ft_vmulx(t_vec *v1, double x)
{
	t_vec	v;

	v.x = v1->x * x;
	v.y = v1->y * x;
	v.z = v1->z * x;
	return (v);
}

t_vec	ft_vdivx(t_vec *v1, double x)
{
	t_vec	v;

	v.x = v1->x / x;
	v.y = v1->y / x;
	v.z = v1->z / x;
	return (v);
}
