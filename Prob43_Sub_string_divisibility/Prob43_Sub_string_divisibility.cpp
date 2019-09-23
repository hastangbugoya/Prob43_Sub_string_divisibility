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

void permute(char *a, int l, int r, unsigned long long int *bigsum)
{
	int i, digit;
	unsigned long long int sum, n;

	if (l == r)
	{
		if (((a[1] - 48) * 100 + (a[2] - 48) * 10 + (a[3] - 48)) % 2 == 0
			&& ((a[2] - 48) * 100 + (a[3] - 48) * 10 + (a[4] - 48)) % 3 == 0
			&& ((a[3] - 48) * 100 + (a[4] - 48) * 10 + (a[5] - 48)) % 5 == 0
			&& ((a[4] - 48) * 100 + (a[5] - 48) * 10 + (a[6] - 48)) % 7 == 0
			&& ((a[5] - 48) * 100 + (a[6] - 48) * 10 + (a[7] - 48)) % 11 == 0
			&& ((a[6] - 48) * 100 + (a[7] - 48) * 10 + (a[8] - 48)) % 13 == 0
			&& ((a[7] - 48) * 100 + (a[8] - 48) * 10 + (a[9] - 48)) % 17 == 0
			)
		{
			sum = 0;
			for (i = 0; i < 10; i++)
			{
				sum = sum * 10 + a[i] - 48;
			}		
			printf("%s %lld\n", a, sum);
			*bigsum = *bigsum + sum;
		}
			
	}
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((a + l), (a + i));
			permute(a, l + 1, r, bigsum);
			swap((a + l), (a + i)); //backtrack 
		}
	}
}

void main()
{
	char str[] = "0123456789";
	int n = strlen(str);
	unsigned long long int bigsum = 0;
	permute(str, 0, n - 1, &bigsum);
	printf("\n%lld", bigsum);
}


