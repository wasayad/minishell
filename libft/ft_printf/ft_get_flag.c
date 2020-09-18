/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_flag.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 15:06:14 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 16:41:54 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft.h"

void		ft_check_point(t_printf *b)
{
	int		i;

	i = 0;
	while (b->d[i] && b->d[i] != '.')
		i++;
	if (b->d[i] == '.')
	{
		if (b->d[i + 1] != '*')
			b->accu = ft_atoi(b->d + i + 1);
		if (i > 0 && b->d[i - 1] != '*')
		{
			i--;
			while ((i > 0 && (b->d[i] >= '0' &&
			b->d[i] <= '9')))
				i--;
			b->width = ft_atoi_width(b->d + i);
			if (b->width < 0)
			{
				b->width = -1 * b->width;
				b->flag_neg = 1;
			}
		}
	}
}

void		ft_replace_star_by_number(va_list ap, t_printf *b)
{
	int		i;
	int		va;

	i = -1;
	while (b->d[++i])
	{
		if (b->d[i] == '*')
		{
			va = va_arg(ap, int);
			if (i > 0 && b->d[i - 1] == '.')
			{
				b->accu = va;
			}
			else
			{
				if (va < 0)
				{
					b->flag_neg = 1;
					va = -1 * va;
				}
				b->width = va;
			}
			b->flag_star = 1;
		}
	}
}

int			ft_check_number(t_printf *b)
{
	int		i;

	i = 0;
	while (b->d[i] && b->d[i] != '*' && b->d[i] != '.')
		i++;
	i--;
	if (i <= 0 || (ft_strchr("csdixXpu%", b->d[i])) == NULL)
		return (0);
	i = 0;
	while (b->d[i] && (b->d[i] == '-' || b->d[i] == '0'))
		i++;
	b->width = ft_atoi(b->d + i);
	return (1);
}
