#include "monty.h"

stack_t *global_stack = NULL;

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char line[100];
	unsigned int line_number = 0;
	char *opcode;
	int i;
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{NULL, NULL}
	};
	(void)argv;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue; /* Skips empty lines or comments */
		i = 0;
		while (ops[i].opcode != NULL)
		{
			if (strcmp(opcode, ops[i].opcode) == 0)
			{
				ops[i].f(&global_stack, line_number);
				break;
			}
			i++;
		}
		if (ops[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free_stack(global_stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(global_stack);
	fclose(file);
	return (0);
}
