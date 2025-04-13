#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../project/get_next_line.h"

int main(void)
{
    char *line;

    line = get_next_line(-1);
    assert(get_next_line(-1) == NULL);
    free(line);

    printf("\033[0;32mOK \033[0m");
    return 0;
}
