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
        if (stack->arr[stack->top].value < stack->arr[index].value)
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
        if (stack->arr[index].value == target)
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
    get.target.value = -1;
    get.target.index = -1;
    while (index > 0)
    {
        if (from->arr[index].value <= sorted[max - chunk] &&
            from->arr[index].value >= sorted[min - chunk])
        {
            get.position = index;
            get.target.value = from->arr[index].value;
            get.target.index = from->arr->index;
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
            while (from->arr[from->top].value != target)
                rotate_top_b(from);
        else
            while (from->arr[from->top].value != target)
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
        if (target < stack->arr[index].value)
            target = stack->arr[index].value;
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
        if (target > stack->arr[index].value)
            target = stack->arr[index].value;
        index--;
    }
    return (target);
}

void insert_position(Stack *stack, Node target)
{
    int index = 0;
    int min_diff = 100;
    int current_diff = 0;
    int next_position = -1;
    int next_target = 0;

    while (index <= stack->top)
    {
        if (target.index > stack->arr[index].index)
            current_diff = target.index - stack->arr[index].index;
        else
            current_diff = stack->arr[index].index - target.index;

        if (current_diff < min_diff)
        {
            min_diff = current_diff;
            next_position = index;
        }
        index++;
    }
    next_target = stack->arr[next_position].value;
    if (next_position > ((stack->top + 1) / 2))
        while (stack->arr[stack->top].value != next_target)
            rotate_top_a(stack);
    else
        while (stack->arr[stack->top].value != next_target)
            rotate_bottom_a(stack);
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
        //printf("greedy %d\n", get.target);
        if (get.position > ((from->top + 1) / 2))
            while (from->arr[from->top].value != get.target.value)
                rotate_top_a(from);
        else
            while (from->arr[from->top].value != get.target.value)
                rotate_bottom_a(from);
        if (to->top > 0)
            insert_position(to, get.target);
        push_a(from, to);
        index++;

        if (from->top == 0)
            push_a(from, to);
    }
    return (index);
}