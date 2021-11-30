#include "main.h"
/**
 * _strcat - function that concatenates two strings
 * @dest: s1
 * @src: s2
 * Return: string dest
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}
	*ptr++ = '/';
	while (*src != '\0')
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (dest);
}
