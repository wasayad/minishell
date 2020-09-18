/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 19:48:35 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 15:51:14 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft.h"

int		ft_get_arg_into_string(t_printf *b, int j, va_list ap)
{
	if (b->d[j] == 'c')
		if (!(ft_init_c(b, ap)))
			return (0);
	if (b->d[j] == 's')
		if (!(ft_init_s(b, ap)))
			return (0);
	if (b->d[j] == 'd' || b->d[j] == 'i')
		if (!(ft_init_di(b, ap)))
			return (0);
	if (b->d[j] == 'x')
		if (!(ft_init_x(b, ap)))
			return (0);
	if (b->d[j] == 'X')
		if (!(ft_init_xx(b, ap)))
			return (0);
	if (b->d[j] == 'p')
		if (!(ft_init_p(b, ap)))
			return (0);
	if (b->d[j] == 'u')
		if (!(ft_init_u(b, ap)))
			return (0);
	if (b->d[j] == '%')
		if (!(ft_init_pr(b)))
			return (0);
	return (1);
}

int		ft_sep_arg(va_list ap, t_printf *b)
{
	int		j;

	j = -1;
	while (b->conv[++j] == '0' || b->conv[j] == '-' || b->conv[j] == '*' ||
	b->conv[j] == '.' || (b->conv[j] <= '9' && b->conv[j] >= '0'))
		if (b->conv[j] == '-')
			b->flag_neg = 1;
	j++;
	if (!(b->d = ft_substr(b->conv, 0, j)))
		return (0);
	free(b->conv);
	b->i = b->i + j;
	ft_replace_star_by_number(ap, b);
	ft_check_point(b);
	ft_check_number(b);
	if (b->d[0] == '0' && b->flag_neg == 0)
		b->flag_zero = 1;
	ft_get_arg_into_string(b, j - 1, ap);
	ft_add_string_to_render(b);
	return (1);
}

int		ft_resolve(char *fmt, va_list ap, t_printf *b)
{
	b->i = 0;
	while (fmt[b->i])
	{
		ft_init_flag(b);
		if (fmt[b->i] == '%')
		{
			if (!(b->conv = ft_strdup(fmt + b->i + 1)))
				return (0);
			if (!(ft_sep_arg(ap, b)))
				return (0);
			free(b->d);
		}
		else
		{
			if (!(ft_realloc_c(b, fmt[b->i])))
				return (0);
		}
		b->i++;
	}
	return (1);
}

void	ft_write_str(char *str, t_printf *b, int fd)
{
	int		i;
	char	c;

	i = 0;
	c = '\0';
	b->len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == -1 && ft_check_tab(b, i) == 0)
		{
			write(fd, &c, 1);
		}
		else
		{
			write(fd, &str[i], 1);
		}
		i++;
	}
}

int		ft_printf(int fd, const char *fmt, ...)
{
	va_list			ap;
	t_printf		*b;
	size_t			i;

	b = init_structing();
	if (fmt == NULL)
		return (0);
	va_start(ap, fmt);
	if (ft_strchr(fmt, '%') == NULL)
	{
		ft_write_str((char *)fmt, b, fd);
	}
	else
	{
		if (!(ft_resolve((char *)fmt, ap, b)))
			return (0);
		ft_write_str(b->str, b, fd);
	}
	va_end(ap);
	i = b->len;
	free(b->index_0);
	free(b->str);
	free(b);
	return (i);
}
