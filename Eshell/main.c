#include "main.h"

int main (int argc, char **argv)
{
        printf("$");
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}	
