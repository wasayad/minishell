/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:45:49 by pbesson           #+#    #+#             */
/*   Updated: 2021/02/02 16:19:03 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
static int		check_var_01(t_minishell *ms, int j)
{
	int		i;

	i = 0;
	while (ms->command_tab[j][i] && ms->command_tab[j][i] != '=')
		i++;
	if (i == 0)
	{
		ft_printf("wrong ID\n");
		return (0);
	}
	if (ms->command_tab[j][i] != '\0')
	{
		if (!(ft_isalnum(ms->command_tab[j][i - 1])) && ms->command_tab[j][i - 1] != '_')
		{
			ft_printf("wrong ID\n");
			return (0);
		}
	}
	return (1);
}

static int		check_var(t_minishell *ms, int j)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (ms->command_tab[j][i] && ms->command_tab[j][i++] != '=')
		if (!(ft_isalnum(ms->command_tab[j][i])) && ms->command_tab[j][i] != '=' &&
			ms->command_tab[j][i] != '_' && ms->command_tab[j][i] != ' ')
		{
			ft_printf("wrong ID\n");
			return (0);
		}
	i = 0;
	while (ms->command_tab[j][i++])
		if (ms->command_tab[j][i] == '=')
			count++;
	if (count == 0)
		return (0);
	return (check_var_01(ms, j));
}

static char	*ft_get_var(t_minishell *ms, int k)
{
	int		i;
	int		j;

	i = 0;
	while (ms->command_tab[k][i] && ms->command_tab[k][i] != '=')
		i++;
	j = i - 1;
	while (j > 0 && ft_isalnum(ms->command_tab[k][j]))
		j--;
	if (j != 0)
		j++;
	return (ft_substr(ms->command_tab[k], j, i - j));
}

char	*ft_get_content(t_minishell *ms, int k)
{
	int		i;
	int		j;

	i = 0;
	while (ms->command_tab[k][i] && ms->command_tab[k][i++] != '=')
		str_remove_index(0, ms);
	j = 0;
	while (ms->command_tab[k][j] && ms->command_tab[k][j] != ' ')
		j++;
	return (ft_substr(ms->command_tab[k], i, j - i));
}

void	ft_no_new_var(t_minishell *ms)
{
	t_env_var	*scroll_var;

	scroll_var = ms->ev->next_var;
	free(ms->line);
	ms->line = ft_strdup("");
	while (scroll_var->next_var)
	{
		ms->line = ft_strjoin_free_s1(ms->line, "declare -x ");
		ms->line = ft_strjoin_free_s1(ms->line, scroll_var->var);
		ms->line = ft_strjoin_free_s1(ms->line, "=\"");
		ms->line = ft_strjoin_free_s1(ms->line, scroll_var->content);
		ms->line = ft_strjoin_free_s1(ms->line, "\"\n");
		scroll_var = scroll_var->next_var;
	}
	ms->line = ft_strjoin_free_s1(ms->line, "declare -x ");
	ms->line = ft_strjoin_free_s1(ms->line, scroll_var->var);
	ms->line = ft_strjoin_free_s1(ms->line, "=\"");
	ms->line = ft_strjoin_free_s1(ms->line, scroll_var->content);
	ms->line = ft_strjoin_free_s1(ms->line, "\"\n");
}

int		ft_export(t_minishell *ms, int i)
{
	if (ms->command_tab[i][0] == '\0')
	{
		ft_no_new_var(ms);
	}
	else if (check_var(ms, i))
	{
		t_env_var	*temp;
		t_env_var	*scroll_var;

		if (!(temp = malloc(sizeof(t_env_var) * 1)))
			ft_exit(ms);
		scroll_var = ms->ev->next_var;
		if (!(temp->var = ft_get_var(ms, i)))
			ft_exit(ms);
		if (ms->ev->next_var)
		{
			while (scroll_var->next_var != NULL)
			{
				if (ft_strcmp(scroll_var->var, temp->var) == 0)
				{
					free(scroll_var->content);
					if (!(scroll_var->content = ft_get_content(ms, i)))
						ft_exit(ms);
					free(temp->var);
					free(temp);
					return (1);
				}
				scroll_var = scroll_var->next_var;
			}
			if (ft_strcmp(scroll_var->var, temp->var) == 0)
			{
				if (!(scroll_var->content = ft_get_content(ms, i)))
					ft_exit(ms);
				free(temp->var);
				free(temp);
				return (1);
			}
		}
		//************************
		if (!(temp->content = ft_get_content(ms, i)))
			ft_exit(ms);
		scroll_var->next_var = temp;
		temp->prev_var = scroll_var;
		temp->next_var= NULL;
	}
	return (1);
}
