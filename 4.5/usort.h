#ifndef USORT_H
#define USORT_H
enum type
{
	character = sizeof(char),
	integral = sizeof(int),
	doubled = sizeof(double)
};
typedef int (*comparator)(const void*, const void*);
int intcompare (const void * a, const void * b);
int doublecompare (const void *a, const void * b);
int charcompare (const void *a, const void * b);
void my_usort (void * base, size_t num, size_t size, int (*comparator)(const void *, const void * ));
#endif
