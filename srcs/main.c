#include "../includes/minishell.h"

int		ft_find_equal(char *envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (envp[i] == '=')
			return(i);
		i++;
	}
	return (0);
}

void	ft_init_env_var(t_minishell *ms)
{
	int		i;
	t_env_var *temp;
	t_env_var *actual;

	i = 0;
	if (!(ms->ev = malloc(sizeof(t_env_var) * 1)))
			ft_exit(ms);
	ms->ev->var = ft_substr(ms->envp[i], 0, ft_find_equal(ms->envp[i]));
	ms->ev->content = ft_substr(ms->envp[i], ft_find_equal(ms->envp[i]) + 1, ft_strlen(ms->envp[i]) - ft_find_equal(ms->envp[i]));
	ms->ev->last = 0;
	i++;
	ms->ev->first_var = ms->ev;
	actual = ms->ev;
	while (ms->envp[i])
	{
		if (!(temp = malloc(sizeof(t_env_var) * 1)))
			ft_exit(ms);
		temp->var = ft_substr(ms->envp[i], 0, ft_find_equal(ms->envp[i]));
		temp->content = ft_substr(ms->envp[i], ft_find_equal(ms->envp[i]) + 1, ft_strlen(ms->envp[i]) - ft_find_equal(ms->envp[i]));
		temp->last = 0;
		if (i > 0)
		{
			actual->next_var = temp;
			actual->first_var = ms->ev;
			temp->prev_var = actual;
			actual = actual->next_var;
		}
		if (ms->envp[i + 1] == NULL)
			actual->last = 1;
		i++;
	}
}

void	ft_init(t_minishell *ms)
{
	ms->line = NULL;
    ms->command = NULL;
    ms->current_workdir = NULL;
	ms->return_value = 0;
	get_next_line(1, NULL); //à vérifier
	ft_init_env_var(ms);
}

int		get_command(t_minishell *ms)
{
	int i;
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
	if (!(ms->line = ft_substr_free(ms->line, j , ft_strlen(ms->line))))
		return (0);
	return (1);
}

void	get_path_arg(t_minishell *ms)
{
	t_env_var *temp;

	temp = ms->ev;

	while (temp->last != 1 && ft_strcmp(temp->var, "PATH") != 0)
	{
		temp = temp->next_var;
	}
	ms->line = ft_strjoin_free_s2(" ", ms->line);
	ms->line = ft_strjoin_free_s2(ms->command, ms->line);
	ms->argv = ft_split(ms->line, ' ');
	ms->argv[0] = ft_strjoin_free_s2("/bin/", ms->argv[0]);
}

void	try_exec(t_minishell *ms)
{
	int		id;
	int		ret;
	char	*buffer;

	get_path_arg(ms);
	buffer = malloc(sizeof(char *) * 10000);
	pipe(ms->pfd);
	id = fork();
	if(id == 0)
	{
		close(ms->pfd[0]);
		dup2(ms->pfd[1], 1);
		execve(ms->argv[0], ms->argv, NULL);
	}
	else
	{
		free(ms->line);
		ms->line = ft_strdup("");
		close(ms->pfd[1]);
		while (((ret = read(ms->pfd[0], buffer, 1023)) > 0))
		{
				ft_printf("%s\n", buffer);
			buffer[ret] = 0;
			ms->line = ft_strjoin_free_s1(ms->line, buffer);
		}
		close(ms->pfd[0]);
	}
	free(buffer);
}
void	get_different_option(t_minishell *ms, int i)
{
	i = i;
	if (!(get_command(ms)))
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

void	manage_pipe(t_minishell *ms, int i)
{
	int		j;

	j = 0;
	ms->command_pipe = ft_split(ms->command_tab[i], -54);
	while (ms->command_pipe[j])
	{
		ft_printf("%s\n", ms->command_pipe[j]);
		j++;
	}
}

void	manage_inf(t_minishell *ms, int i)
{
	int		j;
	int		k;

	j = 1;
	k = 0;
	if (ft_strchr(ms->command_tab[i], -51))
	{
		if (!(ms->command_inf = ft_split(ms->command_tab[i], -51)))
			ft_exit(ms);
		free(ms->line);
		ms->line = ms->command_inf[0];
		get_different_option(ms, i);
		while (ms->command_inf[j])
		{
			k = 0;
			while (ms->command_inf[j][i] && ms->command_inf[j][k] == ' ')				
				k++;
			ms->fd = open(ms->command_inf[j] + k, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |  S_IROTH);
			if (ms->command_inf[j + 1] == NULL)
				write(ms->fd, ms->line, ft_strlen(ms->line));
			close(ms->fd);
			j++;
		}
	}
	else if (ft_strchr(ms->command_tab[i], -52))
	{
		if (!(ms->command_inf = ft_split(ms->command_tab[i], -52)))
			ft_exit(ms);
		free(ms->line);
		ms->line = ms->command_inf[0];
	}
	else if (ft_strchr(ms->command_tab[i], -53))
	{
		if (!(ms->command_inf = ft_split(ms->command_tab[i], -53)))
			ft_exit(ms);
		free(ms->line);
		ms->line = ms->command_inf[0];
		get_different_option(ms, i);
		while (ms->command_inf[j])
		{
			k = 0;
			while (ms->command_inf[j][i] && ms->command_inf[j][k] == ' ')				
				k++;
			ms->fd = open(ms->command_inf[j] + k, O_WRONLY | O_CREAT | O_APPEND,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |  S_IROTH);
			if (ms->command_inf[j + 1] == NULL)
				write(ms->fd, ms->line, ft_strlen(ms->line));
			close(ms->fd);
			j++;
		}
	}
	ft_strdel(ms->line);
	j = 0;
	// while (ms->command_inf[j])
	// {
	// 	ft_strdel(ms->command_inf[j]);
	// }
	// ft_strdel(ms->command_inf[j]);
	// ft_memdel((void **)ms->command_inf);
	//FREE COMMAND INF
}

int		main(int argc __attribute__((unused)),
	char **argv __attribute__((unused)), char **envp)
{
	t_minishell ms[1];
	int			i;

	i = 0;
	ms->envp = envp;
	ft_init(ms);
	while (1)
	{
		get_next_line(0, &ms->line);
		ft_testing(ms);
		while (ms->command_tab[i])
		{
			if (ft_strchr(ms->command_tab[i], -54))
				manage_pipe(ms, i);
			else if (ft_strchr(ms->command_tab[i], -51) || ft_strchr(ms->command_tab[i], -52)
			|| ft_strchr(ms->command_tab[i], -53))
				manage_inf(ms, i);
			else
			{
				ms->line = ms->command_tab[i];
				get_different_option(ms, i);
				ft_printf("%s", ms->line);
				ft_strdel(ms->line);
				ft_strdel(ms->command);
			}
			//ft_strdel(ms->command_tab[i]);
			i++;
		}
		//ft_strdel(ms->command_tab[i]);
		//ft_memdel((void **)ms->command_tab);
		i = 0;
	}
	ft_exit(ms);
	return (1);
}