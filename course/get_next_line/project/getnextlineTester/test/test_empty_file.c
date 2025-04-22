#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>
#include "get_next_line.h"

const char *path = "test/files/test_file.txt";
void generate_file()
{
    remove(path);
    FILE *file = fopen(path, "w");
    if (file == NULL)
    {
        perror("Failed to create file");
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

int main(void)
{
  int fd;
  char *line;
  generate_file();
  fd = open(path, O_RDONLY);
  if (fd < 0)
  {
    perror("open");
    return 1;
  }
  line = get_next_line(fd);
  assert(line == NULL);
  printf("\033[0;32mOK\033[0m ");
  free(line);
  close(fd);
  line = get_next_line(1000);
  assert(line == NULL);
  printf("\033[0;32mOK\033[0m ");
  return 0;
}
