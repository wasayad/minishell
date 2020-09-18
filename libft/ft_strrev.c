/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 15:40:26 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 15:40:41 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	swap;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	i--;
	while (j < i - 1)
	{
		swap = str[j];
		str[j] = str[i];
		str[i] = swap;
		j++;
		i--;
	}
	return (str);
}
