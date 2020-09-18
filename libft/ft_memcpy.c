/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:14:38 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 19:40:22 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char			*temp;
	unsigned char			*temp1;
	int						i;

	i = 0;
	if (src == NULL && dest == NULL && len != 0)
		return (0);
	temp1 = (unsigned char *)src;
	temp = (unsigned char *)dest;
	if (len == 0)
		return (dest);
	while (i < (int)len)
	{
		temp[i] = temp1[i];
		i++;
	}
	return (dest);
}
