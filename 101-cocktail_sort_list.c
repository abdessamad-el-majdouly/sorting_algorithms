#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 *                     using the Cocktail Shaker Sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        /* Forward pass (left to right) */
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                /* Swap current node with the next node */
                if (current->prev != NULL)
                    current->prev->next = current->next;
                else
                    *list = current->next;

                current->next->prev = current->prev;
                current->prev = current->next;
                current->next = current->next->next;
                current->prev->next = current;
                if (current->next != NULL)
                    current->next->prev = current;

                swapped = 1;
                print_list(*list);
            }
        }
        /* If no swaps occurred, the list is sorted */
        if (swapped == 0)
            break;

        swapped = 0;
        /* Backward pass (right to left) */
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                /* Swap current node with the previous node */
                if (current->next != NULL)
                    current->next->prev = current->prev;

                current->prev->next = current->next;
                current->next = current->prev;
                current->prev = current->next->prev;
                current->next->prev = current;
                if (current->prev != NULL)
                    current->prev->next = current;

                swapped = 1;
                print_list(*list);
            }
        }
    } while (swapped);
}
