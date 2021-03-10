/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:01:39 by avogt             #+#    #+#             */
/*   Updated: 2021/03/07 18:52:05 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	counter;

	counter = 0;
	while (counter < len)
		((char *)b)[counter++] = (unsigned char)c;
	return (b);
}
