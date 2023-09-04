#include <stdio.h>
#include <string.h>

int main()
{
	char greeting[] = "Asalam Aleikum!, ";
	char name[] = "Jebet Ivy";
	char combined[30];

	strcpy(combined, greeting);
	strcat(combined, name);

	printf("The Combined string is: %s\n", combined);
	printf("The length of the combined string is: %ld\n", strlen(combined));

	return (0);
}
