#include <stdio.h>
#include "mystrlen.h"

size_t mystrlen(const char* str){
	size_t length = 0;
	while(*str){
		str++;
		length++;
	}
	return length;
}

