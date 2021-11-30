#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *concatenar(char *dir, char *comando)
{
	int i = 0, j = 0, a = 0, k = 0;
	char *strcomp;

	while(dir[i])
		i++;

	while(comando[j])
		j++;
	strcomp = malloc(sizeof(char) * (i + j + 2));
	for (a = 0; a < i; a++)
	{
		strcomp[a] = dir[a];
	}
	strcomp[a++] = '/';
	for (k = 0; a < (i + j + 1); k++, a++)
	{
		strcomp[a] = comando[k];
	}
	strcomp[a++] = '\0';
	return(strcomp);
}
