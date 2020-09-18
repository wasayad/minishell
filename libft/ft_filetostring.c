/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_filetostring.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 15:49:38 by sayad        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 13:47:29 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_filetostring(char *str)
{
	char	buff[2];
	int		fd;
	char	*tmp;
	char	*file[2];
	int		ret;

	fd = open(str, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		return (0);
	}
	if (!(*file = ft_strdup("")))
		return ((char *)-1);
	while ((ret = read(fd, buff, 1) > 0))
	{
		buff[1] = '\0';
		if (!(tmp = ft_strjoinf(*file, buff)))
			return ((char *)-1);
		*file = tmp;
	}
	close(fd);
	return (*file);
}
