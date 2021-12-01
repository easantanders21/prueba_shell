#include "main.h"
/**
 * @brief
 *
 */
int no_builtins(args_t **head)
{
	char *dup = strdup(_getenv("PATH"));
	char *dir = NULL;
	char *dircom, *comando;
	args_t *aux = *head;
	int i, status;
	struct stat buf;

	comando  = aux->arg;
	for(; (dir = strtok(dup, ":")); dup = NULL)
	{
		if (dir == NULL)
			break;
		dircom = concatenar(dir, comando);
		status = stat(dircom, &buf);
		if (status == 0)
		{
			aux->arg = dircom;
			return (0);
		}
	}
	return (0);
}
int builtins(args_t **head)
{
	select_built_t modulo[] = {{"exit", holam}, {NULL, NULL}};
	args_t *aux = *head;
	int i, comp, a = 0, len = 0, j = 0;
	char *concat, ruta[30], *dato = aux->arg;

	comp = _strcmp(modulo[0].id, dato);
	printf("%d\n", comp);
	if (comp == 0)
	{
		modulo[0].f();
		return (0);
	}
	else if (comp != 0)
	{
		no_builtins(head);
		return (0);
	}
	/*for(i = 0; i < 3; i++)
	{
		comp = _strcmp(aux->arg, builtins[i]);
		if(comp == 0)
		{
			aux->arg = dato;
			return(0);
			getcwd(ruta, sizeof(ruta));
			concat = _strcat(ruta, dato);
		} else
		{
			no_builtins(head);
			return (0);
		}
	}*/
	aux->arg = dato;
	return (0);
}
args_t *add(args_t **head, char *arg)
{
    args_t *node, *aux;

    aux = *head;
    if(arg == NULL)
        return (NULL);
    node = malloc(sizeof(args_t));
    if(node == NULL)
        return (NULL);
    node->arg = strdup(arg);
    node->next = NULL;
    if(*head == NULL)
    {
        *head = node;
        return (node);
    }
    while (aux->next)
    {
        aux = aux->next;
    }
    aux->next = node;
    return (node);
}
/**
 * @brief
 *
 */
size_t print(args_t *head)
{
    int i;

    for(i = 0; head; i++)
    {
        head = head->next;
    }
    return (i);
}
/**
 * @brief
 *
 */
char **transform(args_t **head)
{
    int i = 0;
    args_t *h;
    char **arguments;

    builtins(head);

    h = *head;
    for(i = 0; h; i++)
        h = h->next;
    arguments = malloc((i + 1) * sizeof(char *));
    h = *head;
    for (i = 0; h; i++)
    {
        arguments[i] = h->arg;
        h = h->next;
    }
    arguments[i] = NULL;
    return (arguments);
}
