#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystrlen.h"

int main(void){
	char str1[16]="Hello!";
	char* str2="Another string";
	printf("Length of str1: %u\n",mystrlen(str1));
	printf("Length of str2: %u\n",mystrlen(str2));
	printf("Custom length: %u\n",mystrlen(str2+7));
	getchar();
}
