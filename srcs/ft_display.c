/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/13 10:41:36 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 16:54:17 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Head-Up Display
*/

void		ft_display(t_env *rt)
{
	ft_header(rt);
	if (rt->aa == 1.0)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1080, 210, 0xe60000,
			"Anti-Aliasing : OFF");
	else
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1080, 210, 0x329932,
			ft_strjoin("Anti-Aliasing : x", ft_ftoa(rt->aa)));
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1010, 260, 0xffa500,
		"LEFT CLICK  : Select OBJ");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1010, 285, 0xffa500,
		"RIGHT CLICK : Deselect OBJ");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1010, 310, 0xffa500,
		"^/</>/v     : Move CAM/OBJ");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1010, 335, 0xffa500,
		"W/A/S/D     : Rotate CAM/OBJ");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1010, 360, 0xffa500,
		"SCROLL      : ZOOM");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1010, 385, 0xffa500,
		"+/-         : Vary Anti-Aliasing");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1010, 410, 0xffa500,
		"ESC         : Exit");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1010, 460, 0xffa500,
		"___________________________________");
	ft_footer(rt);
}

/*
**	Display header
*/

void		ft_header(t_env *rt)
{
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1000, 0, 0xffa500,
		"HHHHH   HHHHHUUUU   UUUUDDDDDD");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1000, 11, 0xffa500,
		"H:::H   H:::HU::U   U::UD:::::DD");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1000, 22, 0xffa500,
		"HH::H   H::HHUU:U   U:UUDDD:DDD:D");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1000, 33, 0xffa500,
		"  H:H   H:H   U:U   U:U   D:D  D:D");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1000, 44, 0xffa500,
		"  H::HHH::H   U:D   D:U   D:D   D:D");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1000, 55, 0xffa500,
		"  H:::::::H   U:D   D:U   D:D   D:D");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1000, 66, 0xffa500,
		"  H::HHH::H   U:D   D:U   D:D   D:D");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1000, 77, 0xffa500,
		"  H:H   H:H   U::U U::U   D:D  D:D");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1000, 88, 0xffa500,
		"HH::H   H::HH U:::U:::U DDD:DDD:D");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1000, 99, 0xffa500,
		"H:::H   H:::H  UU:::UU  D:::::DD");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1000, 110, 0xffa500,
		"HHHHH   HHHHH    UUU    DDDDDD");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1000, 160, 0xffa500,
		"___________________________________");
}

void		ft_footer(t_env	*rt)
{

}

/*
**	Display object infos
*/

void		ft_obj_infos(t_env *rt, t_obj *tmp)
{
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1100, 500, 0x00FEDC,
		"+-+-+-+-+-+-+-+");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1100, 511, 0x00FEDC,
		"|C|U|R|R|E|N|T|");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1100, 522, 0x00FEDC,
		"+-+-+-+-+-+-+-+");
	if (tmp->type == 0)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1110, 600, 0x00FEDC, "Plane");
	else if (tmp->type == 1)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1110, 600, 0x00FEDC, "Sphere");
	else if (tmp->type == 2)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1110, 600, 0x00FEDC, "Cylinder");
	else if (tmp->type == 3)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1110, 600, 0x00FEDC, "Cone");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1110, 625, 0x00FEDC,
		ft_strjoin("pos  : ", (ft_strjoin(ft_ftoa(tmp->pos.x), \
			(ft_strjoin(" ", (ft_strjoin(ft_ftoa(tmp->pos.y), (ft_strjoin(" ", \
			ft_ftoa(tmp->pos.z)))))))))));
	if (tmp->type == 0 || tmp->type == 2 || tmp->type == 3)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1110, 650, 0x00FEDC,
			ft_strjoin("rot  : ", (ft_strjoin(ft_ftoa(tmp->rot.x), \
			(ft_strjoin(" ", (ft_strjoin(ft_ftoa(tmp->rot.y), (ft_strjoin(" ", \
			ft_ftoa(tmp->rot.z)))))))))));
	if (tmp->type == 2 || tmp->type == 3)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1110, 675, 0x00FEDC,
			ft_strjoin("size : ", ft_ftoa(tmp->size)));
	else if (tmp->type == 1)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1110, 650, 0x00FEDC,
			ft_strjoin("size : ", ft_ftoa(tmp->size)));
}
