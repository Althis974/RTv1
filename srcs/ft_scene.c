/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_scene.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/14 14:03:30 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/14 14:20:51 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	SCENE 1	:
**
**	1 Sphere
**	1 Spot
*/

void	ft_first(t_env *rt)
{
	rt->nb_spot = 1.0;
	rt->cam.ori = (t_vec) {0.0, 0.0, 0.0};
	rt->cam.dir = (t_vec) {5.0, 0.0, 10.0};
	rt->cur = malloc(sizeof(t_obj));
	rt->cur->next = malloc(sizeof(t_obj));
	rt->cur->type = 4;
	rt->cur->pos = (t_vec) {10.0, 0.0, 0.0};
	rt->cur->col = (t_vec) {0.9, 0.9, 0.9};
	rt->cur->pow = 0.99;
	rt->cur->next->type = 1;
	rt->cur->next->size = 1.0;
	rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
	rt->cur->next->pos = (t_vec) {5.0, 0.0, 10.0};
	rt->cur->next->next = NULL;
}

/*
**	SCENE 2	:
**
**	1 Cylinder
**	1 Plane
**	1 Spot
*/

void	ft_second(t_env *rt)
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
	rt->cur->pow = 0.99;
	rt->cur->next->type = 2;
	rt->cur->next->size = 1.0;
	rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
	rt->cur->next->pos = (t_vec) {4.0, 9.0, 0.0};
	rt->cur->next->rot = (t_vec) {0.0, 1.0, 0.0};
	rt->cur->next->next->type = 0;
	rt->cur->next->next->pos = (t_vec) {0.0, -10.0, 0.0};
	rt->cur->next->next->rot = (t_vec) {0.0, 0.1, 0.0};
	rt->cur->next->next->col = (t_vec) {0.75, 0.75, 0.75};
	rt->cur->next->next->next = NULL;
}

/*
**	SCENE 3	:
**
**	1 Sphere
**	1 Plane
**	1 Spot
*/

void	ft_third(t_env *rt)
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
	rt->cur->pow = 0.99;
	rt->cur->next->type = 0;
	rt->cur->next->col = (t_vec) {0.75, 0.75, 0.75};
	rt->cur->next->rot = (t_vec) {1.0, 0.0, 0.0};
	rt->cur->next->pos = (t_vec) {0.0, -10.0, 0.0};
	rt->cur->next->next->type = 1;
	rt->cur->next->next->size = 0.5;
	rt->cur->next->next->col = (t_vec) {1.0, 0.5, 0.5};
	rt->cur->next->next->pos = (t_vec) {-15.0, 0.0, 0.0};
	rt->cur->next->next->next = NULL;
}

/*
**	SCENE 4	:
**
**	1 Cylinder
**	1 Plane
**	1 Spot
*/

void	ft_fourth(t_env *rt)
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
	rt->cur->pow = 0.99;
	rt->cur->next->type = 2;
	rt->cur->next->size = 1.0;
	rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
	rt->cur->next->pos = (t_vec) {5.0, 0.0, 0.0};
	rt->cur->next->rot = (t_vec) {0.0, 0.5, 0.5};
	rt->cur->next->next->type = 0;
	rt->cur->next->next->pos = (t_vec) {0.0, -10.0, 0.0};
	rt->cur->next->next->rot = (t_vec) {0.0, 1.0, 0.0};
	rt->cur->next->next->col = (t_vec) {0.75, 0.75, 0.75};
	rt->cur->next->next->next = NULL;
}

/*
**	SCENE 5	:
**
**	2 Planes
**	1 Cone
**	1 Spot
*/

void	ft_fifth(t_env *rt)
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
	rt->cur->pow = 0.99;
	rt->cur->next->type = 3;
	rt->cur->next->size = 0.5;
	rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
	rt->cur->next->rot = (t_vec) {0.0, 0.5, 0.5};
	rt->cur->next->pos = (t_vec) {5.0, -1.0, 0.0};
	rt->cur->next->next->type = 0;
	rt->cur->next->next->pos = (t_vec) {0.0, -10.0, 0.0};
	rt->cur->next->next->rot = (t_vec) {0.0, 1.0, 0.0};
	rt->cur->next->next->col = (t_vec) {0.0, 0.75, 0.5};
	rt->cur->next->next->next->type = 0;
	rt->cur->next->next->next->pos = (t_vec) {25.0, 0.0, 0.0};
	rt->cur->next->next->next->rot = (t_vec) {1.0, -1.0, 0.0};
	rt->cur->next->next->next->col = (t_vec) {0.0, 0.5, 0.75};
	rt->cur->next->next->next->next = NULL;
}
