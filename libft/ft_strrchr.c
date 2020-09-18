/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 18:57:08 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 11:45:02 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;
	int d;

	d = 0;
	i = 0;
	while (str[d])
	{
		if (str[d] == c)
			i = 0;
		d++;
		i++;
	}
	if (str[d - i] == c)
		return ((char *)str + (d - i));
	if (str[d] == c)
		return ((char *)str + d);
	return (0);
}
