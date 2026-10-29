#include "push_swap.h"

void	set_flags(char *str, swap *flags, size_t len)
{
	if (ft_memcmp(str, "--bench", len))
		flags->flag_bench = 1;
	else if (ft_memcmp(str, "--simple", len))
		flags->flag_simple = 1;
	else if (ft_memcmp(str, "--medium", len))
		flags->flag_medium = 1;
	else if (ft_memcmp(str, "--complex", len))
		flags->flag_complex = 1;
	else if (ft_memcmp(str, "--adaptative", len))
		flags->flag_adaptative = 1;
}

int	*get_ints(char **av, int argc)
{

}

int	parser(char **av, int argc, swap *flags)
{
	int	i;
	int	*array;

	i = 1; //on veux pas l'exec
	set_flags(av[i], flags, ft_strlen(av[i]));
	while (i < argc)
	{

	}
	return(0);
}

int	main(int argc, char **av)
{
	swap	flags;
	ft_memset(&flags, 0, 5);
	if (argc < 2)// dans le cas ou on appelle que l'executable
		return (1);
	parser(av, argc, &flags);
}
