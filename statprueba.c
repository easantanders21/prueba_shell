#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main(void) {
	struct stat buf;
	int statreturn;

	statreturn = stat("carpeta", &buf);
	printf("file size = %ld \n", buf.st_size);
	printf("retorno de stat = %d \n", statreturn);
	printf("permisos: %o\n", buf.st_mode);
	return (0);
}
