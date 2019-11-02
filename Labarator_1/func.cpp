#include "func.h"

#include <stdlib.h> 

#include <conio.h> 

#include <stdio.h> 

using namespace std;

void copy(char* a, char* b)
{
	while (*b != '\0')
	{
		*a = *b;
		a++;
		b++;
	}
	*a = '\0';
	return;
}
long int dlina(char* a)
{
	long int count = 0;
	while (*a != '\0')
	{
		count++;
		a++;
	}
	return count;
}
bool chislo(char p)
{
	if (p >= '0' && p <= '9')
		return true;
	else
		return false;
}

bool test_number(char* str)
{
	while (*str != '\0')
	{
		if (chislo(*str) == true)
			str++;
		else
			return false;
	}
	return true;
}
void sort(worker obj[])
{
	char empty[] = " ";
	worker temp;
	for (int i = 0; i < 10 - 1; i++)
		for (int j = i + 1; j < 10; j++)
			if ((strcmp(obj[i].take_fio(), obj[j].take_fio()) > 0) && (strcmp(obj[i].take_fio(), empty) != 0) && (strcmp(obj[j].take_fio(), empty) != 0))
			{
				temp = obj[i];
				obj[i] = obj[j];
				obj[j] = temp;
			}
}


bool test(char* str)
{
	while (*str != '\0')
	{
		if (chislo(*str) == false)
			str++;
		else
			return false;
	}
	return true;
}

