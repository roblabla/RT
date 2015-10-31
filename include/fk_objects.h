/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_objects.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:32:17 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/29 19:04:15 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_OBJECTS_H
# define FK_OBJECTS_H

typedef struct		s_objects t_objects;
typedef struct		s_sphere t_sphere;
typedef struct		s_ray t_ray;

typedef float		*(*t_intersect)(t_ray ray);

typedef enum		e_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
};

struct				s_objects
{
	e_type			type;
	void			*object;
	t_material		material;
	t_objects		*nextobj;
};

struct				s_sphere
{
	t_vector3		position;
	float			radius;
	t_intersect		intersect;
};

struct				s_plane
{
	t_vector3		position;
	float			radius;
	t_intersect		intersect;
};

struct				s_cylinder
{
	t_vector3		position;
	float			radius;
	t_intersect		intersect;
};

struct				s_cone
{
	t_vector3		position;
	float			radius;
	t_intersect		intersect;
};

struct				s_ray
{
	t_vector3		position;
	t_vector3		direction;
};

#endif