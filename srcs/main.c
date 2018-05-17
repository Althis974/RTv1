/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 11:50:57 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 16:44:39 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_initialization(t_env *rt)
{
	rt->cam.ori = (t_vec){0.0, 0.0, 0.0};
	rt->cam.dir = (t_vec){5.0, 0.0, 10.0};
	rt->cur = malloc(sizeof(t_obj));
	rt->cur->next = malloc(sizeof(t_obj));
	rt->cur->type = 4;
	rt->cur->pos = (t_vec){25.0, 1.0, 0.0};
	rt->cur->pow = 100;
	rt->cur->next->type = 1;
	rt->cur->next->col = (t_vec){192.0, 192.0, 192.0};
	rt->cur->next->size = 50;
	rt->cur->next->pos = (t_vec){5.0, 0.0, 10.0};
	rt->cur->next->next = NULL;
}

int		main(int ac, char **av)
{
	t_env rt;

	if (ac != 2)
		write(2, "usage : ./rtv1 <scene>\n", 23);
	printf("\n%s\n", av[0]);
	ft_bzero(&rt, sizeof(t_env));
	ft_initialization(&rt);
	printf("\n%d\n", rt.cur->type);
	printf("\n%d\n", rt.cur->next->type);
	ft_env_init(&rt);
	free(&rt);
	ft_bzero(&rt, sizeof(t_env));
	return (0);
}
