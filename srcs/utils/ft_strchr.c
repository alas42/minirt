/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:47:35 by avogt             #+#    #+#             */
/*   Updated: 2021/03/07 18:51:47 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

char	*ft_strchr(const char *s, int c)
{
	int		counter;
	char	*ptr;

	counter = 0;
	ptr = (char *)s;
	while (s[counter] != '\0')
	{
		if (s[counter] == c)
			return (ptr);
		counter++;
		ptr++;
	}
	if (s[counter] == c)
		return (ptr);
	return (NULL);
}
