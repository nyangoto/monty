#include "monty.h"

/**
  * rotl - rotates stack to the top
  * @stack: pointer to the head node pointer of stack
  *
  * @nline: line number
  * Return: NAIN
  */
void rotl(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	int hold1, hold2;
	(void)nline;

	if (stack == NULL || *stack == NULL)
	{
		nop(stack, nline);
	}

	hold1 = (*stack)->n;
	temp = *stack;

	while (temp)
	{
		if (temp->next == NULL)
			break;
		temp = temp->next;
	}

	hold2 = temp->n;
	(*stack)->n = hold2;
	temp->n = hold1;
}

/**
  * rotlop - rotates stack to the left
  * @stack: pointer to the head node pointer of stack
  *
  * @nline: line number
  * Return: NAIN
  */
void rotlop(stack_t **stack, unsigned int nline)
{
	stack_t *temp, *last;

	(void)nline;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	temp = *stack;
	last = temp;

	while (last->next)
	{
		last = last->next;
	}

	last->next = temp;
	temp->prev = last;
	temp->next->prev = NULL;
	*stack = temp->next;
	temp->next = NULL;
}


/**
  * rotrop - rotates stack to the right.
  * @stack: pointer to the head node pointer of stack
  * @nline: line number
  *
  * Return: NAIN
  */
void rotrop(stack_t **stack, unsigned int nline)
{
	stack_t *temp, *last;

	(void)nline;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	temp = *stack;
	last = temp;

	while (last->next)
	{
		last = last->next;
	}

	last->prev->next = NULL;
	last->prev = NULL;
	temp->prev = last;
	last->next = temp;
	*stack = last;
}


/**
  * qpush - pushes to queue instead of stack
  * @stack: pointer to the head node pointer of stack
  * @nline: line number
  *
  * Return: NAIN
  */
void qpush(stack_t **stack, unsigned int nline)
{
	stack_t *new, *last;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	last = NULL;
	if (*stack)
	{
		last  = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*stack = new;
	new->prev = last;
	new->next = NULL;
	new->n = arg.arg;
}
