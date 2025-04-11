#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../project/get_next_line.h"

int main(void)
{
    char *line;
    int result = 0;

    printf("==== Invalid File Descriptor Test ====\n");

    line = get_next_line(-1);
    if (line == NULL)
        printf("✅ ");
    else
    {
        printf("❌ Expected NULL but got: \"%s\"\n", line);
        free(line);
        result = 1;
    }

    printf(result == 0 ? "Test passed!\n" : "Test failed!\n");
    return result;
}
