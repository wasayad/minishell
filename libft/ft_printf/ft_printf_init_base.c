/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_init_base.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 15:03:45 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 16:42:06 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft.h"

int		ft_init_x(t_printf *b, va_list ap)
{
	unsigned int		j;

	j = va_arg(ap, unsigned int);
	if (j == 0 && b->accu == 0)
	{
		if (!(b->actual = ft_strdup("")))
			return (0);
	}
	else
	{
		if (!(b->actual = ft_itoa_base(j, "0123456789abcdef")))
			return (0);
	}
	if (b->accu >= 0)
		b->flag_zero = 0;
	return (1);
}

int		ft_init_xx(t_printf *b, va_list ap)
{
	unsigned int		j;

	j = va_arg(ap, unsigned int);
	if (j == 0 && b->accu == 0)
	{
		if (!(b->actual = ft_strdup("")))
			return (0);
	}
	else
	{
		if (!(b->actual = ft_itoa_base(j, "0123456789ABCDEF")))
			return (0);
	}
	if (b->accu >= 0)
		b->flag_zero = 0;
	return (1);
}

int		ft_init_p(t_printf *b, va_list ap)
{
	unsigned long long		j;

	j = va_arg(ap, unsigned long long);
	if (j == 0 && b->accu == 0)
	{
		if (!(b->actual = ft_strdup("0x")))
			return (0);
	}
	else
	{
		if (!(b->temp = ft_itoa_base_address(j, "0123456789abcdef")))
			return (0);
		if (!(b->actual = ft_strjoin("0x", b->temp)))
			return (0);
		free(b->temp);
	}
	if (b->accu >= 0)
		b->flag_zero = 0;
	return (1);
}
