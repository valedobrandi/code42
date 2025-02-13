int	ft_find_next_prime(int nb)
{
	int	guess;
	int	count;

	guess = 1;
	count = 0;
	while ( guess <= nb)
	{
		if (nb % guess == 0)
		       count = count + 1;
		guess = guess + 1;	
	}
	if (count == 2)
	       return (nb);	
	return (ft_find_next_prime(nb + 1))
		
}
