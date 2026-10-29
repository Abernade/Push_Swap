#include "../push_swap.h"

void	set_flags(char *str, swap *flags, size_t len)
{
	if (ft_memcmp(str, "--bench", len + 1))
		flags->flag_bench = 1;
	else if (ft_memcmp(str, "--simple", len + 1))
		flags->flag_simple = 1;
	else if (ft_memcmp(str, "--medium", len + 1))
		flags->flag_medium = 1;
	else if (ft_memcmp(str, "--complex", len + 1))
		flags->flag_complex = 1;
	else if (ft_memcmp(str, "--adaptative", len + 1))
		flags->flag_adaptative = 1;
}

int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	del_list(void *content)
{
	if (content)
		free(content);
}

t_list	*get_ints(char **av, int argc)
{
	int		i;
	int		*converted;
	t_list	*head;
	t_list	*new;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		if (!str_is_digit(*av))
		{
			ft_lstclear(&head, del_list);
			return (NULL);
		}
		converted = (int *)malloc(sizeof(int));
		converted[0] = ft_atoi(*av);
		new = ft_lstnew(converted);
		ft_lstadd_back(&head, new);
		av++;
		i++;
	}
	return (head);

int	parser(char **av, int argc, swap *flags)
{
	int	i;
	t_list	*head;
	t_list	*new;

	i = 1; //on veux pas l'exec
	av++;
	set_flags(*av, flags, ft_strlen(*av));
	head = get_ints(av, argc);
	new = head;
	while (head)
	{
		printf("[%d]\n", ((int *)head->content)[0]);
		head = head->next;
	}
	ft_lstclear(&new, del_list);
	return(0);
}

void	flag_init(swap *flags)
{
	flags->flag_adaptative = 0;
	flags->flag_bench = 0;
	flags->flag_complex = 0;
	flags->flag_medium = 0;
	flags->flag_simple = 0;
	flags->disorder = -1;
}


int	main(int argc, char **av)
{
	swap	flags;
	flag_init(&flags); //faire fonction à part pour
	if (argc < 2)// dans le cas ou on appelle que l'executable
		return (1);
	parser(av, argc, &flags);
}
