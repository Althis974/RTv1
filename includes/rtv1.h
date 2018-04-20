/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rtv1.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 17:28:31 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 16:59:15 by rlossy      ###    #+. /#+    ###.fr     */
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


typedef struct	s_col
{
	double		red;
	double		green;
	double		blue;
}				t_col;

typedef struct	s_vec
{
	double		x;
	double		y;
 	double		z;
}				t_vec;

typedef struct	s_ray
{
 	t_vec		dir;
 	t_vec		ori;
}				t_ray;

typedef struct	s_light
{
	t_vec		ori;
 	t_vec		intens;
}				t_light;

typedef struct	s_rot
{
 	t_vec		angle;
}				t_rot;

typedef struct	s_img
{
	int			size_l;
	int			bpp;
	int			endian;
	char		*data;
	void		*img_ptr;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;

typedef struct	s_env
{
	t_rot		rot;
	t_light		light;
	t_mlx		mlx;
}				t_env;

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
**
*/

#endif
