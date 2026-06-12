#include "monty.h"

/**
 * f_push - add node to the stack (or queue)
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int counter)
{
        int n, j = 0, flag = 0;
        stack_t *new_node, *tail;

        if (!bus.arg)
                flag = 1;
        else
        {
                if (bus.arg[0] == '-')
                        j++;
                for (; bus.arg[j] != '\0'; j++)
                {
                        if (!isdigit(bus.arg[j]))
                                flag = 1;
                }
        }
        if (flag == 1)
        {
                fprintf(stderr, "L%d: usage: push integer\n", counter);
                free(bus.content);
                free_stack(*head);
                fclose(bus.file);
                exit(EXIT_FAILURE);
        }

        n = atoi(bus.arg);
        new_node = malloc(sizeof(stack_t));
        if (!new_node)
        {
                fprintf(stderr, "Error: malloc failed\n");
                free(bus.content);
                free_stack(*head);
                fclose(bus.file);
                exit(EXIT_FAILURE);
        }
        new_node->n = n;

        if (bus.format == 1 && *head != NULL)
        {
                tail = *head;
                while (tail->next)
                        tail = tail->next;
                tail->next = new_node;
                new_node->prev = tail;
                new_node->next = NULL;
                return;
        }

        new_node->next = *head;
        new_node->prev = NULL;
        if (*head)
                (*head)->prev = new_node;
        *head = new_node;
}

/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int counter)
{
        stack_t *h = *head;
        (void)counter;

        while (h)
        {
                printf("%d\n", h->n);
                h = h->next;
        }
}

/**
 * f_pint - prints the value at the top of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pint(stack_t **head, unsigned int counter)
{
        if (*head == NULL)
        {
                fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
                free(bus.content);
                free_stack(*head);
                fclose(bus.file);
                exit(EXIT_FAILURE);
        }
        printf("%d\n", (*head)->n);
}

/**
 * f_pop - removes the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pop(stack_t **head, unsigned int counter)
{
        stack_t *h;

        if (*head == NULL)
        {
                fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
                free(bus.content);
                free_stack(*head);
                fclose(bus.file);
                exit(EXIT_FAILURE);
        }
        h = *head;
        *head = h->next;
        if (*head)
                (*head)->prev = NULL;
        free(h);
}

/**
 * f_nop - does nothing
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_nop(stack_t **head, unsigned int counter)
{
        (void)counter;
        (void)head;
}
