/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:49:12 by tcohen            #+#    #+#             */
/*   Updated: 2024/05/24 13:19:44 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		dst_len = dstsize;
	if (dst_len == dstsize)
		return (dstsize + src_len);
	i = 0;
	if (src_len < (dstsize - dst_len))
		ft_memcpy((dst + dst_len), src, src_len + 1);
	else
	{
		ft_memcpy((dst + dst_len), src, dstsize - dst_len -1);
		dst[dstsize - 1] = '\0';
	}
	return (dst_len + src_len);
}
