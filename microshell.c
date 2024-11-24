#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int ac, char **av, char **env)
{
	int	status;
	int	i;

	int pip[2];
	pipe(pip);
	pip[0]
	pip[1]
	i = 0;
	status = 0;
	while (av[i])
	{
		av += i + 1;
		i = 0;
		if (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (i)

	}
}
