int ft_atoi(const char *nptr)
{
    unsigned int    total;
    int flag;

    flag = 1;
    while(*nptr == ' ')
        nptr++;
    if (*nptr == '-')
        flag *= -1;
    nptr++;
    total = 0;
    while (*nptr >= '0' && *nptr <= '9')
    {
        total += *nptr - '0';
        nptr++;
    }
    return (total * flag);
}