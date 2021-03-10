/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:55:38 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 17:21:31 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*fresh;
	unsigned int	i;

	fresh = NULL;
	i = 0;
	if (s == NULL)
		return (fresh);
	fresh = (char *)malloc(sizeof(char) * (len + 1));
	if (!(fresh))
		return (NULL);
	while (i < len)
		fresh[i++] = s[start++];
	fresh[i] = '\0';
	return (fresh);
}
