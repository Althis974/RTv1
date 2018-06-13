/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mouse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 12:49:34 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 16:46:16 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Events mouse
*/

int		ft_mouse(int button, int x, int y, t_env *rt)
{
	t_obj	*tmp;
	double	tmpx;
	double	tmpy;

	tmpx = (MAX_W - (double)x * FOV) / MAX_H;
	tmpy = (MAX_H - (double)y * FOV) / MAX_W;
	R1 = ft_vsub(&rt->cam.dir, &rt->cam.ori);
	ft_vnorm(&R1);
	if (button == 4 || button == 5)
		ft_zoom(button, x, y, rt);
	else if (button == 1 && (x >= 0 && x <= MAX_W) && (y >= 0 && y <= MAX_H))
	{
		mlx_clear_window(rt->mlx.mlx_ptr, rt->mlx.win);
		if ((tmp = ft_select((t_vec){CAMX + tmpx, CAMY + tmpy, CAMZ}, tmpx, \
		tmpy, rt)) == NULL)
		{
			PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1110, 600, 0x00FEDC,
				"Nothing here");
			rt->select = 0;
			ft_launch(rt, 1);
			return (0);
		}
		ft_obj_infos(rt, tmp);
		rt->select = 1;
	}
	ft_launch(rt, 1);
	return (0);
}

void	ft_zoom(int button, int x, int y, t_env *rt)
{
	if (button == 4 && (x >= 0 && x <= MAX_H)
		&& (y >= 0 && y <= MAX_W))
	{
		rt->zoom += 1;
		CAMD = (t_vec){CAMD.x + 5.0 * R1.x, CAMD.y + 5.0 * R1.y, \
		CAMD.z + 5.0 * R1.z};
		CAMO = (t_vec){CAMX + 5.0 * R1.x, CAMY + 5.0 * R1.y, CAMZ + 5.0 * R1.z};
	}
	else if (button == 5 && (x >= 0 && x <= MAX_H)
			 && (y >= 0 && y <= MAX_W) && rt->zoom)
	{
		rt->zoom -= 1;
		CAMD = (t_vec){CAMD.x - 5.0 * R1.x, CAMD.y - 5.0 * R1.y, \
		CAMD.z - 5.0 * R1.z};
		CAMO = (t_vec){CAMX - 5.0 * R1.x, CAMY - 5.0 * R1.y, CAMZ - 5.0 * R1.z};
	}
}

t_obj	*ft_select(t_vec pos, double x, double y, t_env *rt)
{
	t_obj	*tmp;
	t_env	*tenv;

	R1 = ft_vsub(&CAMD, &pos);
	ft_vnorm(&R1);
	R2 = ft_vcross(&R1, &(t_vec){0.0, 1.0, 0.0});
	ft_vnorm(&R2);
	R3 = ft_vcross(&R2, &R1);
	rt->ray.dir = (t_vec){x * R2.x + y * R3.x + FOV * R1.x, x * R2.y + y * \
	R3.y + FOV * R1.y, x * R2.z + y * R3.z + FOV * R1.z};
	ft_vnorm(&rt->ray.dir);
	tenv = rt;
	tenv->ray.ori = pos;
	tenv->dist = 1000.0;
	tmp = ft_get_obj_inter(tenv);
	return (tmp);
}
