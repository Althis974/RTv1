/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rtv1.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 17:28:31 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/14 16:23:12 by rlossy      ###    #+. /#+    ###.fr     */
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
# define THREADS 8
# define FOV 2.0
# define TMP rt->tmp
# define R1 rt->matrix.r1
# define R2 rt->matrix.r2
# define R3 rt->matrix.r3
# define CAMD rt->cam.dir
# define CAMO rt->cam.ori
# define CAMX rt->cam.ori.x
# define CAMY rt->cam.ori.y
# define CAMZ rt->cam.ori.z
# define PUT mlx_string_put

/*
**	[Matrix structure]
**
**	Rows of a matrix
*/

typedef struct		s_matrix
{
	t_vec			r1;
	t_vec			r2;
	t_vec			r3;
}					t_matrix;

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
**	[Ray structure]
**
**	ori		=	origin of ray
**	dir		=	direction of ray
*/

typedef struct		s_ray
{
	t_vec			ori;
	t_vec			dir;
}					t_ray;

/*
**	[Light structure]
**
**	normal	=	normal at the point of intersection
**	spec	=	color of the light of a specular reflection
**	lite	=	color of the object itself under pure white light
**	shade	=	distance under the shadow
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
**	th		=	number of thread
**	aax		=	x storage for anti-aliasing
**	aay		=	y storage for anti-aliasing
**	select	=	boolean to know if select mode is active or not
**	*s		=	string for display
**	aa		=	anti-aliasing value
**	t1		=	first solution of equation
**	t2		=	second solution of equation
**	dist	=	distance traveled by the ray
**	nb_spot	=	number of spotlight from parsing (multi-spots bonus)
**	mlx		=	basic mlx structure
**	cam		=	camera structure
**	ray		=	ray structure
**	col		=	temporary color coefficient
**	rgb		=	final color coefficient
**	*cur	=	list to work on current object
**	*tmp	=	object selected in live
**	*objs	=	list of objects from parsing
**	center	=	object center in case of cone or cylinder
**	light	=	light structure
**	matrix	=	matrix used for event
*/

typedef struct		s_env
{
	int				th;
	int				aax;
	int				aay;
	int				select;
	char			*s;
	double			aa;
	double			t1;
	double			t2;
	double			dist;
	double			nb_spot;
	t_mlx			mlx;
	t_cam			cam;
	t_ray			ray;
	t_vec			col;
	t_vec			rgb;
	t_obj			*cur;
	t_obj			*tmp;
	t_obj			*objs;
	t_vec			center;
	t_light			light;
	t_matrix		matrix;
}					t_env;

/*
**  Initialize environment.
*/

int					ft_env_init(t_env *rt);
int					ft_create(t_env *rt);
void				ft_initialization(t_env *rt, int scene);
void				ft_launch(t_env *rt, int mode);
void				ft_quit(t_env *rt, t_obj *objs);

/*
**  Functions that take care of tracing.
*/

void				init_thread(t_env *rt);
void				*ft_trace(void *th);
void				ft_aa(t_env *rt, double x, double y);
void				ft_set_pixel(t_env *rt, int x, int y, int color);

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
**	Functions concerning shadow
*/

int					ft_get_shade_inter(t_env *rt, t_obj *light, t_vec pos);
double				ft_intershade(t_env *rt, t_obj *objs, t_vec ray, t_vec pos);

/*
**	Functions concerning light
*/

void				ft_get_light(t_env *rt, t_vec *pos);
void				ft_get_shade(t_env *rt, t_vec *pos);
void				ft_get_diffuse(t_env *rt, t_vec *pos);
void				ft_get_specular(t_env *rt, t_vec *pos);
void				ft_set_normal(t_env *rt, t_vec *pos);

/*
**	Functions that take care of objects intersections
*/

double				ft_interplane(t_env *rt, t_obj *obj);
double				ft_intersphere(t_env *rt, t_obj *obj);
double				ft_intercylinder(t_env *rt, t_obj *obj);
double				ft_intercone(t_env *rt, t_obj *obj);

/*
**	Functions that take care of shadow intersections
*/

double				ft_shadplane(t_env *rt, t_obj *obj, t_vec ray, t_vec pos);
double				ft_shadsphere(t_env *rt, t_obj *obj, t_vec ray, t_vec pos);
double				ft_shadcylindr(t_env *rt, t_obj *obj, t_vec ray, t_vec pos);
double				ft_shadcone(t_env *rt, t_obj *obj, t_vec ray, t_vec pos);

/*
**	Function of existing algorithms
*/

t_vec				ft_lambert(t_obj *obj, t_vec *pos, t_vec *normal);
double				ft_phong(t_env *rt, t_obj *obj, t_vec *pos);

/*
**  Functions that take care of keyboard events.
*/

int					ft_getting_keys(int key, t_env *rt);
void				ft_rotate(int key, t_env *rt);
void				ft_moove(int key, t_env *rt);
void				ft_live(int key, t_env *rt);
void				ft_live_next(int key, t_env *rt, double tmp);

/*
**	Functions that take care of mouse events
*/

int					ft_mouse(int button, int x, int y, t_env *rt);
int					ft_mouse_next(t_env *rt);
void				ft_zoom(int button, int x, int y, t_env *rt);
void				ft_live_zoom(int button, int x, int y, t_env *rt);
t_obj				*ft_select(t_vec pos, double x, double y, t_env *rt);

/*
**	Functions that display
*/

void				ft_display(t_env *rt);
void				ft_header(t_env *rt);
void				ft_cam_infos(t_env	*rt);
void				ft_obj_infos(t_env *rt);
void				ft_footer(t_env *rt);

/*
**	Functions that describe scenes
*/

void				ft_first(t_env *rt);
void				ft_second(t_env *rt);
void				ft_third(t_env *rt);
void				ft_fourth(t_env *rt);
void				ft_fifth(t_env *rt);
void				ft_sixth(t_env *rt);
void				ft_sixth_next(t_env *rt);
void				ft_seventh(t_env *rt);
void				ft_eighth(t_env *rt);
void				ft_eighth_next(t_env *rt);

#endif
