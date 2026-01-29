#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **av){
    if(ac != 2)
        return 1;
    char *filter = av[1];
    size_t fillen = strlen(filter);
    size_t cap = 10;
    size_t r = 0;
    size_t len = 0;
    char *buff = malloc(sizeof(char) * cap);
    if(!buff)
        return(1);
    while((r = read(0, buff + len, cap - len)) > 0){
        len += r;
        if(len == cap){
            cap *= 2;
            buff = realloc(buff, sizeof(char) * cap);
            if(!buff)
                return(1);
        }
    }
    buff = realloc(buff, len + 1);
    buff[len] = '\0';
    char *aster = malloc(sizeof(char) * fillen);
    size_t i = 0;
    while(i < fillen)
        aster[i++] = '*';
    char *dupe = buff;
    size_t remaining = len;
    while(remaining >= fillen){
        char *found = memmem(dupe, remaining, filter, fillen);
        if(!found)
            break;
        size_t offset = found - buff;
        memmove(buff + offset, aster, fillen);
        dupe = buff + offset + fillen;
        remaining = len - (dupe - buff);
    }
    write(1, buff, len);
    free(aster);
    return(1);

}
