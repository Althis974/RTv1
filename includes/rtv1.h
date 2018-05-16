/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rtv1.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 17:28:31 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/16 16:44:18 by rlossy      ###    #+. /#+    ###.fr     */
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
# define FOV 2.0

/*
**	[Color structure]
**
**	/!\ Now considered as vector that correspond to coef of color /!\
*/

/*
**	[Vector structure]
**
**	Moved to Libft
*/

/*
**	[Object structure]
**
**	type	=	type of object from parsing
**	pos		=	position of specific object
**	rot		=	rotation of specific object
**	col		=	color of specific object
**	size	=	size of specific object
**	pow		=	intensity of light
**	*next	=	chained list to access to next object
*/

typedef struct		s_obj
{
	int				type;
	t_vec			pos;
	t_vec			rot;
	t_vec			col;
	double			size;
	double			pow;
	struct s_obj	*next;
}					t_obj;

/*
**	[Camera structure]
**
**	ori		=	origin of camera
**	dir		=	direction of camera
*/

typedef struct		s_cam
{
	t_vec			ori;
	t_vec			dir;
}					t_cam;

/*
**	[Rotation structure]
**
**	ori		=	origin of rotation
**	dir		=	direction of rotation
*/

typedef struct		s_rot
{
	t_vec			ori;
	t_vec			dir;
}					t_rot;

/*
**	[Light structure]
**
**	normal	=	normal at the point of intersection
**	spec	=	color of the light of a specular reflection
**	lite	=	color of the object itself under pure white light
**	shade	=	distance under the shadow
**
**	/!\ Parsed as an object. This structure is used for calculation /!\
*/

typedef struct		s_light
{
	t_vec			normal;
	t_vec			spec;
	t_vec			lite;
	double			shade;
}					t_light;

/*
**	[Image structure]
**
**	Basic features of mlx image
*/

typedef struct		s_img
{
	int				size_l;
	int				bpp;
	int				endian;
	char			*data;
	void			*img_ptr;
}					t_img;

/*
**	[Mlx structure]
**
**	Basic features of mlx environment
*/

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win;
	t_img			img;
}					t_mlx;

/*
**	[Environment structure]
**
**	mlx		=	basic mlx structure
**	cam		=	camera structure
**	rot		=	rotation structure
**	col		=	original color of image (might not be kept)
**	*objs	=	list of objects from parsing
**	*cur	=	list to work on current object (might not be kept)
**	dist	=	distance traveled by the ray
**	nb_spot	=	number of spotlight from parsing (multi-spots bonus)
*/

typedef struct		s_env
{
	t_mlx			mlx;
	t_cam			cam;
	t_rot			rot;
	t_vec			col;
	t_light			light;
	t_obj			*objs;
	t_obj			*cur;
	double			dist;
	double			nb_spot;
}					t_env;

/*
**	[Multi-thread structure]
**
**	*rt		=	pointer on env structure
**	part	=	number of thread
*/

typedef struct		s_th
{
	t_env			*rt;
	int				part;
}					t_th;

/*
**  Initialize environment.
*/

void				ft_initialization(t_env *rt);
int					ft_env_init(t_env *rt);
int					ft_create(t_env *rt);

/*
**  Functions that take care of tracing.
*/

int					ft_trace(t_env *rt, int part);

/*
**	Functions concerning camera
*/

void				ft_set_cam(t_env *rt, double x, double y);

/*
**	Functions concerning objects
*/

void				ft_get_obj_col(t_env *rt);
t_obj				*ft_get_obj_inter(t_env *rt);

/*
**	Functions concerning light
*/

void				ft_get_light(t_env *rt, t_vec *pos);
double				ft_get_shade(t_env *rt, t_vec *pos);
t_vec				ft_get_diffuse(t_env *rt, t_vec *pos);
t_vec				ft_get_specular(t_env *rt, t_vec *pos);
t_vec				ft_set_normal(t_obj *obj, t_vec *pos);

/*
**	Functions that take care of objects intersections
*/

double				ft_interplane(t_obj *obj, t_env *rt);
double				ft_intersphere(t_obj *obj, t_env *rt);
double				ft_intercylinder(t_obj *obj, t_env *rt);
double				ft_intercone(t_obj *obj, t_env *rt);

/*
**	Functions that take care of shadow intersections
*/

/*
**  Functions that take care of events.
*/

/*
** Implementing multi-threading
*/

void				init_thread(t_env *rt);
void				*threaderize(void *th);

#endif
