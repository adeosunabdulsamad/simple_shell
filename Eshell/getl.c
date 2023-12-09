#include "main.h"

int main()
{
        char *buffer;
	size_t bufsize =32;
	size_t characters;

	buffer = (char *)malloc(bufsize *sizeof(char));
	if (buffer == NULL)
	{
		perror("unable to read properly\n");
		exit(1);
	}
	while (1)
	{
		printf("$ ");
		characters = getline(&buffer, &bufsize, stdin);
		printf("%s", buffer);
	}
	return (0);
}
