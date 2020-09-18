/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_norme.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 15:59:08 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 16:42:17 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft.h"

void		ft_init_flag(t_printf *b)
{
	b->flag_point = 0;
	b->flag_star = 0;
	b->flag_neg = 0;
	b->flag_zero = 0;
	b->len = 0;
	b->accu = -1;
	b->width = 0;
	b->addcheck = 0;
	b->addsymb = NULL;
}

t_printf	*init_structing(void)
{
	t_printf *b;

	if (!(b = malloc(sizeof(t_printf) * 1)))
		return (NULL);
	b->len = 0;
	b->i = 0;
	if (!(b->str = ft_calloc(sizeof(char), 1)))
		return (0);
	if (!(b->index_0 = malloc(sizeof(int) * 1)))
		return (0);
	b->index_0[0] = -1;
	return (b);
}
