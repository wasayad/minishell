/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 18:03:49 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 15:48:31 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizenumber(long long n, char *base)
{
	int				cmpt;
	long long		result;

	cmpt = 0;
	result = n;
	if (n < 0)
	{
		cmpt++;
		result *= -1;
	}
	while (result >= (long)ft_strlen(base))
	{
		result = result / ft_strlen(base);
		cmpt++;
	}
	if (result < (long)ft_strlen(base))
		cmpt++;
	return (cmpt);
}

char		*ft_itoa_base(long long n, char *base)
{
	long long	cmpt;
	char		*nb_str;

	cmpt = ft_sizenumber(n, base);
	if (!(nb_str = malloc(sizeof(char) * ft_sizenumber(n, base) + 1)))
		return (NULL);
	nb_str[cmpt--] = '\0';
	if (n == 0)
	{
		nb_str[0] = base[0];
		return (nb_str);
	}
	if (n < 0)
	{
		nb_str[0] = '-';
		n *= -1;
	}
	while (cmpt >= 0)
	{
		nb_str[cmpt--] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (nb_str);
}
