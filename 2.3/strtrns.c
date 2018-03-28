#include "strtrns.h"
#include <stdlib.h>
//#include "../2.1/mystrlen.c"

char* strtrns(const char* string, const char* old, const char* new, char* result)
{
	if(result == NULL)
	{
		puts("result is NULL\n");
		return "";
	}
	for(int j = 0; j < mystrlen(string); j++){
		result[j] =	string[j];
		for(int i = 0; i < mystrlen(old); i++)
		{
			if(string[j] == old[i]){
				result[j] = new[i];
			}
		}
	}
	return result;
}
