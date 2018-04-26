/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rtv1.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 17:28:31 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 17:22:36 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "keycode.h"
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# define MAX_H 1000
# define MAX_W 1000
# define MID_W (MAX_W / 2)
# define MID_H (MAX_H / 2)
# define THREADS 8

/*
**	[Color structure]
**
**	Shade of color from RGB
*/

typedef struct	s_col
{
	double		red;
	double		green;
	double		blue;
}				t_col;

/*
**	[Vector structure]
**
**	Basic name for 3 axes
*/

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

/*
**	[Object structure]
**
**	type	=	type of object from parsing
**	pos		=	position of specific object
**	rot		=	rotation of specific object
**	col		=	color of specific object
**	*next	=	chained list to access to next object
*/

typedef struct	s_obj
{
	int				type;
	t_vec			pos;
	t_vec			rot;
	t_col			col;
	struct s_obj	*next;
}				t_obj;

/*
**	[Light structure]
**
**	data	=	feature of  light
*/

typedef struct	s_light
{
	t_vec		data;
}				t_light;

/*
**	[Camera structure]
**
**	ori		=	origin of camera
**	dir		=	direction of camera
*/

typedef struct	s_cam
{
	t_vec		ori;
	t_vec		dir;
}				t_cam;

/*
**	[Image structure]
**
**	Basic features of mlx image
*/

typedef struct	s_img
{
	int			size_l;
	int			bpp;
	int			endian;
	char		*data;
	void		*img_ptr;
}				t_img;

/*
**	[Mlx structure]
**
**	Basic features of mlx environment
*/

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;

/*
**	[Environment structure]
**
**	mlx		=	basic mlx structure
**	cam		=	camera structure
**	*lite	=	allocation according to nb of spots from parsing
**	*objs	=	list of objects from parsing
**	*cur	=	list to work on current object (might not be kept)
*/

typedef struct	s_env
{
	t_mlx		mlx;
	t_cam		cam;
	t_light		*lite;
	t_obj		*objs;
	t_obj		*cur;
}				t_env;

/*
**	[Multi-thread structure] (might not be kept)
**
**	*rt		=	pointer on env structure
**	part	=	number of thread
*/

typedef struct	s_th
{
	t_env		*rt;
	int			part;
}				t_th;

/*
**  Initialize environment.
*/

/*
**  Functions that take care of tracing.
*/

/*
**  Functions of differents scenes.
*/

/*
**  Functions that take care of events.
*/

/*
** Tried to implement multi-threading
**
** void     init_thread(t_env *f);
** void     *threaderize(void *th);
*/

#endif
