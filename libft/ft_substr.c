/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 16:59:33 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 14:46:25 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (len--)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
