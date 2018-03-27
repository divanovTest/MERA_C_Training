#include <stdio.h>
#include "usort.h"

void main(void)
{	
	comparator myFuncMass[3] = {&intcompare, &doublecompare, &charcompare};
	int a = 4, b = 4;
	int res = myFuncMass[0](&a, &b);
	printf(res > 0 ? "first int argument > second int argument\n":res < 0 ? "first int argument < second int argument\n" : "first int argument == second int argument\n");
	double c = 2.33445, d = 3.445567;
	res = myFuncMass[1](&c,&d);
	printf(res > 0 ? "first double argument > second double argument\n" : res < 0 ? "first double argument < second double argument\n":"first double argument == second double argument\n");
	char e = 'a',f = 'b';
	res = myFuncMass[2](&e,&f);
	printf(res > 0 ? "first char argument > second char argument\n" : res < 0 ? "first char argument < second char argument\n" : "first char argument == second char argument\n");
	
	int len = 20;
	int array_i[] = {19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
	puts("Before sorting:");
	for(int i = 0; i < len; i++)printf("%d ", array_i[i]);
	my_usort(&array_i, len, sizeof(array_i[0]), myFuncMass[0]);
	puts("\nAfter sorting:");
	for(int i = 0; i < len; i++)printf("%d ",array_i[i]);
	
	len=10;
	double array_d[] = {12.33, 10.456, 33.12, 15.55, 8.54, 4.223, 3.643543, 1.5654, 3.5464,2.4543};
	puts("\nBefore sorting:");
	for(int i = 0;i < len; i++)printf("%f ", array_d[i]);
	my_usort(&array_d, len, sizeof(array_d[0]), myFuncMass[1]);
	puts("\nAfter sorting:");
	for(int i = 0; i < len; i++)printf("%f ", array_d[i]);

	char array_c[] = {'k','i','h','g','f','e','d','c','b','a'};
	puts("\nBefore sorting:");
	for(int i = 0; i < len; i++)printf("%c ", array_c[i]);
	my_usort(&array_c, len, sizeof(array_c[0]), myFuncMass[2]);
	puts("\nAfter sorting:");
	for(int i = 0; i < len; i++)printf("%c ", array_c[i]);
	puts("");
}
