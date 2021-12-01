#include "main.h"
#include <stdio.h>
/**
 * _strcmp - s1 compare s2
 * @s1: comp 1
 * @s2: comp 2
 *
 *
 * Return: compare
 */
int _strcmp(char *s1, char *s2)
{
	int r = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int b = 1;
	int tam;

	while (*(s1 + j))
	{
		j++;
	}

	while (*(s2 + k))
	{
		k++;
	}
	if (j != k)
	{
		return(-1);
	}
	
	while (b != 0)
	{
		r = s1[i] - s2[i];

		if (r == 0)
		{
			i++;
		}
		if (r != 0)
		{
			return (-1);
		}
		if (r != 0 || i == j)
		{
			b = 0;
			return (b);
		}
	}

	return (0);
}
