#include "push_swap.h"
Stack stack_a = {
    .arr = {3, 27, 94, 19, 63, 1, 88, 52, 44, 85,
            7, 90, 33, 39, 60, 101, 48, 96, 59, 18,
            34, 40, 58, 15, 6, 92, 87, 100, 50, 26,
            76, 46, 32, 10, 14, 69, 2, 64, 25, 43,
            28, 84, 36, 21, 66, 30, 78, 82, 37, 45,
            77, 16, 4, 5, 35, 93, 74, 47, 9, 95,
            20, 24, 11, 80, 56, 41, 86, 13, 38, 75,
            71, 23, 31, 67, 91, 17, 72, 61, 12, 97,
            65, 42, 70, 29, 53, 55, 22, 99, 49, 83,
            8, 68, 81, 57, 62, 98, 89, 54, 79},
    .top = 99};
Stack stack_b = {.top = -1};

int main(void)
{
    int *sorted = buble_sort(stack_a.arr, 100);
    int max = 99;
    int chunk = 0;
    while (stack_a.top >= 0)
        chunk += push_chuncks(&stack_a, &stack_b, sorted, max, chunk);
    sorte_back(&stack_b, &stack_a, sorted);
    /* for (int i = 0; i < 100; i++)
        printf("[A][%d] - %d\n", i, stack_b.arr[i]);
    printf("\nTotal operations: %d\n", operation_count); */
    return (0);
}

/*
for (int i = 0; i < 100; i++)
    printf("[A][%d] - %d\n", i, stack_a.arr[i]);
printf("\nTotal operations: %d\n", operation_count);
*/
