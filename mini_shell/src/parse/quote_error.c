#include "parse_def.h"

int quote_error(char *prompt)
{
    int double_quote;
    int index;

    index = 0;
    double_quote = 0;
    while (prompt[index])
    {
        if (prompt[index] == DOUBLE_QUOTE)
		{
			double_quote++;
			index++;
			while (prompt[index] && prompt[index] != DOUBLE_QUOTE)
				index++;
			if (prompt[index] == '\0')
				return (1);
			double_quote++;
			index++;
		}
        else if (prompt[index] == SINGLE_QUOTE)
		{
			index++;
			while (prompt[index] && prompt[index] != SINGLE_QUOTE)
				index++;
			if (prompt[index] == '\0')
				return (1);
			index++;
		}
		else
			index++;
    }
	if (double_quote % 2 != 0)
		return (1);
    return (0);
}
