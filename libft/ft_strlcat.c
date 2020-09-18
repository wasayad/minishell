/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:02:12 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 11:44:47 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;

	len = ft_strlen(dst);
	i = 0;
	if (len > size)
		return (ft_strlen(src) + size);
	while (size - len > 1 && src[i])
	{
		dst[len + i] = src[i];
		size--;
		i++;
	}
	dst[len + i] = '\0';
	return (ft_strlen(src) + len);
}
