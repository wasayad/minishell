#include "./libft/libft.h"
#include "errno.h"
#include <sys/types.h>
#include <sys/wait.h>
#include "stdio.h"

int		main(int argc __attribute__((unused)),
	char **argv __attribute__((unused)), char **envp)
{
int		id;
	int		ret;
	char	*buffer;
    char    **arg;

    arg = malloc(sizeof(char **) * 2);
    arg[0] = NULL;
    int pfd[2];
	buffer = malloc(sizeof(char *) * 10000);
	pipe(pfd);
	id = fork();
	if(id == 0)
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
        printf("salut");
		execve("/home/user42/42/minish/tester.sh", arg, envp);

	}
	else
	{
		close(pfd[1]);
		while (((ret = read(pfd[0], buffer, 1023)) > 0))
		{
			printf("%s\n", buffer);
			buffer[ret] = 0;
		}
		close(pfd[0]);
	}
	free(buffer);
}