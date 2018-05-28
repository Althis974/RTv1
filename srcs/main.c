/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 11:50:57 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/28 13:49:38 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_initialization(t_env *rt)
{
	rt->aa = 2.0;
	rt->nb_spot = 2.0;
//	rt->cam.ori = (t_vec) {-10.0, 0.0, 10.0};
	rt->cam.ori = (t_vec) {-25.0, 0.0, 0.0};
	rt->cam.dir = (t_vec) {0.0, 0.0, 0.0};

	/*	Scene 1	*/

/*	rt->cur = malloc(sizeof(t_obj));
	rt->cur->next = malloc(sizeof(t_obj));
	rt->cur->type = 4;
	rt->cur->pos = (t_vec) {25.0, 0.0, 0.0};
	rt->cur->rot = (t_vec) {0.0, 1.0, 1.0};
	rt->cur->col = (t_vec) {0.9, 0.9, 0.9};
	rt->cur->size = 1;
	rt->cur->pow = 0.99;
	rt->cur->next->type = 1;
	rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
	rt->cur->next->rot = (t_vec) {0.0, 1.0, 1.0};
	rt->cur->next->size = 0.5;
	rt->cur->next->pos = (t_vec) {5.0, 0.0, 10.0};
	rt->cur->next->next = NULL;*/

	/*	Scene 2	*/

/*	rt->cur = malloc(sizeof(t_obj));
	rt->cur->next = malloc(sizeof(t_obj));
	rt->cur->type = 4;
	rt->cur->pos = (t_vec) {0.0, 0.0, 0.0};
	rt->cur->rot = (t_vec) {0.0, 1.0, 1.0};
	rt->cur->col = (t_vec) {0.9, 0.9, 0.9};
	rt->cur->size = 1;
	rt->cur->pow = 0.99;
	rt->cur->next->type = 3;
	rt->cur->next->col = (t_vec) {1.0, 0.5, 0.5};
	rt->cur->next->size = 1.0;
	rt->cur->next->pos = (t_vec) {5.0, 0.0, 10.0};*/

	/*	Scene 3	*/

/*	rt->cur = malloc(sizeof(t_obj));
	rt->cur->next = malloc(sizeof(t_obj));
	rt->cur->next->next = malloc(sizeof(t_obj));
	rt->cur->type = 4;
	rt->cur->pos = (t_vec) {25.0, 0.0, 0.0};
	rt->cur->rot = (t_vec) {0.0, 1.0, 1.0};
	rt->cur->col = (t_vec) {0.9, 0.9, 0.9};
	rt->cur->size = 1;
	rt->cur->pow = 0.99;
	rt->cur->next->type = 0;
	rt->cur->next->col = (t_vec) {0.75, 0.75, 0.75};
	rt->cur->next->rot = (t_vec) {0.0, 1.0, 1.0};
	rt->cur->next->size = 0.5;
	rt->cur->next->pos = (t_vec) {0.0, 15.0, 0.0};
	rt->cur->next->next->type = 1;
	rt->cur->next->next->col = (t_vec) {1.0, 0.5, 0.5};
	rt->cur->next->next->rot = (t_vec) {0.0, 1.0, 1.0};
	rt->cur->next->next->size = 0.5;
	rt->cur->next->next->pos = (t_vec) {5.0, 0.0, 10.0};
	rt->cur->next->next->next = NULL;*/

	/*	Scene 5	*/

/*	rt->cur = malloc(sizeof(t_obj));
	rt->cur->next = malloc(sizeof(t_obj));
	rt->cur->next->next = malloc(sizeof(t_obj));
	rt->cur->type = 4;
	rt->cur->pos = (t_vec){0.0, 25.0, 0.0};
	rt->cur->rot = (t_vec){0.0, 1.0, 1.0};
	rt->cur->col = (t_vec){0.9, 0.9, 0.9};
	rt->cur->size = 1;
	rt->cur->pow = 0.99;
	rt->cur->next->type = 1;
	rt->cur->next->col = (t_vec){1.0, 0.5, 0.5};
	rt->cur->next->rot = (t_vec){0.0, 1.0, 1.0};
	rt->cur->next->size = 0.5;
	rt->cur->next->pos = (t_vec){5.0, 0.0, 10.0};
	rt->cur->next->pow = 0.5;
	rt->cur->next->next->type = 1;
	rt->cur->next->next->col = (t_vec){0.0, 0.5, 1.0};
	rt->cur->next->next->rot = (t_vec){0.0, 1.0, 1.0};
	rt->cur->next->next->size = 5;
	rt->cur->next->next->pos = (t_vec){10.0, -8.0, 20.0};
	rt->cur->next->next->next = NULL;*/

	/*	Scene 6	*/

	rt->cur = malloc(sizeof(t_obj));
	rt->cur->next = malloc(sizeof(t_obj));
	rt->cur->next->next = malloc(sizeof(t_obj));
	rt->cur->next->next->next = malloc(sizeof(t_obj));
	rt->cur->next->next->next->next = malloc(sizeof(t_obj));
	rt->cur->type = 0;
	rt->cur->pos = (t_vec){0.0, -10.0, 0.0};
	rt->cur->rot = (t_vec){0.0, 1.0, 0.0};
	rt->cur->col = (t_vec){0.75, 0.75, 0.75};
	rt->cur->size = 1.0;
	rt->cur->next->type = 4;
	rt->cur->next->pos = (t_vec){-50.0, 5.0, 25.0};
	rt->cur->next->rot = (t_vec){0.0, 1.0, 1.0};
	rt->cur->next->col = (t_vec){1.0, 1.0, 1.0};
	rt->cur->next->size = 1;
	rt->cur->next->pow = 0.99;
	rt->cur->next->next->type = 1;
	rt->cur->next->next->col = (t_vec){0.04, 0.5, 0.70};
	rt->cur->next->next->rot = (t_vec){0.0, 1.0, 1.0};
	rt->cur->next->next->size = 0.5;
	rt->cur->next->next->pos = (t_vec){0.0, 0.0, 0.0};
	rt->cur->next->next->next->type = 3;
	rt->cur->next->next->next->col = (t_vec){0.40, 0.1, 0.2};
	rt->cur->next->next->next->size = 1.0;
	rt->cur->next->next->next->pos = (t_vec){0.0, 0.0, 0.0};
	rt->cur->next->next->next->next->type = 4;
	rt->cur->next->next->next->next->pos = (t_vec){-50.0, 5.0, -25.0};
	rt->cur->next->next->next->next->rot = (t_vec){0.0, 1.0, 1.0};
	rt->cur->next->next->next->next->col = (t_vec){1.0, 1.0, 1.0};
	rt->cur->next->next->next->next->size = 1.0;
	rt->cur->next->next->next->next->pow = 0.99;
	rt->cur->next->next->next->next->next = NULL;
}

int		main(int ac, char **av)
{
	t_env rt;

	if (ac != 2)
		write(2, "usage : ./rtv1 <scene>\n", 23);
	printf("\n%s\n", av[0]);
	ft_bzero(&rt, sizeof(t_env));
	ft_initialization(&rt);
	ft_env_init(&rt);
	free(&rt);
	ft_bzero(&rt, sizeof(t_env));
	return (0);
}
