#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 256
#define MAX_ARGUMENTS 32

/**
 * handleChildProcess - Function that executes a command in the child process
 * @line: The command to be executed
 *
 */
void handleChildProcess(char *line)
{
        char *command = strdup(line);
        char *args[] = {command, NULL};

        execve(command, args, NULL);
        perror("execve");
        free(command);
        exit(EXIT_FAILURE);
}

/**
 * executeCommand - Function that creates a child process to execute a command
 * @line: The command to be executed
 *
 */
void executeCommand(char *line)
{
                pid_t pid = fork();

                if (pid == -1)
                {
                        perror("fork");
                        exit(EXIT_FAILURE);
                }
                if (pid == 0)
                {
                        handleChildProcess(line);
                }
                else
                {
                        wait(NULL);
                }
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	size_t bufsize = 0;
	char *line = NULL;
	int status;

	while (1)
	{
		printf("$ ");
		status = getline(&line, &bufsize, stdin);
		if (status == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			perror("getline");
			exit(EXIT_FAILURE);
		}
		if (line[status - 1] == '\n')
			line[status - 1] = '\0';
		executeCommand(line);
	}
	free(line);
	return (0);
}
