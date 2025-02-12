unsigned int 	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	src_size;
	unsigned int	index;

	dest_size = 0;
	while (dest_size < size && dest[dest_size] != '\0')
		dest_size += 1;

	if (dest_size >= size)
		return (size + dest_size);

	index = 0;
	while (src[index] != '\0' && dest_size < (size - 1))
	{
		dest[dest_size] = src[index];
		dest_size++;
		index++;	
	}

	return (dest_size + src_size);
			
}
