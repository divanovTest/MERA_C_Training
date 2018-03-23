#include <stdio.h>
#include "../2.1/mystrlen.c"
#include "mymemmove.h"



int main(void)
{
	char buffer[32]="\0\0\0\0My string";
	char* buf1=buffer+4;
	char* buf2=buffer;
	char* buf3=buffer+2;
	printf("Copy left: %s\n",mymemmove(buf2,buf1,mystrlen(buf1)+1));
	printf("Copy right: %s\n",mymemmove(buf3,buf2,mystrlen(buf2)+1));
	return 0;
}
