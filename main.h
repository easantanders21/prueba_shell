#ifndef MAIN_H
#define MAIN_H
/*include library*/
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
extern char **environ;
typedef struct args_s
{
    char *arg;
    struct  args_s *next;
} args_t;

#define UNUSED(x) (void)(x);
/*prototypes*/
int main(int argc, char **argv, char **env);
args_t *add(args_t **head, char *arg);
size_t print(args_t *head);
char **transform(args_t **haed);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *concatenar(char *dir, char *comando);
char *_getenv(const char *name);
#endif /* MAIN_H */
