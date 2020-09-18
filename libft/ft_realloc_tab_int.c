/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc_tab_int.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 21:24:30 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 16:43:41 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_tab(t_printf *b, int j)
{
	int		i;

	i = 0;
	while (b->index_0[i] != -1)
	{
		if (b->index_0[i] == j)
			return (0);
		i++;
	}
	return (1);
}

int		ft_realloc_tab_int(t_printf *b, int index)
{
	int		i;
	int		*j;

	i = 0;
	while (b->index_0[i] != -1)
		i++;
	if (!(j = malloc(sizeof(int *) * (i + 2))))
		return (0);
	i = 0;
	while (b->index_0[i] != -1)
	{
		j[i] = b->index_0[i];
		i++;
	}
	j[i] = index;
	j[i + 1] = -1;
	free(b->index_0);
	if (!(b->index_0 = malloc(sizeof(int *) * (i + 1))))
		return (0);
	i = -1;
	while (j[++i] != -1)
		b->index_0[i] = j[i];
	b->index_0[i] = -1;
	free(j);
	return (1);
}
