#include "monty.h"

/**
 * f_pchar - prints the char at the top of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pchar(stack_t **head, unsigned int counter)
{
        if (*head == NULL)
        {
                fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
                free(bus.content);
                free_stack(*head);
                fclose(bus.file);
                exit(EXIT_FAILURE);
        }
        if ((*head)->n < 0 || (*head)->n > 127)
        {
                fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
                free(bus.content);
                free_stack(*head);
                fclose(bus.file);
                exit(EXIT_FAILURE);
        }
        printf("%c\n", (*head)->n);
}

/**
 * f_pstr - prints the string starting at the top of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pstr(stack_t **head, unsigned int counter)
{
        stack_t *h = *head;

        (void)counter;
        while (h && h->n > 0 && h->n <= 127)
        {
                printf("%c", h->n);
                h = h->next;
        }
        printf("\n");
}

/**
 * f_rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotl(stack_t **head, unsigned int counter)
{
        stack_t *top, *last;

        (void)counter;
        if (*head == NULL || (*head)->next == NULL)
                return;

        top = *head;
        last = top;
        while (last->next)
                last = last->next;

        *head = top->next;
        (*head)->prev = NULL;

        last->next = top;
        top->prev = last;
        top->next = NULL;
}

/**
 * f_rotr - rotates the stack to the bottom
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotr(stack_t **head, unsigned int counter)
{
        stack_t *top, *last;

        (void)counter;
        if (*head == NULL || (*head)->next == NULL)
                return;

        top = *head;
        last = top;
        while (last->next)
                last = last->next;

        last->prev->next = NULL;
        last->prev = NULL;
        last->next = top;
        top->prev = last;

        *head = last;
}

/**
 * f_stack - sets the format of the data to a stack (LIFO)
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_stack(stack_t **head, unsigned int counter)
{
        (void)head;
        (void)counter;
        bus.format = 0;
}

/**
 * f_queue - sets the format of the data to a queue (FIFO)
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_queue(stack_t **head, unsigned int counter)
{
        (void)head;
        (void)counter;
        bus.format = 1;
}
