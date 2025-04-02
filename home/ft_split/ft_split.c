#include <stdlib.h>
#include <stdio.h>
int count_words(char *str)
{
    int count;
    int flag;

    flag = 1;
    count = 0;
    while (*str != '\0')
    {
        if (*str == ' ' || (*str >= '\t' && *str <= '\r'))
            flag = 1;
        else if (flag)
        {
            count++;
            flag = 0;
        }
        str++;
    }
    return (count);
}

int count_char(char *str)
{
    int count;

    count = 0;
    while (*str != '\0')
    {
        if (*str == ' ' || (*str >= '\t' && *str <= '\r'))
            break;
        else
            count++;
        str++;
    }
    return (count);
}

char    *ft_strlcpy(char *dest, char *str, int n)
{
    int index;

    index = 0;
    while (str[index] != '\0' && index < n)
    {
        dest[index] = str[index];
        index++;
    }
    dest[index] = '\0';
    return (dest);
}

char    **ft_split(char *str)
{
    int index;
    char    **arr;
    int count;

    count = count_words(str);
    arr = malloc((count + 1) * sizeof(char*));
    if (!arr)
        return (NULL);
    index = 0;
    count = 1;
    while (*str != '\0')
    {
        while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
        {
            count = 1;
            str++;
        }
        if (count && count_char(str))
        {
            arr[index] = malloc((count_char(str) + 1) * sizeof(char));
            if (!arr[index])
                return (NULL);
            ft_strlcpy(arr[index], str, count_char(str));
            count = 0;
            index++;
        }       
        str++;
    }
    arr[index] = NULL;
    return (arr);
}

int main()
{
    ft_split(" ABC A    ABC A ");
    return (0);
}