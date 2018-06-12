/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 11:50:57 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/12 16:46:39 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_initialization(t_env *rt, int scene)
{
	rt->aa = 1.0;

	/*	Scene 1	: Sphere + Light */
	if (scene == 1)
	{
		rt->nb_spot = 1.0;
		rt->cam.ori = (t_vec) {0.0, 0.0, 0.0};
		rt->cam.dir = (t_vec) {5.0, 0.0, 10.0};
		rt->cur = malloc(sizeof(t_obj));
		rt->cur->next = malloc(sizeof(t_obj));
		rt->cur->type = 4;
		rt->cur->pos = (t_vec) {10.0, 0.0, 0.0};
		rt->cur->col = (t_vec) {0.9, 0.9, 0.9};
		rt->cur->size = 1;
		rt->cur->pow = 0.99;
		rt->cur->next->type = 1;
		rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
		rt->cur->next->size = 1.0;
		rt->cur->next->pos = (t_vec) {5.0, 0.0, 10.0};
		rt->cur->next->next = NULL;
	}

	/*	Scene 2	: Cyl + Light + Plane */

	else if (scene == 2)
	{
		rt->nb_spot = 1.0;
		rt->cam.ori = (t_vec) {-25.0, 0.0, 0.0};
		rt->cam.dir = (t_vec) {0.0, 0.0, 0.0};
		rt->cur = malloc(sizeof(t_obj));
		rt->cur->next = malloc(sizeof(t_obj));
		rt->cur->next->next = malloc(sizeof(t_obj));
		rt->cur->type = 4;
		rt->cur->pos = (t_vec) {-5.0, 0.0, 0.0};
		rt->cur->col = (t_vec) {0.9, 0.9, 0.9};
		rt->cur->size = 1;
		rt->cur->pow = 0.99;
		rt->cur->next->type = 2;
		rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
		rt->cur->next->size = 1.0;
		rt->cur->next->pos = (t_vec) {4.0, 9.0, 0.0};
		rt->cur->next->rot = (t_vec) {0.0, 1.0, 0.0};
		rt->cur->next->next->type = 0;
		rt->cur->next->next->pos = (t_vec) {0.0, -10.0, 0.0};
		rt->cur->next->next->rot = (t_vec) {0.0, 0.1, 0.0};
		rt->cur->next->next->col = (t_vec) {0.75, 0.75, 0.75};
		rt->cur->next->next->size = 1.0;
		rt->cur->next->next->next = NULL;
	}

	/*	Scene 3	: Sphere + Plane + Light | different cam */

	else if (scene == 3)
	{
		rt->nb_spot = 1.0;
		rt->cam.ori = (t_vec) {-15.0, 10.0, 10.0};
		rt->cam.dir = (t_vec) {-10.0, 0.0, 0.0};
		rt->cur = malloc(sizeof(t_obj));
		rt->cur->next = malloc(sizeof(t_obj));
		rt->cur->next->next = malloc(sizeof(t_obj));
		rt->cur->type = 4;
		rt->cur->pos = (t_vec) {-20.0, 0.0, 2.0};
		rt->cur->col = (t_vec) {0.9, 0.9, 0.9};
		rt->cur->size = 1;
		rt->cur->pow = 0.99;
		rt->cur->next->type = 0;
		rt->cur->next->col = (t_vec) {0.75, 0.75, 0.75};
		rt->cur->next->rot = (t_vec) {1.0, 0.0, 0.0};
		rt->cur->next->size = 0.5;
		rt->cur->next->pos = (t_vec) {0.0, -10.0, 0.0};
		rt->cur->next->next->type = 1;
		rt->cur->next->next->col = (t_vec) {1.0, 0.5, 0.5};
		rt->cur->next->next->size = 0.5;
		rt->cur->next->next->pos = (t_vec) {-15.0, 0.0, 0.0};
		rt->cur->next->next->next = NULL;
	}

	/*	Scene 4	: rot cyl + plane + light */

	else if (scene == 4)
	{
		rt->nb_spot = 1.0;
		rt->cam.ori = (t_vec) {-25.0, 0.0, 0.0};
		rt->cam.dir = (t_vec) {0.0, 0.0, 0.0};
		rt->cur = malloc(sizeof(t_obj));
		rt->cur->next = malloc(sizeof(t_obj));
		rt->cur->next->next = malloc(sizeof(t_obj));
		rt->cur->type = 4;
		rt->cur->pos = (t_vec) {-5.0, 0.0, 0.0};
		rt->cur->col = (t_vec) {0.9, 0.9, 0.9};
		rt->cur->size = 1;
		rt->cur->pow = 0.99;
		rt->cur->next->type = 2;
		rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
		rt->cur->next->size = 1.0;
		rt->cur->next->pos = (t_vec) {5.0, 0.0, 0.0};
		rt->cur->next->rot = (t_vec) {0.0, 0.5, 0.5};
		rt->cur->next->next->type = 0;
		rt->cur->next->next->pos = (t_vec) {0.0, -10.0, 0.0};
		rt->cur->next->next->rot = (t_vec) {0.0, 1.0, 0.0};
		rt->cur->next->next->col = (t_vec) {0.75, 0.75, 0.75};
		rt->cur->next->next->size = 1.0;
		rt->cur->next->next->next = NULL;
	}

	/*	Scene 5	: 2 planes + cone + light */

	else if (scene == 5)
	{
		rt->nb_spot = 1.0;
		rt->cam.ori = (t_vec) {-25.0, 0.0, 20.0};
		rt->cam.dir = (t_vec) {0.0, 0.0, 0.0};
		rt->cur = malloc(sizeof(t_obj));
		rt->cur->next = malloc(sizeof(t_obj));
		rt->cur->next->next = malloc(sizeof(t_obj));
		rt->cur->next->next->next = malloc(sizeof(t_obj));
		rt->cur->type = 4;
		rt->cur->pos = (t_vec) {-5.0, 0.0, 0.0};
		rt->cur->col = (t_vec) {0.9, 0.9, 0.9};
		rt->cur->size = 1;
		rt->cur->pow = 0.99;
		rt->cur->next->type = 3;
		rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
		rt->cur->next->size = 0.5;
		rt->cur->next->pos = (t_vec) {5.0, -1.0, 0.0};
		rt->cur->next->rot = (t_vec) {0.0, 0.5, 0.5};
		rt->cur->next->next->type = 0;
		rt->cur->next->next->pos = (t_vec) {0.0, -10.0, 0.0};
		rt->cur->next->next->rot = (t_vec) {0.0, 1.0, 0.0};
		rt->cur->next->next->col = (t_vec) {0.0, 0.75, 0.5};
		rt->cur->next->next->size = 1.0;
		rt->cur->next->next->next->type = 0;
		rt->cur->next->next->next->pos = (t_vec) {25.0, 0.0, 0.0};
		rt->cur->next->next->next->rot = (t_vec) {1.0, -1.0, 0.0};
		rt->cur->next->next->next->col = (t_vec) {0.0, 0.5, 0.75};
		rt->cur->next->next->next->size = 1.0;
		rt->cur->next->next->next->next = NULL;
	}

	/* Scene 6 : plane + cone + sphere + 3 lights */

	else if (scene == 6)
	{
		rt->nb_spot = 3.0;
		rt->cam.ori = (t_vec) {-25.0, 10.0, -13.0};
		rt->cam.dir = (t_vec) {0.0, 0.0, -10.0};
		rt->cur = malloc(sizeof(t_obj));
		rt->cur->next = malloc(sizeof(t_obj));
		rt->cur->next->next = malloc(sizeof(t_obj));
		rt->cur->next->next->next = malloc(sizeof(t_obj));
		rt->cur->next->next->next->next = malloc(sizeof(t_obj));
		rt->cur->next->next->next->next->next = malloc(sizeof(t_obj));
		rt->cur->type = 4;
		rt->cur->pos = (t_vec) {-50.0, 5.0, 25.0};
		rt->cur->col = (t_vec) {0.0, 0.0, 1.0};
		rt->cur->size = 1;
		rt->cur->pow = 0.99;
		rt->cur->next->type = 3;
		rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
		rt->cur->next->size = 0.5;
		rt->cur->next->pos = (t_vec) {5.0, 0.0, 0.0};
		rt->cur->next->rot = (t_vec) {0.0, 0.5, 0.5};
		rt->cur->next->next->type = 1;
		rt->cur->next->next->col = (t_vec) {0.0, 0.0, 1.0};
		rt->cur->next->next->size = 0.5;
		rt->cur->next->next->pos = (t_vec) {5.0, 0.0, 0.0};
		rt->cur->next->next->next->type = 0;
		rt->cur->next->next->next->pos = (t_vec) {0.0, -10.0, 0.0};
		rt->cur->next->next->next->rot = (t_vec) {0.0, 1.0, 0.0};
		rt->cur->next->next->next->col = (t_vec) {0.75, 0.75, 0.75};
		rt->cur->next->next->next->size = 1.0;
		rt->cur->next->next->next->next->type = 4;
		rt->cur->next->next->next->next->pos = (t_vec) {-50.0, 5.0, -25.0};
		rt->cur->next->next->next->next->col = (t_vec) {0.0, 1.0, 0.0};
		rt->cur->next->next->next->next->size = 1.0;
		rt->cur->next->next->next->next->pow = 0.99;
		rt->cur->next->next->next->next->next->type = 4;
		rt->cur->next->next->next->next->next->pos = (t_vec) {-5.0, 1.0, 0.0};
		rt->cur->next->next->next->next->next->col = (t_vec) {1.0, 0.0, 0.0};
		rt->cur->next->next->next->next->next->size = 1;
		rt->cur->next->next->next->next->next->pow = 0.99;
		rt->cur->next->next->next->next->next->next = NULL;
	}

	/* Scene 7	: 2 spheres + light */

	else if (scene == 7)
	{
		rt->nb_spot = 1.0;
		rt->cam.ori = (t_vec) {0.0, 0.0, 0.0};
		rt->cam.dir = (t_vec) {5.0, 0.0, 10.0};
		rt->cur = malloc(sizeof(t_obj));
		rt->cur->next = malloc(sizeof(t_obj));
		rt->cur->next->next = malloc(sizeof(t_obj));
		rt->cur->type = 4;
		rt->cur->pos = (t_vec) {0.0, 25.0, 0.0};
		rt->cur->col = (t_vec) {0.9, 0.9, 0.9};
		rt->cur->size = 1;
		rt->cur->pow = 0.99;
		rt->cur->next->type = 1;
		rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
		rt->cur->next->size = 0.5;
		rt->cur->next->pos = (t_vec) {5.5, 2.0, 11.0};
		rt->cur->next->pow = 0.5;
		rt->cur->next->next->type = 1;
		rt->cur->next->next->col = (t_vec) {0.0, 0.5, 1.0};
		rt->cur->next->next->size = 5.0;
		rt->cur->next->next->pos = (t_vec) {7.5, -5.0, 15.0};
		rt->cur->next->next->next = NULL;
	}

	/*	Scene 8	: 2 spheres + 2 planes + cone + cyl + 2 lights */

	else if (scene == 8)
	{
		rt->nb_spot = 2.0;
		rt->cam.ori = (t_vec) {-25.0, 0.0, 20.0};
		rt->cam.dir = (t_vec) {0.0, 0.0, 0.0};
		rt->cur = malloc(sizeof(t_obj));
		rt->cur->next = malloc(sizeof(t_obj));
		rt->cur->next->next = malloc(sizeof(t_obj));
		rt->cur->next->next->next = malloc(sizeof(t_obj));
		rt->cur->next->next->next->next = malloc(sizeof(t_obj));
		rt->cur->next->next->next->next->next = malloc(sizeof(t_obj));
		rt->cur->next->next->next->next->next->next = malloc(sizeof(t_obj));
		rt->cur->next->next->next->next->next->next->next = malloc(
		sizeof(t_obj));
		rt->cur->type = 4;
		rt->cur->pos = (t_vec) {-5.0, 0.0, 10.0};
		rt->cur->col = (t_vec) {1.0, 1.0, 1.0};
		rt->cur->size = 1.0;
		rt->cur->pow = 0.80;
		rt->cur->next->type = 3;
		rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
		rt->cur->next->size = 0.5;
		rt->cur->next->pos = (t_vec) {5.0, -1.0, 0.0};
		rt->cur->next->rot = (t_vec) {0.0, 0.5, 0.5};
		rt->cur->next->next->type = 0;
		rt->cur->next->next->pos = (t_vec) {0.0, -10.0, 0.0};
		rt->cur->next->next->rot = (t_vec) {0.0, 1.0, 0.0};
		rt->cur->next->next->col = (t_vec) {0.3, 0.3, 0.3};
		rt->cur->next->next->size = 1.0;
		rt->cur->next->next->next->type = 0;
		rt->cur->next->next->next->pos = (t_vec) {25.0, 0.0, 0.0};
		rt->cur->next->next->next->rot = (t_vec) {1.0, -1.0, 0.0};
		rt->cur->next->next->next->col = (t_vec) {0.0, 0.5, 0.75};
		rt->cur->next->next->next->size = 1.0;
		rt->cur->next->next->next->next->type = 1;
		rt->cur->next->next->next->next->pos = (t_vec) {5.0, -5.0, 5.0};
		rt->cur->next->next->next->next->size = 5.0;
		rt->cur->next->next->next->next->col = (t_vec) {0.2, 0.8, 0.1};
		rt->cur->next->next->next->next->next->type = 2;
		rt->cur->next->next->next->next->next->pos = (t_vec) {0.0, -5.0, 5.0};
		rt->cur->next->next->next->next->next->rot = (t_vec) {0.0, 0.0, 1.0};
		rt->cur->next->next->next->next->next->col = (t_vec) {0.5, 0.0, 0.5};
		rt->cur->next->next->next->next->next->size = 1.0;
		rt->cur->next->next->next->next->next->next->type = 4;
		rt->cur->next->next->next->next->next->next->pos = (t_vec) {-10.0, 15.0,
																	-25.0};
		rt->cur->next->next->next->next->next->next->col = (t_vec) {0.0, 0.7,
																	1.0};
		rt->cur->next->next->next->next->next->next->size = 1.0;
		rt->cur->next->next->next->next->next->next->pow = 0.80;
		rt->cur->next->next->next->size = 1.0;
		rt->cur->next->next->next->next->next->next->next->type = 1;
		rt->cur->next->next->next->next->next->next->next->pos = (t_vec) {5.0,
																		  10.0,
																		  -10.0};
		rt->cur->next->next->next->next->next->next->next->size = 2.5;
		rt->cur->next->next->next->next->next->next->next->col = (t_vec) {0.9,
																		  0.9,
																		  0.9};
		rt->cur->next->next->next->next->next->next->next->next = NULL;
	}
}

int		main(int ac, char **av)
{
	t_env rt;

	if (ac != 2 || ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 8)
	{
		write(2, "usage : ./rtv1 <scene>\n", 23);
		return (1);
	}
	ft_bzero(&rt, sizeof(t_env));
	ft_initialization(&rt, ft_atoi(av[1]));
	ft_env_init(&rt);
//	free(&rt);
//	ft_bzero(&rt, sizeof(t_env));
	return (0);
}
