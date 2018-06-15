/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_env.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 12:29:53 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/15 09:51:29 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	Initializing window
*/

int		ft_env_init(t_env *rt)
{
	rt->mlx.mlx_ptr = mlx_init();
	rt->mlx.win = mlx_new_window(rt->mlx.mlx_ptr, MAX_W + 350, MAX_H, "RTv1");
	rt->nb_spot = 1.0 / rt->nb_spot;
	mlx_expose_hook(rt->mlx.win, ft_create, rt);
	mlx_hook(rt->mlx.win, 2, 0, ft_getting_keys, rt);
	mlx_mouse_hook(rt->mlx.win, ft_mouse, rt);
	mlx_loop(rt->mlx.mlx_ptr);
	return (0);
}

/*
**	Initializing image
*/

int		ft_create(t_env *rt)
{
	rt->mlx.img.img_ptr = mlx_new_image(rt->mlx.mlx_ptr, MAX_W, MAX_H);
	rt->mlx.img.data = mlx_get_data_addr(rt->mlx.img.img_ptr, &rt->mlx.img.bpp,
			&rt->mlx.img.size_l, &rt->mlx.img.endian);
	init_thread(rt);
	ft_display(rt);
	mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img.img_ptr,
			0, 0);
	return (0);
}

/*
** Implementing multi-threading
*/

void	init_thread(t_env *rt)
{
	int			i;
	t_env		p[THREADS];
	pthread_t	th[THREADS];

	i = -1;
	while (++i < THREADS)
	{
		p[i] = *rt;
		p[i].th = i;
		pthread_create(&th[i], NULL, ft_trace, &p[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(th[i], NULL);
}

/*
**	Launching events
*/

void	ft_launch(t_env *rt, int mode)
{
	mlx_destroy_image(rt->mlx.mlx_ptr, rt->mlx.img.img_ptr);
	if (!mode)
		mlx_clear_window(rt->mlx.mlx_ptr, rt->mlx.win);
	ft_create(rt);
}
