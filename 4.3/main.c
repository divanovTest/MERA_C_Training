#include <math.h>
#include <stdio.h>
#define PI 3.14159265 

typedef double (*myFunc)(double);


void main(void)
{	
	myFunc myFuncArray[6] = {&sin,&cos,&tan,&exp,&log,&fabs};

	for(int i = 0; i < 7; i++)
	{
		switch(i)
		{
			case 0:
				printf("\t-PI/2\t-PI/3\t-PI/6\t0\tPI/4\tPI\n");				
				;break;
			case 1:
				printf("sin\t%f\t%f\t%f\t%f\t%f\t%f\n", myFuncArray[0](-PI/2), myFuncArray[0](-PI/3), myFuncArray[0](-PI/6), myFuncArray[0](0),
					myFuncArray[0](PI/4), myFuncArray[0](PI/2));
				break;
			case 2:
				printf("cos\t%f\t%f\t%f\t%f\t%f\t%f\n", myFuncArray[1](-PI/2), myFuncArray[1](-PI/3), myFuncArray[1](-PI/6), myFuncArray[1](0),
					myFuncArray[1](PI/4), myFuncArray[1](PI/2));
				break;
			case 3:
				printf("tan\t%f\t%f\t%f\t%f\t%f\t%f\n", myFuncArray[2](-PI/2), myFuncArray[2](-PI/3), myFuncArray[2](-PI/6), myFuncArray[2](0),
					myFuncArray[2](PI/4), myFuncArray[2](PI/2));
				break;
			case 4:
				printf("exp\t%f\t%f\t%f\t%f\t%f\t%f\n", myFuncArray[3](-PI/2), myFuncArray[3](-PI/3), myFuncArray[3](-PI/6), myFuncArray[3](0),
					myFuncArray[3](PI/4), myFuncArray[3](PI/2));
				break;
			case 5:
				printf("log\t%f\t%f\t%f\t%f\t%f\t%f\n", myFuncArray[4](-PI/2), myFuncArray[4](-PI/3), myFuncArray[4](-PI/6), myFuncArray[4](0),
					myFuncArray[4](PI/4), myFuncArray[4](PI/2));
				break;
			case 6:
				printf("fabs\t%f\t%f\t%f\t%f\t%f\t%f\n", myFuncArray[5](-PI/2), myFuncArray[5](-PI/3), myFuncArray[5](-PI/6), myFuncArray[5](0),
					myFuncArray[5](PI/4), myFuncArray[5](PI/2));
				break;
				
		}		
	}
}
