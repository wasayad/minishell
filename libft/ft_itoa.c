/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 14:57:26 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 13:03:33 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int nbr)
{
	long	nb;
	int		size;
	char	*str;
	long	n;

	n = nbr;
	size = 1;
	nb = (long)n;
	n < 0 ? n = -n : n;
	nbr < 0 ? size = size + 1 : size;
	while ((n = n / 10) > 0)
		size++;
	if (!(str = ft_calloc(sizeof(char), (size + 1))))
		return (0);
	if ((nb = -nb) > 0)
		str[0] = '-';
	nb < 0 ? nb = -nb : nb;
	while (nb >= 10)
	{
		str[--size] = (nb % 10) + '0';
		nb = nb / 10;
	}
	str[--size] = (nb % 10) + '0';
	return (str);
}
