#include <stdio.h>

//Написать следующие функции без использования циклов, рекурсии, вспомогательных функций:
// Возвращает 1, если value является степенью двойки, 0 – в противном случае:
int ispower2(int value)
{
	return (value & (value - 1)) == 0 ? 0 : 1;
};
// Возвращает значение 2p (два в степени p):
int pow2(int p)
{
	return 2 << ( p - 1 );
};
//В следующих функциях необходимо использовать рекурсию:
// Возвращает факториал числа n:
int fact(int n)
{
	return n <= 1 ? 1 : n * fact( n - 1 );
}
// Возвращает сумму цифр числа. sum_digit(123) = 6:
int sum_digit(int n)
{
	return n > 0 ? n % 10 + sum_digit( n / 10 ) : 0;
}
// Возвращает число ненулевых битов в n. nz_bits(15121) = 7 :
int nz_bits(int n)
{
	return n > 0 ? n % 2 != 0 ? 1 + nz_bits( n / 2 ) : 0 + nz_bits( n / 2 ) : 0;
}

void main(void){
	printf("Digit 8 is ^2: %i\n", ispower2(8));
	printf("Digit 5 is ^2: %i\n", ispower2(5));

	printf("Pow 2^8: %i\n", pow2(8));
	printf("Pow 2^2: %i\n", pow2(2));

	printf("Factorial 5!: %i\n", fact(5));

	printf("Sum of all digits: %i\n", sum_digit(123));

	printf("Sum of all bits: %i\n", nz_bits(15121));
}


