#include <stdio.h>
#include <stdlib.h>
#include "../4.5/usort.c" //my_usort
//#include "../2.1/mystrlen.c" //mystrlen
#include "../2.3/strtrns.c" //strtrns

#define FILENAME "inputfile.txt"



int main(int argc, char* argv[])
{

	/*Программа должна поддерживать следующие ключи:
	+	-r сортирует в обратном порядке
		-n сортирует в числовом формате (“123” > “23”)
	+	-u оставляет только уникальные строки
	+	-f игнорирует регистр
	+	-o <file> результат сохраняется в файл вместо стандартного вывода
	+	-q использует быструю сортировку (вызывая системную qsort)*/

	void (*mypointerqsort)(void * base, size_t num, size_t size, int (*comparator)(const void *, const void * ));
	mypointerqsort = &my_usort;
	char* filename = NULL; char* outputfilename = NULL;
	unsigned short  numbers = 0, unique = 0, regitri = 0, qwicksort = 0;
	char* oldpattern = "";
	char* newpattern = "";
	for(int i = 1; i < argc; ++i)
	{
		if(strcmp(argv[i], "-r") == 0){
			reverse = 1;
		}else if(strcmp(argv[i], "-n") == 0){
			numbers = 1;
		}else if(strcmp(argv[i], "-u") == 0){
			unique = 1;
		}else if(strcmp(argv[i], "-f") == 0){
			regitri = 1;
			oldpattern = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			newpattern = "abcdefghijklmnopqrstuvwxyz";
		}else if(strcmp(argv[i], "-o") == 0){
			if(argv[i+1] == NULL){
				printf("Error. Please enter output file name.");
				exit(EXIT_FAILURE);
			}
			outputfilename = argv[++i];
		}else if(strcmp(argv[i], "-q") == 0){
			qwicksort = 1;
			mypointerqsort = &qsort;
		}else{
			filename = argv[1];
		}
	}

	if(filename == NULL)printf("You are not enter file name: use default file name %s\n",FILENAME);

	FILE *fpr;
	char *buf = NULL;
	size_t len = 0;
	ssize_t read;
	char** strings = NULL;
	int* integrals = NULL;

   	fpr = fopen(filename == NULL ? FILENAME : filename, "r");
    if (fpr == NULL){
    	printf("Cannot open file: %s\n", filename == NULL ? FILENAME : filename);
        exit(EXIT_FAILURE);
    }

    int count = 0;
	while ((read = getline(&buf, &len, fpr)) != -1) 
	{
		strings = (char**)realloc(strings, sizeof(char*) * (count + 1));
		if(!strings)
		{
			printf("Error. realloc strings\n");
			exit(EXIT_FAILURE);
		}
		strings[count] = (char*)malloc(sizeof(char) * read);

		if(unique)
		{
			unsigned short temp = 0;
			for(int i = 0; i < count; ++i)
			{
				if(strcmp(buf, strings[i]) == 0)temp = 1;
			}
			if(temp > 0)continue;
		}
		

		if(numbers)
		{
			integrals=(int*)realloc(integrals,sizeof(int) * (count + 1));
			if(!integrals)
			{
				printf("Error. realloc integrals\n");
				exit(EXIT_FAILURE);
			}
			integrals[count] = atoi(buf);
		}
		//strtrns.c:
		strtrns(buf, oldpattern, newpattern, strings[count]);
		count++;
	}


	for(int j = 0; j < count; j++)
	{
		if(numbers > 0)
		{
			//usort.c
			mypointerqsort(integrals, count, sizeof(int), intcompare);
		}
		else
		{
			//usort.c
			mypointerqsort(strings[j], mystrlen(strings[j]), sizeof(char), charcompare);
		}
	}
	//write in file
	if(outputfilename != NULL)
	{

		FILE *fpw = fopen(outputfilename, "w");
		for(int j = 0; j < count; j++)
		{
			fprintf(fpw, numbers > 0 ? "%d " : "%s", numbers > 0 ? integrals[j] : strings[j]);	
		}
		fclose(fpw);
	}
	else
	{
		for(int j = 0; j < count; ++j)
		{
			printf("strings[%d] = %s\n", j, strings[j]);
		}
	}

	for(int i = 0; i < count; ++i)free(strings[i]);
	free(strings);
   	free(buf);
   	return 0;
}