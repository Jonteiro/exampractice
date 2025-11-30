#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **av){
	if(ac != 2)
		return(1);
	char *filter = av[1];
	size_t fillen = strlen(filter);
	if(fillen == 0)
		return(1);
	size_t initialcap = 1;
	size_t len = 0;
	size_t r;
	char *buff = malloc(initialcap);
	if (!buff)
		return(1);
	while((r = read(0, buff + len, initialcap - len)) > 0){
		len += r;
		if(len == initialcap){
			initialcap *= 2;
			char *new = realloc(buff, initialcap);
			if (!new){
				free(buff);
				return(1);
			}
			buff = new;
		}
	}
	buff = realloc(buff, len + 1);
	buff[len] = '\0';


	int i = 0;
	while(buff[i]){
		if (memcmp(buff + i, filter, fillen) == 0)
			memset(buff + i, '*', fillen);
		i++;
	}
	printf("%s = %zu bytes", buff, len);
	free(buff);
	return(0);
}




/*
write a function that read from the standard output and replaces 
all found instances of string s 
and replaces them with the same number of *

echo "1234512300" | ./filter "123" 

***45***00

echo "abcdefg" | ./filter "a" 

*bcdefg

echo "abcdefaaaaaaaaaaaaaaabcdef" | ./filter "abc" 

***defaaaaaaaaaaaaaaa***def

read()



str = read(1) -> reads from stdin

str = read(0) -> reads from terminal
*/