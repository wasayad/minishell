/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sayad <sayad@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:20:01 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/13 04:03:05 by sayad       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < ((int)size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	if (size < ft_strlen(src))
		return (ft_strlen(src));
	return (ft_strlen((char *)src));
}
