/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasayad <wasayad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:20:08 by akerdeka          #+#    #+#             */
/*   Updated: 2021/02/08 17:22:22 by wasayad          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_cd_errors(t_minishell *ms)
{
	if (errno == 2)
		ft_printf("No such file or directory.\n");
	if (errno == 13)
		ft_printf("Permission denied.\n");
	if (errno == 14)
		ft_printf("Bad address.\n");
	if (errno == 20)
		ft_printf("%s is not a directory.\n", ms->line);
	errno = 0;
	ft_strdel_free(&(ms->line));
	ms->line = ft_strdup("");
}

int			ft_cd(t_minishell *ms, int j)
{
	int		i;
	char	*str;
	t_env_var *temp;

	i = -1;
	if (!(str = malloc(sizeof(char*) * (ft_strlen(ms->command_tab[j]) + 1))))
		ft_exit(ms);
	str[0] = '\0';
	while (ms->command_tab[j][++i])
	{
		while (ms->command_tab[j][i] == ' ')
		{
			if (ms->command_tab[j][i + 1] != ' ' && ms->command_tab[j][i + 1] != '\0')
			{
				ft_printf("Too much arguments.\n");
				free(str);
				return (0);
			}
			i++;
		}
		str[i] = ms->command_tab[j][i];
	}
	temp = ms->ev->next_var;
	if (str[0] == '\0')
	{
		while (temp->next_var)
		{
			if (ft_strcmp(temp->var, "HOME") == 0)
				break ;
			temp = temp->next_var;
		}
		chdir(temp->content);
		ft_cd_errors(ms);
		return (0);
	}
	str[i] = '\0';
	chdir(str);
	free(str);
	ft_cd_errors(ms);
	return (1);
}
