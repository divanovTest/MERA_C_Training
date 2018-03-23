#include <stdio.h>
#include "mystrlen.h"

size_t mystrlen(const char* str){
size_t val=0;
while(*str){
        str++;
        val++;
}
return val;
}

