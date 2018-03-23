#include <stdlib.h>
#include "usort.h"

int intcompare (const void * a, const void * b)
{
	if(*((int*)a) == *((int*)b))
	{
		return 0;
	}
	else if(*((int*)a) > *((int*)b))
	{
		return 1;	
	}
	else
	{
		return -1;
	}
}

int doublecompare (const void *a, const void * b)
{
	if(*((double*)a) == *((double*)b))
	{
		return 0;
	}
	else if(*((double*)a) > *((double*)b))
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int charcompare (const void *a, const void * b)
{
	if(*((char*)a) == *((char*)b))
	{
		return 0;
	}
	else if(*((char*)a) > *((char*)b))
	{
		return 1;	
	}
	else
	{
		return -1;
	}
}
//В качестве аргументов функции принимают указатели на соответствующие типы. Если значения равны, возвращается 0. Если первый аргумент больше второго – 
//возвращается положительное число, в противном случае – отрицательное.

//Написать универсальную функцию для сортировки (любым способом):
void my_usort (void * base, size_t num, size_t size, int (*comparator)(const void *, const void * ))
{
	int res, t_int; double t_double; char t_char;
	for(int i = 0; i < num * size - size; i += size)
	{
		res = comparator(&base[i], &base[i + size]);
		if(res > 0)
		{
			for(int j = i;j >- 1;j -= size)
			{
				res=comparator(&base[j], &base[j + size]);
				if(res > 0)
				{
					switch(size)
					{
						case integral:
							t_int = *((int*)&base[j + size]);
							*((int*)&base[j + size]) = *((int*)&base[j]);
							*((int*)&base[j]) = t_int;
							;break;		
						case character:
							t_char = *((char*)&base[j + size]);
							*((char*)&base[j + size]) = *((char*)&base[j]);
							*((char*)&base[j]) = t_char;
							;break;
						case doubled:
							t_double = *((double*)&base[j + size]);
							*((double*)&base[j + size]) = *((double*)&base[j]);
							*((double*)&base[j]) = t_double;
							;break;			
					}
				}
				else
				{
					break;
				}
			}	
		}
	}
}
// base – указатель на начало массива
// num – количество элементов в массиве
// size – размер одного элемента в байтах
// comparator – функция для сравнения элементов

//Реализовать проверку работы этой функции аналогично предыдущему примеру для трех типов: char, int, double.
