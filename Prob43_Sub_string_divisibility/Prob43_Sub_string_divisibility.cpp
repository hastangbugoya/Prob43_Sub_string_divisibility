// Prob43_Sub_string_divisibility.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
1430952867 1430952867
1406357289 1406357289
1460357289 1460357289
4130952867 4130952867
4106357289 4106357289
4160357289 4160357289

16695334890
*/
#include "pch.h"
#include <iostream>
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void jumble(char *s, int l, int r, unsigned long long int *bigsum)
{
	int i, digit;
	unsigned long long int sum, n;

	if (l == r)
	{
		if (((s[1] - 48) * 100 + (s[2] - 48) * 10 + (s[3] - 48)) % 2 == 0
			&& ((s[2] - 48) * 100 + (s[3] - 48) * 10 + (s[4] - 48)) % 3 == 0
			&& ((s[3] - 48) * 100 + (s[4] - 48) * 10 + (s[5] - 48)) % 5 == 0
			&& ((s[4] - 48) * 100 + (s[5] - 48) * 10 + (s[6] - 48)) % 7 == 0
			&& ((s[5] - 48) * 100 + (s[6] - 48) * 10 + (s[7] - 48)) % 11 == 0
			&& ((s[6] - 48) * 100 + (s[7] - 48) * 10 + (s[8] - 48)) % 13 == 0
			&& ((s[7] - 48) * 100 + (s[8] - 48) * 10 + (s[9] - 48)) % 17 == 0
			)
		{
			sum = 0;
			for (i = 0; i < 10; i++)
			{
				sum = sum * 10 + s[i] - 48;
			}		
			printf("%s %lld\n", s, sum);
			*bigsum = *bigsum + sum;
		}
			
	}
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((s + l), (s + i));
			jumble(s, l + 1, r, bigsum);
			swap((s + l), (s + i)); //backtrack 
		}
	}
}

void main()
{
	char str[] = "0123456789";
	unsigned long long int bigsum = 0;
	//start and end index
	jumble(str, 0, 9, &bigsum);
	printf("\n%lld", bigsum);
}


