#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 256

/**
 * run_command - A function that executes a command using fork and execve
 * @command: The command to execute
 *
 */
void run_command(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork error");
	}
	if (child_pid == 0)
	{
		char *argv[] = {(char *)command, NULL};
		char *envp[] = {NULL};

		if (execve(command, argv, envp) == -1)
		{
			perror("./simple_shell");
		}
	}
	else
	{
		int status;

		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
		{
			printf("%d\n", WEXITSTATUS(status));
		}
	}
}

/**
 * main - A simple-shell Function that executes user provided commands
 *
 * Return: Always 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("simple_shell$ ");
		fflush(stdout);

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\nGoodbye!\n");
			break;
		}
		size_t command_length = strlen(command);

		if (command_length > 0 && command[command_length - 1] == '\n')
		{
			command[command_length - 1] = '\0';
		}
		run_command(command);
	}
	return (0);
}
