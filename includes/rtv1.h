/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rtv1.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 17:28:31 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 17:31:21 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../minilibx_macos/mlx.h"
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "keycode.h"
# include <pthread.h>
#define MAX_LEN 1000
# define MAX_WID 1000
# define MID_WID (MAX_WID / 2)
# define MINX f->mlx.minx
# define MINY f->mlx.miny
# define MAXX f->mlx.maxx
# define MAXY f->mlx.maxy
# define MOTION 6
# define NB_FRAC 10

/*
typedef struct	s_col
{
	int			red;
	int			green;
	int			blue;
	int			val;
	int			sw1;
	int			sw2;
	double		coef;
}				t_col;

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct	s_tree
{
	int			iter;
	int			on;
	double		size1;
	double		size2;
	t_col		col;
}				t_tree;

typedef struct	s_mouse
{
	int			on;
	int			zoom;
	double		x;
	double		y;
}				t_mouse;

typedef struct	s_frac
{
	int			type;
	double		max_iter;
	double		freq;
	double		constr;
	double		consti;
	double		real;
	double		img;
	double		man;
	t_col		col;
	t_tree		tree;
}				t_frac;

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
	int			color;
	void		*mlx_ptr;
	void		*win;
	double		minx;
	double		miny;
	double		maxx;
	double		maxy;
	t_img		img;
}				t_mlx;

typedef struct	s_env
{
	t_frac		frac;
	t_mlx		mlx;
	t_mouse		mouse;
}				t_env;
*/
/*
**  Initialize environment.
*/


/*
**  Functions that take care of tracing.
*/


/*
**  Functions of differents fractals.
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
** typedef struct		s_th
**{
**	t_env			*f;
**	int				part;
**}                    t_th;
*/

#endif
