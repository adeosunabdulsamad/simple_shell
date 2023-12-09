#include "main.h"

int main()
{
	char str[100];
	const char s[2] =" ";
	char* token;

	printf("enter your text: ");
	fgets(str, sizeof(str), stdin);
        token = strtok(str, s);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, s);
	}
	return 0;
}
