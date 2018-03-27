#include <stdio.h>

void Func1()
{
	printf ("Func1 is working\n");
}

void Func2(int a, int b)
{
	printf ("Func2 is working: %d\n", a + b);
}

int Func3()
{
	return printf("Func3 is working\n"), 0;
}

int * Func4(int * p)
{
	return printf("Func4 is working: %d\n", *p), p;
}



void main(void)
{
	void (*pointer1)();
	void (*pointer2)(int a, int b);
	int (*pointer3)();
	int* (*pointer4)(int * p);

	pointer1 = Func1;
	pointer1();
	pointer2 = Func2;
	pointer2(2,2);
	pointer3 = Func3;
	pointer3();
	pointer4 = Func4;
	int temp = 4;
	pointer4(&temp);
}
