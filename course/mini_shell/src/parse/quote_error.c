#include "parse_def.h"

int quote_error(char *prompt)
{
    int single_quote;
    int double_quote;
    int index;

    index = 0;
    single_quote = 0;
    double_quote = 0;
    while (prompt[index])
    {
        if (prompt[index] == DOUBLE_QUOTE)
            double_quote++;
        if (prompt[index] == SINGLE_QUOTE)
            single_quote++;
        index++;
    }
    return ((single_quote % 2) + (double_quote % 2));
}
