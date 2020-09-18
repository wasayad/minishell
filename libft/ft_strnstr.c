/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/08 18:16:16 by sayad        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 15:58:08 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i])
	{
		while (big[i + j] == little[j] &&
			big[i + j] && little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
