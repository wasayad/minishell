/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base_address.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 11:06:44 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 16:09:20 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizenumber(unsigned long long n, char *base)
{
	int						cmpt;
	unsigned long long		result;

	cmpt = 0;
	result = n;
	while (result >= (unsigned long long)ft_strlen(base))
	{
		result = result / ft_strlen(base);
		cmpt++;
	}
	if (result < (unsigned long long)ft_strlen(base))
		cmpt++;
	return (cmpt);
}

char		*ft_itoa_base_address(unsigned long long n, char *base)
{
	unsigned long long	cmpt;
	char				*nb_str;

	cmpt = ft_sizenumber(n, base);
	if (!(nb_str = malloc(sizeof(char) * ft_sizenumber(n, base) + 1)))
		return (NULL);
	nb_str[cmpt--] = '\0';
	if (n == 0)
	{
		nb_str[0] = base[0];
		return (nb_str);
	}
	while (cmpt > 0)
	{
		nb_str[cmpt--] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	nb_str[cmpt--] = base[n % ft_strlen(base)];
	return (nb_str);
}
