#include <stdio.h>

int main()
{
	int age = 18;
	int score = 60;

	if (age >= 18 && score >= 60)
	{
		printf("You are eligible for a driver's license\n");
	}
	else
	{
		printf("You are not eligible for a driver's license\n");
	}

	if (age < 18 || score >= 80)
	{
		printf("You are not old enough for a driver's license, but you have an exceptional score\n");
	}
	else
	{
		printf("You are not eligible for a driver's license\n");
	}
	return (0);
}
