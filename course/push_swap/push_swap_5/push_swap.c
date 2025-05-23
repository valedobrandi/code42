#include "push_swap.h"
int operation_count = 0;

void increment_count()
{
    operation_count++;
}

int validate(Stack *stack)
{
    int index;

    index = 0;
    while (index < stack->top)
    {
        if (stack->arr[stack->top] < stack->arr[index])
            return (0);
        index++;
    }
    return (1);
}

int best_move(Stack *stack, int target)
{
    int index;

    index = stack->top;
    while (index >= 0)
    {
        if (stack->arr[index] == target)
            break;
        index--;
    }
    return (index);
}

Greedy greedy_search(Stack *from, int *sorted, int max, int min, int chunk)
{
    int index = from->top;
    Greedy get;

    get.position = -1;
    get.target = -1;
    while (index > 0)
    {
        if (from->arr[index] <= sorted[max - chunk] &&
            from->arr[index] >= sorted[min - chunk])
        {
            get.position = index;
            get.target = from->arr[index];
            return (get);
        }
        index--;
    }
    return (get);
}

void sorte_back(Stack *from, Stack *to, int *sorted)
{
    int target = 0;
    int position = 0;
    int index = 0;

    while (from->top >= 0)
    {
        target = sorted[99 - index];
        position = best_move(from, target);
        if (position > ((from->top + 1) / 2))
            while (from->arr[from->top] != target)
                rotate_top_b(from);
        else
            while (from->arr[from->top] != target)
                rotate_bottom_b(from);
        push_b(from, to);
        index++;
    }
}

int max_stack_value(Stack *stack, int *sorted)
{
    int index = stack->top;
    int target = sorted[0];

    while (index >= 0)
    {
        if (target < stack->arr[index])
            target = stack->arr[index];
        index--;
    }
    return (target);
}

int min_stack_value(Stack *stack, int *sorted)
{
    int index = stack->top;
    int target = sorted[99];

    while (index >= 0)
    {
        if (target > stack->arr[index])
            target = stack->arr[index];
        index--;
    }
    return (target);
}


void insert_position(Stack *stack, Node *sorted, int target)
{
    int index = 0;
    
    
}

int push_chuncks(Stack *from, Stack *to, int *sorted, int max, int chunk)
{
    int chunck_size = 20;
    Greedy get;
    int index;

    index = 0;
    while (index < chunck_size && from->top > 0)
    {
        get = greedy_search(from, sorted, max, max - chunck_size, chunk);
        printf("greedy %d\n", get.target);
        if (get.position > ((from->top + 1) / 2))
            while (from->arr[from->top] != get.target)
                rotate_top_a(from);
        else
            while (from->arr[from->top] != get.target)
                rotate_bottom_a(from);
        int is_max = get.target > max_stack_value(to, sorted);
        int is_min = get.target < min_stack_value(to, sorted);
        if (to->top >= 0 && !is_max & !is_min)
            insert_position(to, sorted, get.target);
        push_a(from, to);
        index++;
        if (is_max & !is_min)
            rotate_bottom_b(to);
        if (from->top == 0)
            push_a(from, to);
    }
    return (index);
}