#include "gnl2.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *ft_strchr(char *s, int c)
{
    int i = 0;
    while (s[i] && s[i] != c)
        i++;
    if (s[i] == c)
        return (s+i);
    else
        return (NULL);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    if(n > 0){
        while (i < n){
            ((char *)dest)[i] = ((char *)src)[i];
            i++;
        }
    }
    return dest;
}

size_t ft_strlen(char *s)
{
    size_t ret=0;
    while (s[ret])
        ret++;
    return (ret);
}

char *str_append_mem(char *s1, char *s2, size_t size2)
{
    size_t size1 = ft_strlen(s1);
    char *tmp = malloc(size2 + size1 + 1);
    if (!tmp)
        return (NULL);
    ft_memcpy(tmp, s1, size1);
    ft_memcpy(tmp + size1, s2, size2);
    tmp[size1 + size2] = 0;
    return (tmp);
}

char *str_append_str(char *s1, char *s2)
{
    return str_append_mem(s1, s2, ft_strlen(s2));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
    if (dest < src)
        return ft_memcpy (dest, src, n);
    else if (dest == src)
        return dest;
    size_t i = n;
    while (i > 0)
    {
        i--;
        ((char *)dest)[i] = ((char *)src)[i];
    }
    return dest;
}

char *get_next_line(int fd)
{
    static char b[BUFFER_SIZE + 1] = "";
    char *ret = NULL;
    char *tmp = ft_strchr(b, '\n');
    
    while(!tmp)
    {
        char *old_ret = ret;
        ret = str_append_str(ret ? ret : "", b);
        free(old_ret);
        b[0] = 0;
        if (!ret)
            return NULL;
        int read_ret = read(fd, b, BUFFER_SIZE);
        if (read_ret <= 0)
        {
            b[0] = 0;
            if (ret && ft_strlen(ret) > 0)
                return ret;
            free(ret);
            return NULL;
        }
        b[read_ret] = 0;
        tmp = ft_strchr(b, '\n');
    }
    
    char *old_ret = ret;
    char *final = str_append_mem(ret ? ret : "", b, tmp - b + 1);
    free(old_ret);
    
    if (!final)
        return NULL;
    
    ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
    return final;
}

int main(int ac, char **av){
    if(ac != 2)
        return(0);
    int fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (1);
    
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}