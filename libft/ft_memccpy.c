/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 17:03:15 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 16:23:41 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	unsigned char		*temp;
	unsigned char		*temp1;
	int					i;

	i = 0;
	temp1 = (unsigned char *)src;
	temp = (unsigned char *)dest;
	while (i < (int)len)
	{
		temp[i] = temp1[i];
		if (temp1[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	if ((unsigned char)c == '\0' && len != 0)
		return (dest + i);
	return (0);
}
