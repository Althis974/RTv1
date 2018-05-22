/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 11:50:57 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/22 17:20:08 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_initialization(t_env *rt)
{
	rt->nb_spot = 1.0;
	rt->cam.ori = (t_vec) {0.0, 0.0, 0.0};
	rt->cam.dir = (t_vec) {5.0, 0.0, 10.0};

/*	Scene 1	*/

	rt->cur = malloc(sizeof(t_obj));
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
	rt->cur->next->pow = 0.5;
	rt->cur->next->next = NULL;

/*	Scene 2	*/

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
}

int		main(int ac, char **av)
{
	t_env rt;

	if (ac != 2)
		write(2, "usage : ./rtv1 <scene>\n", 23);
	printf("\n%s\n", av[0]);
	ft_bzero(&rt, sizeof(t_env));
	ft_initialization(&rt);
//	printf("\n1: type = %d\n", rt.cur->type);
//	printf("\n1: pos = %lf, %lf, %lf\n", rt.cur->pos.x, rt.cur->pos.y, rt.cur->pos.z);
//	printf("\n1: rot = %lf, %lf, %lf\n", rt.cur->rot.x, rt.cur->rot.y, rt.cur->rot.z);
//	printf("\n1: col = %lf, %lf, %lf\n", rt.cur->col.x, rt.cur->col.y, rt.cur->col.z);
//	printf("\n1: size = %lf\n", rt.cur->size);
//	printf("\n1: pow = %lf\n", rt.cur->pow);
//	printf("\n2: type = %d\n", rt.cur->next->type);
//	printf("\n2: pos = %lf, %lf, %lf\n", rt.cur->next->pos.x, rt.cur->next->pos.y, rt.cur->next->pos.z);
//	printf("\n2: rot = %lf, %lf, %lf\n", rt.cur->next->rot.x, rt.cur->next->rot.y, rt.cur->next->rot.z);
//	printf("\n2: col = %lf, %lf, %lf\n", rt.cur->next->col.x, rt.cur->next->col.y, rt.cur->next->col.z);
//	printf("\n2: size = %lf\n", rt.cur->next->size);
//	printf("\n2: pow = %lf\n", rt.cur->next->pow);
//	sleep(3);
	ft_env_init(&rt);
	free(&rt);
	ft_bzero(&rt, sizeof(t_env));
	return (0);
}
