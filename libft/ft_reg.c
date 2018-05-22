/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_reg.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 11:11:30 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/22 14:05:03 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

double	ft_reg(double x, double min, double max)
{
	x = x < min ? min : x;
	x = x > max ? max : x;
	return (x);
}
