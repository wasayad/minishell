/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 11:56:01 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 16:25:20 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*str;
	const char		*str1;
	char			*str1temp;
	char			*strtemp;

	str1 = src;
	str = dst;
	if (src == NULL && dst == NULL && len != 0)
		return (0);
	if (str < str1)
	{
		while (len--)
			*str++ = *str1++;
	}
	else
	{
		str1temp = (char *)str1 + (len - 1);
		strtemp = str + (len - 1);
		while (len--)
			*strtemp-- = *str1temp--;
	}
	return (dst);
}
