/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 19:29:45 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 14:19:19 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*d;
	int				i;

	i = 0;
	d = (char *)s;
	while (n)
	{
		if (d[i] == c)
			return (d + i);
		i++;
		n--;
	}
	return (0);
}
