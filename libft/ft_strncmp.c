/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:08:32 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 13:08:00 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str, const char *str3, size_t len)
{
	int					i;
	int					l;
	const unsigned char *str1;
	const unsigned char *str2;

	str1 = (const unsigned char *)str;
	str2 = (const unsigned char *)str3;
	l = (int)len;
	i = 0;
	if (l == 0)
		return (0);
	while (str1[i] && str2[i]
			&& l > 1 && str1[i] == str2[i])
	{
		i++;
		l--;
	}
	return (str1[i] - str2[i]);
}
