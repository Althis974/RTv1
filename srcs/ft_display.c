/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/13 10:41:36 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 15:05:45 by rlossy      ###    #+. /#+    ###.fr     */
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
	rt->s = ft_strjoin("Anti-Aliasing : x", ft_ftoa(rt->aa), 2);
	if (rt->aa == 1.0)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1080, 210, 0xe60000,
			"Anti-Aliasing : OFF");
	else
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1080, 210, 0x329932, rt->s);
	free(rt->s);
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1010, 260, 0xffa500,
		"LEFT CLICK  : Select OBJ");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1010, 285, 0xffa500,
		"RIGHT CLICK : Deselect OBJ");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1010, 310, 0xffa500,
		"^/</v/>     : Move CAM/OBJ");
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
	ft_cam_infos(rt);
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

/*
**	Display information about camera
*/

void		ft_cam_infos(t_env *rt)
{
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1050, 510, 0x800080,
		" _______ _______ _______ ");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1050, 525, 0x800080,
		"|\\     /|\\     /|\\     /|");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1050, 540, 0x800080,
		"| +---+ | +---+ | +---+ |");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1050, 555, 0x800080,
		"| | C | | | A | | | M | |");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1050, 570, 0x800080,
		"| +---+ | +---+ | +---+ |");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1050, 585, 0x800080,
		"|/_____\\|/_____\\|/_____\\|");
	rt->s = ft_strjoin("ori  : ", (ft_strjoin(ft_ftoa(rt->cam.ori.x),
			(ft_strjoin(" ", (ft_strjoin(ft_ftoa(rt->cam.ori.y),
			(ft_strjoin(" ", ft_ftoa(rt->cam.ori.z), 2)), 3)), 2)), 3)), 2);
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1075, 635, 0x800080, rt->s);
	free(rt->s);
	rt->s = ft_strjoin("dir  : ", (ft_strjoin(ft_ftoa(rt->cam.dir.x),
			(ft_strjoin(" ", (ft_strjoin(ft_ftoa(rt->cam.dir.y),
			(ft_strjoin(" ", ft_ftoa(rt->cam.dir.z), 2)), 3)), 2)), 3)), 2);
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1075, 660, 0x800080, rt->s);
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1000, 710, 0xffa500,
		"___________________________________");
	free(rt->s);
}

/*
**	Display information about selected object
*/

void		ft_obj_infos(t_env *rt)
{
	ft_footer(rt);
	rt->s = ft_strjoin("pos  : ", (ft_strjoin(ft_ftoa(rt->tmp->pos.x), \
			(ft_strjoin(" ", (ft_strjoin(ft_ftoa(rt->tmp->pos.y), \
			(ft_strjoin(" ", ft_ftoa(rt->tmp->pos.z), 2)), 3)), 2)), 3)), 2);
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1075, 857, 0x00FEDC, rt->s);
	free(rt->s);
	rt->s = ft_strjoin("rot  : ", (ft_strjoin(ft_ftoa(rt->tmp->rot.x), \
	(ft_strjoin(" ", (ft_strjoin(ft_ftoa(rt->tmp->rot.y), \
	(ft_strjoin(" ", ft_ftoa(rt->tmp->rot.z), 2)), 3)), 2)), 3)), 2);
	if (rt->tmp->type == 0 || rt->tmp->type == 2 || rt->tmp->type == 3)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1075, 882, 0x00FEDC, rt->s);
	free(rt->s);
	rt->s = ft_strjoin("size : ", ft_ftoa(rt->tmp->size), 2);
	if (rt->tmp->type == 2 || rt->tmp->type == 3)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1075, 907, 0x00FEDC, rt->s);
	else if (rt->tmp->type == 1)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1075, 882, 0x00FEDC, rt->s);
	free(rt->s);
}

/*
**	Display footer
*/

void		ft_footer(t_env *rt)
{
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1100, 760, 0x00FEDC,
		"+-+-+-+-+-+-+-+");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1100, 771, 0x00FEDC,
		"|C|U|R|R|E|N|T|");
	PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1100, 782, 0x00FEDC,
		"+-+-+-+-+-+-+-+");
	if (rt->tmp->type == 0)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1130, 832, 0x00FEDC, "Plane");
	else if (rt->tmp->type == 1)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1130, 832, 0x00FEDC, "Sphere");
	else if (rt->tmp->type == 2)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1130, 832, 0x00FEDC, "Cylinder");
	else if (rt->tmp->type == 3)
		PUT(rt->mlx.mlx_ptr, rt->mlx.win, 1130, 832, 0x00FEDC, "Cone");
}
