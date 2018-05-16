/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vec2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 11:09:44 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/16 12:37:22 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_vreg(t_vec *v, double a, double b)
{
	v->x = ft_reg(v->x, a, b);
	v->y = ft_reg(v->y, a, b);
	v->z = ft_reg(v->z, a, b);
}

void	ft_vnorm(t_vec *v)
{
	double	n;

	n = 1.0 / sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x *= n;
	v->y *= n;
	v->z *= n;
}

double	ft_vdot(t_vec *v1, t_vec *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}
