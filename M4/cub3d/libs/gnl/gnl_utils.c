#include "include/get_next_line.h"

int ft_strlen(char *str) {
    int i = 0;
    while (str && str[i])
        i++;
    return i;
}

char *ft_strchr(char *str, char c) {
    if (!str)
        return NULL;
    while (*str)
    {
        if (*str == c)
            return str;
        str++;
    }
    return NULL;
}

char *ft_strdup(char *s1) {
	char *dup = malloc(ft_strlen(s1) + 1);
	if (!dup)
		return NULL;
	for (int i = 0; s1[i]; i++)
		dup[i] = s1[i];
	dup[ft_strlen(s1)] = '\0';
	return dup;
}

char *ft_strjoin(char *stash, char *buffer) {
	if (!stash)
		return ft_strdup(buffer);
	if (!buffer)
		return ft_strdup(stash);
	size_t len = ft_strlen(stash) + ft_strlen(buffer);
	char *res = malloc(len + 1);
	if (!res)
		return NULL;
	size_t i = 0, j = 0;
	while (stash[i])
    {
		res[i] = stash[i];
        i++;
    }
	while (buffer[j])
    {
		res[i + j] = buffer[j];
        j++;
    }
	res[i + j] = '\0';
	free(stash);
	return res;
}

char *ft_substr(char *s, int start, int len) {
	if (!s)
		return NULL;
	int  s_len = ft_strlen(s);
	if (start >= s_len )
		return ft_strdup("");
	if (len > s_len - start)
		len = s_len - start;
	char *sub = malloc(len + 1);
	if (!sub)
		return NULL;
	for (int i = 0; i < len; i++)
		sub[i] = s[start + i];
	sub[len] = '\0';
	return sub;
}