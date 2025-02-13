int	ft_sqrt(int nb)
{
	static int 	guess;
	
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	if (guess == 0)
		guess = 1;
	if (guess * guess == nb)
		return guess;
	if (guess * guess > nb)
		return (0);
	guess = guess + 1;
	return (ft_sqrt(nb));
}
