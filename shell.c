#include "shell.h"

/**
 * execute - executes the command(s) entered from then cli
 *
 * @cli: cli command(s) to run
 *
 * Return: 0 on success, -1 if exit, 1 for any other error
 */
int execute(char **cli)
{
	pid_t child_pid;
	int status;

	if (strncmp("exit", cli[0], 4) == 0)
		return (-1);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(cli[0], cli, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	else
		wait(&status);

	return (0);
}


/**
 * main - entry function for the simple shell
 *
 * @argc: number of cli arguments
 * @argv: list of cli arguments
 *
 * Return: Always 0, and  -1 on error
 */
int main(int argc, char **argv)
{
	int response;
	char **tokens;
	size_t buffsize = BUFSIZ;
	int isPipe = 0;
	char *buffer;

	if (argc >= 2)
	{
		if (execve(argv[1], argv, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
		return (0);
	}

	buffer = (char *)malloc(buffsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	do {
		if (isatty(fileno(stdin)))
		{
			isPipe = 1;
			_puts("cisfun#: ");
		}

		getline(&buffer, &buffsize, stdin);
		buffer[_strlen(buffer) - 1] = '\0';
		tokens = stringToTokens(buffer);
		response = execute(tokens);
	} while (isPipe && response != -1);

	return (0);
}
