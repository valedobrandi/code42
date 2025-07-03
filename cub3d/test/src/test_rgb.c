#include <criterion/criterion.h>
#include "cub3d.h"
#include "libft.h"

// Helper to create a single t_list node
t_list *make_entry(char *type, char *path)
{
    t_entries *entry = malloc(sizeof(t_entries));
    entry->type = strdup(type);
    entry->path = strdup(path);
    return ft_lstnew(entry);
}

// Helper to free an entry
void free_entry(void *ptr)
{
    t_entries *entry = ptr;
    if (entry->type)
        free(entry->type);
    if (entry->path)
        free(entry->path);
    free(entry);
}

Test(validate, valid_rgb_values)
{
    t_list *lst = NULL;

    ft_lsadd_back(&lst, make_entry("F", "220,100,0"));
    ft_lsadd_back(&lst, make_entry("C", "  255 ,  255 , 255 "));

    cr_assert_eq(validate_rgb(&lst), 0, "Should validate correct RGB strings");

    ft_lstclear(&lst, free_entry);
}

Test(validate, bigger_number)
{
    t_list *lst = NULL;

    ft_lsadd_back(&lst, make_entry("F", "2210,100,0"));
    ft_lsadd_back(&lst, make_entry("C", "  255 ,  255 , 2550 "));

    cr_assert_eq(validate_rgb(&lst), 1, "should fail with bigger numbers");

    ft_lstclear(&lst, free_entry);
}

Test(validate, invalid_format_missing_values)
{
    t_list *lst = NULL;

    ft_lsadd_back(&lst, make_entry("F", "220,100"));

    cr_assert_eq(validate_rgb(&lst), 1, "Should fail on missing RGB component");

    ft_lstclear(&lst, free_entry);
}

Test(validate, invalid_non_digit_chars)
{
    t_list *lst = NULL;

    ft_lsadd_back(&lst, make_entry("C", "255,x,0"));

    cr_assert_eq(validate_rgb(&lst), 1, "should fail on non-digit character");

    ft_lstclear(&lst, free_entry);
}

Test(validate, empty_rgb_string)
{
    t_list *lst = NULL;

    ft_lsadd_back(&lst, make_entry("F", ""));

    cr_assert_eq(validate_rgb(&lst), 1, "should fail on empty RGB string");

    ft_lstclear(&lst, free_entry);
}

Test(validate, space_numbers)
{
    t_list *lst = NULL;

    ft_lsadd_back(&lst, make_entry("F", "  2 5 5, 0 , 1    0   1"));

    cr_assert_eq(validate_rgb(&lst), 0, "should fail with spaces");

    ft_lstclear(&lst, free_entry);
}
