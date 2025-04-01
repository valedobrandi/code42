#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	if (index <= 1)
	{
		return (index);
	}	
	return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
}

int	main(void)
{
	int	fib;

	fib = ft_fibonacci(2);
	printf("%d\n", fib);
	fib = ft_fibonacci(3);
        printf("%d\n", fib);
        fib = ft_fibonacci(4);
        printf("%d\n", fib);
        fib = ft_fibonacci(10);
        printf("%d\n", fib);

}
