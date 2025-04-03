#include <unistd.h>

void print(long n, int fd)
{
    char    num;

    if (n == 0)
        return;
    num = (n % 10) + '0';
    print(n / 10, fd);
    write(fd, &num, 1);
}

void    ft_putnbr_fd(int n, int fd)
{
    long long_n;

    long_n = n;
    if (long_n == 0) {
        write(fd, "0", 1);
        return;
    }
    if (long_n < 0)
    {
        write(fd, "-", 1);
        long_n *= -1;
    }
    print(long_n, fd);
}