#include "monty.h"

/**
  * addop - finds sum of top two elements
  * @stack: pointer to the head node pointer of stack
  * @nline: line number
  *
  * Return: NAIN
  */
void addop(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
  * subop - finds difference in top 2 elements ands stores it in 2nd element.
  * @stack: pointer to the head node pointer of stack
  * @nline: line number
  *
  * Return: NAIN
  */
void subop(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!(stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}


/**
  * divop - divides top 2 stack elements
  * ands stores it in second element
  * @stack: pointer to the head node pointer of stack
  * @nline: line number
  *
  * Return: NAIN
  */
void divop(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}



/**
  * mulop - multiplies top 2 elements ans stores res in 2nd element.
  * @stack: pointer to the head node pointer of stack
  * @nline: line number
  *
  * Return: NAIN
  */
void mulop(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}



/**
  * modop - finds modulus of top 2 elements and stores it in 2nd element.
  * @stack: pointer to the head node pointer of stack
  * @nline: line number
  *
  * Return: NAIN
  */
void modop(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
