/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_scene2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/14 14:14:50 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/14 14:43:21 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
**	SCENE 6 :
**
**	1 Plane
**	1 Cone
**	1 Sphere
**	3 Spots
*/

void	ft_sixth(t_env *rt)
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
	rt->cur->pow = 0.99;
	rt->cur->next->type = 3;
	rt->cur->next->size = 0.5;
	rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
	rt->cur->next->pos = (t_vec) {5.0, 0.0, 0.0};
	rt->cur->next->rot = (t_vec) {0.0, 0.5, 0.5};
	rt->cur->next->next->type = 1;
	rt->cur->next->next->size = 0.5;
	rt->cur->next->next->col = (t_vec) {0.0, 0.0, 1.0};
	rt->cur->next->next->pos = (t_vec) {5.0, 0.0, 0.0};
	ft_sixth_next(rt);
}

void	ft_sixth_next(t_env *rt)
{
	rt->cur->next->next->next->type = 0;
	rt->cur->next->next->next->pos = (t_vec) {0.0, -10.0, 0.0};
	rt->cur->next->next->next->rot = (t_vec) {0.0, 1.0, 0.0};
	rt->cur->next->next->next->col = (t_vec) {0.75, 0.75, 0.75};
	rt->cur->next->next->next->next->type = 4;
	rt->cur->next->next->next->next->pos = (t_vec) {-50.0, 5.0, -25.0};
	rt->cur->next->next->next->next->col = (t_vec) {0.0, 1.0, 0.0};
	rt->cur->next->next->next->next->pow = 0.99;
	rt->cur->next->next->next->next->next->type = 4;
	rt->cur->next->next->next->next->next->pos = (t_vec) {-5.0, 1.0, 0.0};
	rt->cur->next->next->next->next->next->col = (t_vec) {1.0, 0.0, 0.0};
	rt->cur->next->next->next->next->next->pow = 0.99;
	rt->cur->next->next->next->next->next->next = NULL;
}

/*
**	SCENE 7	:
**
**	2 Spheres
**	1 Spot
*/

void	ft_seventh(t_env *rt)
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
	rt->cur->pow = 0.99;
	rt->cur->next->type = 1;
	rt->cur->next->size = 0.5;
	rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
	rt->cur->next->pos = (t_vec) {5.5, 2.0, 11.0};
	rt->cur->next->next->type = 1;
	rt->cur->next->next->size = 5.0;
	rt->cur->next->next->col = (t_vec) {0.0, 0.5, 1.0};
	rt->cur->next->next->pos = (t_vec) {7.5, -5.0, 15.0};
	rt->cur->next->next->next = NULL;
}

/*
**	SCENE 8	:
**
**	2 Spheres
**	2 Planes
**	1 Cone
**	1 Cylinder
**	2 Spots
*/

void	ft_eighth(t_env *rt)
{
	rt->cam.ori = (t_vec) {-25.0, 0.0, 20.0};
	rt->cam.dir = (t_vec) {0.0, 0.0, 0.0};
	rt->cur = malloc(sizeof(t_obj));
	rt->cur->next = malloc(sizeof(t_obj));
	rt->cur->next->next = malloc(sizeof(t_obj));
	rt->cur->next->next->next = malloc(sizeof(t_obj));
	rt->cur->next->next->next->next = malloc(sizeof(t_obj));
	rt->cur->next->next->next->next->next = malloc(sizeof(t_obj));
	rt->cur->next->next->next->next->next->next = malloc(sizeof(t_obj));
	rt->cur->next->next->next->next->next->next->next = malloc(sizeof(t_obj));
	rt->cur->type = 4;
	rt->cur->pos = (t_vec) {-5.0, 0.0, 10.0};
	rt->cur->col = (t_vec) {1.0, 1.0, 1.0};
	rt->cur->pow = 0.80;
	rt->cur->next->type = 3;
	rt->cur->next->size = 0.5;
	rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
	rt->cur->next->pos = (t_vec) {5.0, -1.0, 0.0};
	rt->cur->next->rot = (t_vec) {0.0, 0.5, 0.5};
	rt->cur->next->next->type = 0;
	rt->cur->next->next->pos = (t_vec) {0.0, -10.0, 0.0};
	rt->cur->next->next->rot = (t_vec) {0.0, 1.0, 0.0};
	rt->cur->next->next->col = (t_vec) {0.3, 0.3, 0.3};
	rt->cur->next->next->next->type = 0;
	ft_eighth_next(rt);
}

void	ft_eighth_next(t_env *rt)
{
	rt->cur->next->next->next->pos = (t_vec) {25.0, 0.0, 0.0};
	rt->cur->next->next->next->rot = (t_vec) {1.0, -1.0, 0.0};
	rt->cur->next->next->next->col = (t_vec) {0.0, 0.5, 0.75};
	rt->cur->next->next->next->next->type = 1;
	rt->cur->next->next->next->next->size = 5.0;
	rt->cur->next->next->next->next->pos = (t_vec) {5.0, -5.0, 5.0};
	rt->cur->next->next->next->next->col = (t_vec) {0.2, 0.8, 0.1};
	rt->cur->next->next->next->next->next->type = 2;
	rt->cur->next->next->next->next->next->size = 1.0;
	rt->cur->next->next->next->next->next->pos = (t_vec) {0.0, -5.0, 5.0};
	rt->cur->next->next->next->next->next->rot = (t_vec) {0.0, 0.0, 1.0};
	rt->cur->next->next->next->next->next->col = (t_vec) {0.5, 0.0, 0.5};
	rt->cur->next->next->next->next->next->next->type = 4;
	rt->cur->next->next->next->next->next->next->pos =
	(t_vec) {-10.0, 15.0, -25.0};
	rt->cur->next->next->next->next->next->next->col =
	(t_vec) {0.0, 0.7, 1.0};
	rt->cur->next->next->next->next->next->next->pow = 0.80;
	rt->cur->next->next->next->next->next->next->next->type = 1;
	rt->cur->next->next->next->next->next->next->next->pos =
	(t_vec) {5.0, 10.0, -10.0};
	rt->cur->next->next->next->next->next->next->next->size = 2.5;
	rt->cur->next->next->next->next->next->next->next->col =
	(t_vec) {0.9, 0.9, 0.9};
	rt->cur->next->next->next->next->next->next->next->next = NULL;
}
