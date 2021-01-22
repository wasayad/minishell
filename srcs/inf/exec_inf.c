/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_inf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasayad <wasayad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:44:55 by wasayad           #+#    #+#             */
/*   Updated: 2021/01/22 16:11:41 by wasayad          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			get_command(t_minishell *ms, int i)
{
	int j;

	i = 0;
	j = 0;
	while (ms->line[i] && ms->line[i] == ' ')
		i++;
	j = i;
	while (ms->line[j] && ms->line[j] != ' ')
		j++;
	if (!(ms->command = ft_substr(ms->line, i, j - i)))
		return (0);
	while (ms->line[j] && ms->line[j] == ' ')
		j++;
	if (!(ms->line = ft_substr_free(ms->line, j, ft_strlen(ms->line))))
		return (0);
	return (1);
}

void	get_path_arg(t_minishell *ms)
{
	t_env_var	*temp;
	char		**path;
	int			i;
	char		*tempo;
	int			id;

	i = -1;
	temp = ms->ev;
	while (temp->last != 1 && ft_strcmp(temp->var, "PATH") != 0)
		temp = temp->next_var;
	path = ft_split(temp->content, ':');
	while (path[++i])
	{
		tempo = ft_strjoin(path[i], "/");
		tempo = ft_strjoin_free_s1(tempo, ms->command);
		id = open(tempo, O_RDONLY);
		if (id > 0)
			break ;
		close(id);
		free(tempo);
	}
	ms->line = ft_strjoin_free_s2(" ", ms->line);
	ms->line = ft_strjoin_free_s2(ms->command, ms->line);
	ms->argv = ft_split(ms->line, ' ');
	ms->argv[0] = tempo;
}

static void	try_exec_read(t_minishell *ms)
{
	int		ret;
	char	*buffer;

	buffer = malloc(sizeof(char *) * 10000);
	free(ms->line);
	ms->line = ft_strdup("");
	close(ms->pfd[1]);
	while (((ret = read(ms->pfd[0], buffer, 1023)) > 0))
	{
		buffer[ret] = 0;
		ms->line = ft_strjoin_free_s1(ms->line, buffer);
	}
	close(ms->pfd[0]);
	free(buffer);
}
static void	try_exec(t_minishell *ms)
{
	int		id;

	get_path_arg(ms);
	pipe(ms->pfd);
	id = fork();
	if (id == 0)
	{
		close(ms->pfd[0]);
		dup2(ms->pfd[1], 1);
		execve(ms->argv[0], ms->argv, NULL);
	}
	else
	{
		try_exec_read(ms);
	}
}

void	get_different_option(t_minishell *ms, int i)
{
	i = 0;
	if (!(get_command(ms, i)))
		ft_exit(ms);
	if (ft_strcmp(ms->command, "echo") == 0)
		get_echo(ms);
	else if (ft_strcmp(ms->command, "pwd") == 0)
		ft_pwd(ms);
	else if (ft_strcmp(ms->command, "cd") == 0)
		ft_cd(ms);
	else if (ft_strcmp(ms->command, "exit") == 0)
		check_exit(ms);
	else if (ft_strcmp(ms->command, "export") == 0)
		ft_export(ms);
	else if (ft_strcmp(ms->command, "unset") == 0)
		ft_unset(ms);
	else if (ft_strcmp(ms->command, "env") == 0)
		ft_env(ms);
	else
		try_exec(ms);
}
