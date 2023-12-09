#include "main.h"

int main (int argc, char **argv)
{
        int length = sizeof(argv)/sizeof(argv[2]);
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}	
