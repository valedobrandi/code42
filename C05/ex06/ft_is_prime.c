int	ft_is_prime(int nb)
{
	int	count;
	int	guess;

	guess = 0;
	count = 1;

	while (count <= nb)
	{
		if (nb % count == 0)
			guess = guess + 1;
		count = count + 1;
	}

	if (guess == 2)
		return (1);
	return (0);

}
