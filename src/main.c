/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 21:03:28 by roblabla          #+#    #+#             */
/*   Updated: 2016/01/27 18:04:19 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include <mlx.h>
#include "ft_printf.h"
#include "framework_math/fk_vector.h"
#include "framework_collision/fk_collision.h"
#include <stdlib.h>

#define WIDTH 1224
#define HEIGHT 780
int		rt_expose_hook(t_env *env)
{
	ft_render(*env);
	return (0);
}

/*
** TODO : Check segfault
*/
int		main(int argc, char **argv)
{
	t_env	env;

	(void)argc;
	(void)argv;
	env.mlx = mlx_init();
	env.resolution.width = 1224;
	env.resolution.height = 780;
	env.win = mlx_new_window(env.mlx, env.resolution.width, env.resolution.height, "RayTracer");
	env.img.ptr = mlx_new_image(env.mlx, env.resolution.width, env.resolution.height);
	env.img.data = mlx_get_data_addr(env.img.ptr, &env.img.bpp, &env.img.sizeline, &env.img.endianness);
	env.fov = 45;
	env.pos_absolute_camera = (t_vertex3) { 0, 0, 0 };
	env.dir_camera = (t_vector3) { 0, 0, 1 };
	ft_setup_inter(env.fctinter);
	ft_setup_normal(env.fctnormal);
	rt_expose_hook(&env);
	mlx_expose_hook(env.win, rt_expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
