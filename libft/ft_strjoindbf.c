/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoindbf.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sayad <sayad@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 18:40:05 by sayad        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 18:40:27 by sayad       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoindbf(char *s1, char *s2)
{
	int				i;
	int				j;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	j = 0;
	ft_strcpy(str, s1);
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}
