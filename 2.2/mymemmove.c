#include "mymemmove.h"
#include <stdlib.h>

void *mymemmove(void* dest,const void* source,size_t size)
{
	char *ch_dest = (char*) dest;
	char *ch_source = (char*) source;
	char *str_source = (char*)malloc(size);
	for (int i = 0; i < size; i++)
	{
		str_source[i] = ch_source[i];
	}
	for(int i = 0; i < size; i++)
	{
		ch_dest[i] = str_source[i];
	}
	free(str_source);
	return dest;
}
