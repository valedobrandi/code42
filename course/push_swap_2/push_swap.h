#include <stdlib.h>
#include <stdio.h>
typedef struct
{
    int arr[100];
    int top;
} Stack;

void push(Stack *stack, int value)
{
    stack->top++;
    stack->arr[stack->top] = value;
}

int pop(Stack *stack)
{
    int popped;

    popped = stack->arr[stack->top];
    stack->top--;
    return (popped);
}

int sorted(Stack *stack)
{
    int index;
    int stack_index;

    index = 0;
    while (index < stack->top)
    {
        stack_index = index + 1;
        while (stack_index <= stack->top)
        {
            if (stack->arr[index] > stack->arr[stack_index])
                return (0);
            stack_index++;
        }
        index++;
    }
    return (1);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    unsigned char *s;

    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    while (n--)
        *d++ = *s++;
    return (dest);
}

void buble_swap(int *arr, int index)
{
    int temp;

    temp = arr[index];
    arr[index] = arr[index + 1];
    arr[index + 1] = temp;
}

int *buble_sort(int *arr, int size)
{
    int index;
    int swapped;

    int *sorted = malloc(sizeof(int) * size);
    if (!sorted)
        return NULL;
    ft_memcpy(sorted, arr, sizeof(int) * size);
    index = 0;
    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        index = 0;
        while (index < size - 1)
        {
            if (sorted[index] > sorted[index + 1])
            {
                buble_swap(sorted, index);
                swapped = 1;
            }
            index++;
        }
    }
    return (sorted);
}