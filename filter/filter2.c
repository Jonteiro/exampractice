#define _GNU_SOURCE
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
	size_t initialcap = 5;
	size_t len = 0;
	size_t r;
	char *buff = malloc(sizeof(char) * initialcap);
	if(!buff)
		return(1);
	while((r = read(0, buff + len, initialcap - len)) > 0){
		len += r;
		if(len == initialcap){
			initialcap *= 2;
			char *newbuff = realloc(buff, initialcap);
			if(!newbuff){
				free(buff);
				return(1);
			}
			buff = newbuff;
		}
	}
	if(r < 0){
		free(buff);
		return(1);
	}
	buff = realloc(buff, len + 1);
	buff[len] = '\0';
	char *aster = malloc(sizeof(char) * fillen);
	if(!aster){
		free(buff);
		return(1);
	}
	size_t i = 0;
	while(i < fillen)
		aster[i++] = '*';
	char *curr = buff;
	size_t remaining = len;
	while(remaining >= fillen){
		char *found = memmem(curr, remaining, filter, fillen);
		if(!found) 
			break;
		size_t offset = (size_t)(found - buff);
		memmove(buff + offset, aster, fillen);
		curr = buff + offset + fillen;
		remaining = len - (curr - buff);
	}
	write(1, buff, len);
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