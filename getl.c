#include "main.h"

int main()
{
        char *buffer;
	size_t bufsize = 0;
	ssize_t characters;
	char *token;

	buffer = NULL;
	while (1)
	{
		printf("$ ");
		characters = getline(&buffer, &bufsize, stdin);
		token = strtok(buffer, " ");
		while (token != NULL)
	    {
			printf("%s\n", token);
			token = strtok(NULL, " ");
	    }
		if (characters == -1)
		{
			printf("The shell has closed\n");
			free(buffer);
			return(-1);
		}
		printf("%s", buffer);
	}
	free(buffer);
	printf("This program has stopped running");
	return (0);
}
