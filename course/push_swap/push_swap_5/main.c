#include "push_swap.h"
int input[100] = {
    3, 27, 94, 19, 63, 1, 88, 52, 44, 85,
    7, 90, 33, 39, 60, 101, 48, 96, 59, 18,
    34, 40, 58, 15, 6, 92, 87, 100, 50, 26,
    76, 46, 32, 10, 14, 69, 2, 64, 25, 43,
    28, 84, 36, 21, 66, 30, 78, 82, 37, 45,
    77, 16, 4, 5, 35, 93, 74, 47, 9, 95,
    20, 24, 11, 80, 56, 41, 86, 13, 38, 75,
    71, 23, 31, 67, 91, 17, 72, 61, 12, 97,
    65, 42, 70, 29, 53, 55, 22, 99, 49, 83,
    8, 68, 81, 57, 62, 98, 89, 54, 79};
Stack stack_b = {.top = -1};

void push_to_stack(Stack *stack_a, int *sorted, int *input, int size)
{
    int index = 0;
    int sorted_index = 0;

    while (index < size)
    {
        stack_a->arr[stack_a->top].value = input[index];
        sorted_index = 0;
        while (sorted_index < size)
        {
            if (input[index] == sorted[sorted_index])
            {
                stack_a->arr[stack_a->top].index = sorted_index;
                break;
            }
            sorted_index++;
        }
        index++;
        stack_a->top++;
    }
}

int main(void)
{
    Stack stack_a = {{0}, 0};
    int *sorted = buble_sort(input, 100);
    int max = 99;
    int chunk = 0;
    while (stack_a.top >= 0)
        chunk += push_chuncks(&stack_a, &stack_b, sorted, max, chunk);
    printf("\nTotal operations: %d\n", operation_count);
    sorte_back(&stack_b, &stack_a, sorted);
    for (int i = 0; i < 100; i++)
        printf("[A][%d] - %d\n", i, stack_b.arr[i]);
    printf("\nTotal operations: %d\n", operation_count);
    printf("\n");

    return (0);
}

/*
for (int i = 0; i < 100; i++)
    printf("[A][%d] - %d\n", i, stack_a.arr[i]);
printf("\nTotal operations: %d\n", operation_count);
*/