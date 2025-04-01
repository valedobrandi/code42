#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{	
	unsigned int	index;

	index = 0;
	while(src[index])
	{
		if (index < n)
		{
			dest[index] = src[index];
		}
		else 
		{
			dest[index] = '\0';
		}
		index++;
	}	

	dest[index] = '\0';

	return dest;
}
int	main(void)
{
	char	src[] = "123456789";
	char	dest[10];

	ft_strncpy(dest, src, 5);
	printf("%s\n", dest);

}
