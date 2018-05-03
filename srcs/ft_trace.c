/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trace.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:26:27 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 16:58:20 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		ft_trace(t_env *rt, int part)
{
	int		x;
	int		y;
	int		stop;
	int		start;

	start = (MAX_H / THREADS) * part;
	stop = (MAX_H / THREADS) * (part + 1);
	y = start - 1;
	while (++y < stop)
	{
		x = -1;
		while (++x < MAX_W)
		{
//			ft_set_pixel(rt, x, y);
		}
	}
	return (0);
}