/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 21:12:58 by mbarbari          #+#    #+#             */
/*   Updated: 2016/01/27 18:04:08 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include "framework_shape/fk_listobj.h"
#include "framework_light/fk_normal.h"
#include "framework_light/fk_normal_plan.h"
#include "framework_light/fk_normal_sphere.h"
#include "framework_light/fk_normal_cylinder.h"

void		ft_setup_inter(t_fctinter inter[DEFAULT])
{
	inter[SPHERE] = (t_fctinter)&intersect_sphere;
	inter[PLANE] = (t_fctinter)&intersect_plan;
	inter[CYLINDER] = (t_fctinter)&intersect_cylinder;
	inter[CONE] = NULL;
	inter[DEFAULT] = NULL;
}

void		ft_setup_normal(t_fctnormal normal[DEFAULT])
{
	normal[SPHERE] = (t_fctnormal)&normal_sphere;
	normal[PLANE] = (t_fctnormal)&normal_plan;
	normal[CYLINDER] = (t_fctnormal)&normal_cylinder;
	normal[CONE] = NULL;
	normal[DEFAULT] = NULL;
}
