/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_init.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 15:01:06 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 16:42:12 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft.h"

int		ft_init_pr(t_printf *b)
{
	if (!(b->actual = ft_strdup("%")))
		return (0);
	b->accu = 0;
	return (1);
}

int		ft_init_c(t_printf *b, va_list ap)
{
	int			c;

	c = va_arg(ap, int);
	if (!(b->actual = malloc(sizeof(char *) * 2)))
		return (0);
	if (c == 0)
	{
		if (b->flag_neg == 1)
			if (!(ft_realloc_tab_int(b, ft_strlen(b->str))))
				return (0);
		if (b->flag_neg == 0)
		{
			if (b->width >= 1)
				if (!(ft_realloc_tab_int(b, ft_strlen(b->str) + b->width - 1)))
					return (0);
			if (b->width < 1)
				if (!(ft_realloc_tab_int(b, ft_strlen(b->str))))
					return (0);
		}
		b->actual[0] = -1;
	}
	else
		b->actual[0] = c;
	b->actual[1] = '\0';
	return (1);
}

int		ft_init_s(t_printf *b, va_list ap)
{
	if (!(b->temp = ft_strdup(va_arg(ap, char *))))
		return (0);
	if (b->temp == NULL)
	{
		if (!(b->actual = ft_substr("(null)", 0, b->accu)))
			return (0);
	}
	else
	{
		if (b->accu < 0)
		{
			if (!(b->actual = ft_strdup(b->temp)))
				return (0);
		}
		else
		{
			if (!(b->actual = ft_substr(b->temp, 0, b->accu)))
				return (0);
		}
	}
	b->accu = 0;
	free(b->temp);
	return (1);
}

int		ft_init_di(t_printf *b, va_list ap)
{
	long		j;

	j = va_arg(ap, int);
	if (j < 0)
	{
		j = -1 * j;
		b->addcheck = 1;
		b->width--;
		if (!(b->addsymb = ft_strdup("-")))
			return (0);
	}
	if (j == 0 && b->accu == 0)
	{
		if (!(b->actual = ft_strdup("")))
			return (0);
	}
	else
	{
		if (!(b->actual = ft_itoa(j)))
			return (0);
	}
	if (b->accu >= 0)
		b->flag_zero = 0;
	return (1);
}

int		ft_init_u(t_printf *b, va_list ap)
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
		if (!(b->actual = ft_itoa(j)))
			return (0);
	}
	if (b->accu >= 0)
		b->flag_zero = 0;
	return (1);
}
