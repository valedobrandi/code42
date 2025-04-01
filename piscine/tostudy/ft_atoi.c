int ft_atoi(char *str)
{
	int index;
	int mark;
	int result;

	index = 0;
	mark = 0;
	result = 0;

	while (str[index] == ' ' || str[index] >= 9 && str[index] <= 13)
		index++;
	if (str[index] == '-' || str[index] == "+")
	{
		if (str[index] == '-')
			mark = -1;
		index++;
	}

	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + (str[index] - '0');
		index++;
	}

	return (result * mark);
}