/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:17:09 by avogt             #+#    #+#             */
/*   Updated: 2021/03/07 14:04:30 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

char	*free_l_parsed(t_light *light, char *s)
{
	free(light);
	light = NULL;
	return (s);
}

char	*free_c_parsed(t_camera *c, char *s)
{
	free(c);
	c = NULL;
	return (s);
}

char	*free_o_parsed(t_object *o, char *s)
{
	free(o);
	o = NULL;
	return (s);
}
