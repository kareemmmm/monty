#include "monty.h"

/**
 * f_swap - swaps the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_swap(stack_t **head, unsigned int counter)
{
        stack_t *h = *head;
        int len = 0, aux;

        while (h)
        {
                h = h->next;
                len++;
        }
        if (len < 2)
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
                free(bus.content);
                free_stack(*head);
                fclose(bus.file);
                exit(EXIT_FAILURE);
        }
        h = *head;
        aux = h->n;
        h->n = h->next->n;
        h->next->n = aux;
}

/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_add(stack_t **head, unsigned int counter)
{
        stack_t *h = *head;
        int len = 0, aux;

        while (h)
        {
                h = h->next;
                len++;
        }
        if (len < 2)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", counter);
                free(bus.content);
                free_stack(*head);
                fclose(bus.file);
                exit(EXIT_FAILURE);
        }
        h = *head;
        aux = h->n + h->next->n;
        h->next->n = aux;
        *head = h->next;
        (*head)->prev = NULL;
        free(h);
}

/**
 * f_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_div(stack_t **head, unsigned int counter)
{
        stack_t *h = *head;
        int len = 0, aux;

        while (h)
        {
                h = h->next;
                len++;
        }
        if (len < 2)
        {
                fprintf(stderr, "L%d: can't div, stack too short\n", counter);
                free(bus.content);
                free_stack(*head);
                fclose(bus.file);
                exit(EXIT_FAILURE);
        }
        h = *head;
        if (h->n == 0)
        {
                fprintf(stderr, "L%d: division by zero\n", counter);
                free(bus.content);
                free_stack(*head);
                fclose(bus.file);
                exit(EXIT_FAILURE);
        }
        aux = h->next->n / h->n;
        h->next->n = aux;
        *head = h->next;
        (*head)->prev = NULL;
        free(h);
}

/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_mul(stack_t **head, unsigned int counter)
{
        stack_t *h = *head;
        int len = 0, aux;

        while (h)
        {
                h = h->next;
                len++;
        }
        if (len < 2)
        {
                fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
                free(bus.content);
                free_stack(*head);
                fclose(bus.file);
                exit(EXIT_FAILURE);
        }
        h = *head;
        aux = h->next->n * h->n;
        h->next->n = aux;
        *head = h->next;
        (*head)->prev = NULL;
        free(h);
}
