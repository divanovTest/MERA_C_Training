#include <stdio.h>
#include "strtrns.h"



int main(void){
	char string[64] = "sample text";
	const char* old_symbols = "st";
	const char* new_symbols = "ST";
	printf("Convert text: %s\n", strtrns(string, old_symbols, new_symbols, string));

	old_symbols = "abcdefghijklmnopqrstuvwxyz";
	new_symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";	
	printf ("Another text: %s\n", strtrns("Another example", old_symbols, new_symbols, string));

	new_symbols = "bcdefghijklmnopqrstuvwxyza";
	printf ("Encrypted text: %s\n", strtrns("secret message", old_symbols, new_symbols, string));
	printf ("Decrypted text: %s\n", strtrns(string, new_symbols, old_symbols, string));
	return 0;
}


