/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 17:36:50 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 14:43:07 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(const char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
		i++;
	return (i);
}

static char		*ft_strmalloc(const char *s, int n)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_len(s, n) + 1))))
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int		ft_check(char c, const char *sep)
{
	size_t		i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	if (!(s1))
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_check(s1[i], set) && s1[i])
		i++;
	if (i - 1 == j)
	{
		if (!(str = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		return (str);
	}
	while (ft_check(s1[j], set))
		j--;
	size = (j - i) + 1;
	if (!(str = ft_strmalloc((s1 + i), size)))
		return (NULL);
	return (str);
}
