/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 11:30:30 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 15:50:21 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp;
	unsigned char	*temp1;

	temp1 = (unsigned char *)s1;
	temp = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 1 && *temp1 == *temp)
	{
		temp1++;
		temp++;
		n--;
	}
	if (*temp1 == '\0' && *temp == '\0')
		return (0);
	return (*temp1 - *temp);
}
