#include "push_swap_bonus.h"

int ft_compare(char *line, char *instraction)
{
	int	i;

	i = 0;
	if(line == NULL || instraction == NULL)
		return (0);
	while(line[i] && instraction[i])
	{
		if(line[i] != instraction[i])
			return (0);
		i++;
	}
	return (1);
}

int main ()
{
	printf("%d", ft_compare(NULL, "rraegwrtj\n"));
}