#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystrlen.h"

int main(void){
	char str1[16] = "Hello!";
	char* str2 = "Another string";
	printf("Length of str1: %lu\n", mystrlen(str1));
	printf("Length of str2: %lu\n", mystrlen(str2));
	printf("Custom length: %lu\n", mystrlen(str2 + 7));
	return 0;
}
