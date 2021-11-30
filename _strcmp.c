#include "main.h"
/**
 * _strcmp - function that compares two strings
 * @s1: string s1
 * @s2: string s2
 * Return: string concat
 */
int _strcmp(char *s1, char *s2)
{
	int a = 0;
	int cm = 0;

	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] == s2[a])
		{
			cm = 0;
			a++;
		}
		else
		{
			cm = s1[a] - s2[a];
			break;
		}
	}
	return (cm);
}
