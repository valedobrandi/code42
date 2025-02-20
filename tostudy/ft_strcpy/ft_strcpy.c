char	*ft_strcpy(char *dest, char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		dest[index] = str[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
