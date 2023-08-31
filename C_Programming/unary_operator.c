#include <stdio.h>

int main()
{
	int num = 42;
	double pi = 3.14159;
	char letter = 'A';

	printf("Size of int: %zu bytes\n", sizeof(int));
	printf("Size of double: %zu bytes\n", sizeof(double));
	printf("Size of char: %zu bytes\n", sizeof(char));

	printf("Size of num: %zu bytes\n", sizeof(num));
	printf("Size of pi: %zu bytes\n", sizeof(pi));
	printf("Size of letter: %zu bytes\n", sizeof(letter));

	return (0);
}
