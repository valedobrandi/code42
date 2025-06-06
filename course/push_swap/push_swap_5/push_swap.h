#include <stdlib.h>
#include <stdio.h>

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
typedef struct 
{
    int value;
    int index;
} Node;

typedef struct
{
    Node arr[100];
    int top;
} Stack;

typedef struct
{
    int target;
    int position;
} Greedy;

extern int operation_count;

char *swap_a(Stack *stack_a);
char *swap_b(Stack *stack_b);
char *push_a(Stack *stack_a, Stack *stack_b);
char *push_b(Stack *stack_b, Stack *stack_a);
char *rotate_bottom_a(Stack *stack_a);
char *rotate_bottom_b(Stack *stack_b);
char *rotate_top_a(Stack *stack_a);
char *rotate_top_b(Stack *stack_b);
void push(Stack *stack, int value);
int pop(Stack *stack);
int sorted(Stack *stack);
void *ft_memcpy(void *dest, const void *src, size_t n);
void buble_swap(int *arr, int index);
int *buble_sort(int *arr, int size);
void increment_count();
int validate(Stack *stack);
int best_move(Stack *stack, int target);
Greedy greedy_search(Stack *from, int *sorted, int max, int min, int chunk);
void sorte_back(Stack *from, Stack *to, int *sorted);
int push_chuncks(Stack *from, Stack *to, int *sorted, int max, int chunk);
#endif