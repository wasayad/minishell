/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_manage_conv.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 15:09:23 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 16:41:59 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft.h"

int		manage_neg(t_printf *b)
{
	int		i;

	i = b->accu > (int)ft_strlen(b->actual) ? 
	b->accu : (int)ft_strlen(b->actual);
	if (b->addcheck == 1)
		if (!(b->str = ft_strjoinf(b->str, b->addsymb)))
			return (0);
	while (b->accu > (int)ft_strlen(b->actual))
	{
		if (!(b->str = ft_strjoinf(b->str, "0")))
			return (0);
		b->accu--;
	}
	if (!(b->str = ft_strjoinf(b->str, b->actual)))
		return (0);
	while (b->width > i)
	{
		if (!(b->str = ft_strjoinf(b->str, " ")))
			return (0);
		b->width--;
	}
	free(b->actual);
	return (1);
}

int		manage_zero(t_printf *b)
{
	if (b->addcheck == 1)
		if (!(b->str = ft_strjoinf(b->str, b->addsymb)))
			return (0);
	while (b->width > (int)ft_strlen(b->actual))
	{
		if (!(b->str = ft_strjoinf(b->str, "0")))
			return (0);
		b->width--;
	}
	if (!(b->str = ft_strjoinf(b->str, b->actual)))
		return (0);
	free(b->actual);
	return (1);
}

int		manage_no_flag(t_printf *b)
{
	int		i;

	i = b->accu > (int)ft_strlen(b->actual) ? 
	b->accu : (int)ft_strlen(b->actual);
	while (b->width > i)
	{
		if (!(b->str = ft_strjoinf(b->str, " ")))
			return (0);
		b->width--;
	}
	if (b->addcheck == 1)
		if (!(b->str = ft_strjoinf(b->str, b->addsymb)))
			return (0);
	while (b->accu > (int)ft_strlen(b->actual))
	{
		if (!(b->str = ft_strjoinf(b->str, "0")))
			return (0);
		b->accu--;
	}
	if (!(b->str = ft_strjoinf(b->str, b->actual)))
		return (0);
	free(b->actual);
	return (1);
}

int		ft_add_string_to_render(t_printf *b)
{
	if (b->flag_neg == 1)
	{
		if (!(manage_neg(b)))
			return (0);
	}
	if (b->flag_neg == 0 && b->flag_zero == 1)
	{
		if (!(manage_zero(b)))
			return (0);
	}
	if (b->flag_neg == 0 && b->flag_zero == 0)
	{
		if (!(manage_no_flag(b)))
			return (0);
	}
	free(b->addsymb);
	return (1);
}
