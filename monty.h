#ifndef MONTY_H
#define MONTY_H

/* Library inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>


/* struct definitions */

/**
  * struct arg_s - argument representation.
  * @arg: integer.
  * @flag: option that corresponds to a specific command.
  *
  * Description: structure fr argument parameters
  * passed to monty.
  */
typedef struct arg_s
{
	int arg;
	int flag;
} arg_t;

extern arg_t arg;

/**
  * struct stack_s - doubly linked list representation of a stack (or queue)
  * @n: integer element within node.
  * @prev: points to previous element of stack/queue.
  * @next: points to next element of stack/queue.
  *
  * Description: doubly linked node structure
  * for this Holberton project.
  */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
  * struct instruction_s - opcode and its function.
  * @opcode: the opcode.
  * @f: function to handle the opcode.
  *
  * Description: opcode and its function.
  */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * struct meta_s - contents of file and buffer data.
  * @buf: pointer to array of data read from buffer.
  * @stack: pointer to top of stack.
  * @file: pointer to file.
  */
typedef struct meta_s
{
	char *buf;
	stack_t *stack;
	FILE *file;
} meta_t;

/**
  * struct line - contents of a line and number.
  * @content: array of tokens read from line.
  * @number: line number.
  *
  * Description: structure for data in a line.
  */
typedef struct line_s
{
	char **content;
	unsigned int number;
} line_t;

/* Critical functions */
void (*get_op_func(line_t line, meta_t *meta))(stack_t **, unsigned int);
int _isalpha(int c);

/* Parse functions */
void parsefile(FILE *file);
void parseline(line_t *line, char *buffer);

/* Validation functions */
bool comment_check(line_t line);
void push_check(line_t line, meta_t *meta, char *opcode);

/* Stack manipulation functions */
void push(stack_t **stack, unsigned int nline);
void pall(stack_t **stack, unsigned int nline);
void pint(stack_t **stack, unsigned int nline);
void pop(stack_t **stack, unsigned int nline);
void swap(stack_t **stack, unsigned int nline);
void nop(stack_t **stack, unsigned int nline);
void rotl(stack_t **stack, unsigned int nline);
void rotlop(stack_t **stack, unsigned int nline);
void rotrop(stack_t **stack, unsigned int nline);
void pchar(stack_t **stack, unsigned int nline);
void pstr(stack_t **stack, unsigned int nline);
void free_stack(stack_t **stack);
void qpush(stack_t **stack, unsigned int nline);
void addqu(stack_t **stack, unsigned int nline);
void addst(stack_t **stack, unsigned int nline);

/* Arithmetic functions */
void subop(stack_t **stack, unsigned int nline);
void addop(stack_t **stack, unsigned int nline);
void divop(stack_t **stack, unsigned int nline);
void mulop(stack_t **stack, unsigned int nline);
void modop(stack_t **stack, unsigned int nline);

#endif /* MONTY_H */
