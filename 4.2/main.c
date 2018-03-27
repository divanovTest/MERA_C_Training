#include <stdio.h>
#include <stdlib.h>

void print_arrays_pointer(int **array){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf(" %i ", array[i][j]);
		}
		printf("\n");
	}
}

void print_array(int array[][3])
{
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf(" %d ", array[i][j]);
		}
		printf("\n");
	}	
}

void main(void)
{
	int array1[][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int **array2 = (int**)malloc(sizeof(int*)*3);
	int n = 1;
	for(int i = 0; i < 3; i++)
	{
		array2[i] = (int*)malloc(sizeof(int)*3);
		for(int j = 0; j < 3; j++){
			array2[i][j] = n++;	
		}
	}
	n = 1;
	int *array3[] = {{1,2,3},{4,5,6},{7,8,9}};
	for(int i = 0; i < 3; i++)
	{
		array3[i] = (int*)malloc(sizeof(int)*3);
		for(int j = 0; j < 3; j++){
			array3[i][j] = n++;	
		}
		
	}
	
	print_array(array1);
	print_arrays_pointer(array2);
	print_arrays_pointer(array3);	
		
	for(int i = 0; i < 3; i++)
	{
		free(array2[i]);
		free(array3[i]);	
	}
	free(array2);
}
