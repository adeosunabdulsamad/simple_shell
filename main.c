#include "main.h"

int main(void)
{
    char *buffer, *buffer_copy;
    size_t bufsize = 0;
    ssize_t characters;
    char *token;
    const char *delim = " ";
    int i = 0;
    int n;
	char *envp[] = {
		"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/usr/lib/wsl/lib:/mnt/c/Python312/Scripts/:/mnt/c/Python312/:/mnt/c/Windows/system32:/mnt/c/Windows:/mnt/c/Windows/System32/Wbem:/mnt/c/Windows/System32/WindowsPowerShell/v1.0/:/mnt/c/Windows/System32/OpenSSH/:/mnt/c/Program Files/dotnet/:/mnt/c/Program Files (x86)/nodejs/:/mnt/c/ProgramData/chocolatey/bin:/mnt/c/Program Files/Git/cmd:/mnt/c/Users/ADEOSUN/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/ADEOSUN/.dotnet/tools:/mnt/c/Users/ADEOSUN/AppData/Roaming/npm:/mnt/c/Users/ADEOSUN/AppData/Local/Programs/Microsoft VS Code/bin:/mnt/c/Users/ADEOSUN/AppData/Local/GitHubDesktop/bin:/snap/bin",
		NULL
	};

    buffer = NULL;
    while (1)
    {
        printf("$ ");
        // gets the input
        characters = getline(&buffer, &bufsize, stdin);
        if (characters == -1) // if there is an error
        {
            printf("The shell has closed\n");
            free(buffer);
            return -1;
        }
        buffer_copy = malloc(bufsize);
        strcpy(buffer_copy, buffer);

        token = strtok(buffer, delim);
        while (token != NULL)
        {
            i++;
            token = strtok(NULL, delim);
        }
        i++;

        char **argv_exec = malloc(sizeof(char *) * i);
        // separate the input with space as the delimiter
        token = strtok(buffer_copy, delim);
        for (n = 0; token != NULL; n++)
        {
            argv_exec[n] = malloc(strlen(token) + 1);
            strcpy(argv_exec[n], token);
            token = strtok(NULL, delim);
        }
        argv_exec[n] = NULL;

        for (int counter = 0; counter < i - 1; counter++)
        {
            printf("%s\n", argv_exec[counter]);
            free(argv_exec[counter]);
        }

        if (fork() == 0)
        {
            // Child process
            if (execve(argv_exec[0], argv_exec, envp) == -1)
            {
                perror("Error:");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            // Parent process
            wait(NULL); // Wait for the child process to finish
            free(argv_exec);
            free(buffer_copy);
        }
    }

    free(buffer);
    printf("This program has stopped running\n");
    return 0;
}

