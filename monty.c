#include "monty.h"

/**
  * main - opens a monty script file for parsing.
  * @argc: number of arguments.
  * @argv: argument vector.
  *
  * Return: EXIT_SUCCESS on success or
  * EXIT_FAILURE on failure.
  */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	parsefile(file);
	return (EXIT_SUCCESS);
}
