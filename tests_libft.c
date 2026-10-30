#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	char	*nptr = "+9223372036854775807";
	char	*nptr1 = "-9223372036854775807";
	char	*nptr2 = "2147483647";
	char	*nptr3 = "-2147483647";

	long long	a = ft_atoll(nptr);
	long		b = ft_atoll(nptr2);
	long long	c = ft_atoll(nptr1);
	long		d = ft_atoll(nptr3);

	printf("[%lld][%ld][%lld][%ld]\n", a, b, c, d);
	return(0);
}
