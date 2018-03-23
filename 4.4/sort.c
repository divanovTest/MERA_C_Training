#include "sort.h"

//Написать функцию для сортировки (любым способом: пузырьком, выбором, вставкой …)
void mysort(int * array, int len)
{
	int temp;
	for(int i=0;i<len-1;i++)
	{
		if(array[i]>array[i+1])
		{
			for(int j=i;j>-1;j--)
			{
				if(array[j]>array[j+1])
				{
					temp=array[j];
					array[j+1]=array[j];
					array[j]=temp;
				}else{break;}
				
			}
		}
		
	}
};
// array – указатель на начало массива
// len – длина

//Написать функцию для инициализации массива случайными значениями с аналогичными аргументами:
void init_array(int * array, int len)
{
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        array[i] = rand() % len;
    }
};


//Написать функцию для проверки правильности сортировки:
int check_order (int * array, int len)
{
	for(int i=0;i<len-1;i++)
	{
		if(array[i]>array[i+1]){
			return 1;	
		}
	}
	return 0;
};
// Проверяет, что все элементы расположены по возрастанию. Возвращает 0, если элементы расположены по возрастанию, 1 
//в противном случае.
