#include "monty.h"

/**
  * push - pushes node to top of stack.
  * @stack: pointer to head node pointer of stack
  * @nline: line number.
  *
  * Return: NAIN.
  */
void push(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp->next = *stack;
	temp->prev = NULL;
	temp->n = arg.arg;
	if (*stack)
		(*stack)->prev = temp;
	*stack = temp;
}

/**
  * pall - prints data of all nodes in stack.
  * @stack: pointer to head node pointer of stack.
  * @nline: line number.
  *
  * Return: nothing.
  */
void pall(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
  * free_stack - frees all nodes in a stack.
  * @stack: pointer to head node pointer of a stack.
  *
  * Return: NAIN
  */
void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
		return;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}


/**
  * nop - does NAIN.
  * @stack: pointer to head node pointer of stack.
  * @nline: line number.
  *
  * Return: NAIN.
  */
void nop(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;
}


/**
  * _isalpha - checks if int is an alphabet.
  * @c: int
  *
  * Return: 1 if yes, 0 otherwise.
  */
int _isalpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	else
		return (0);
}

