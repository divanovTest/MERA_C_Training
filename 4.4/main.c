#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void main(void)
{	
	//Контрольный пример:
	int len = 100000;
	int * array = malloc(sizeof(int) * len);
	for (int step = 1; step < 16; step++)
	{
		printf ("Step #%d: ", step);
		init_array (array, len);
		mysort (array, len);
		printf (check_order(array, len) ? "FAILED\n" : "Passed\n");
	}
	free (array);
}
