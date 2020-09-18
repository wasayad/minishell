/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_width.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 20:48:48 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 16:09:41 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_width(const char *str)
{
	int			i;
	long		res;

	res = 0;
	i = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	while (*str && *str == '-')
	{
		i = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = (res * 10) + *str - 48;
		str++;
	}
	return (res * i);
}
