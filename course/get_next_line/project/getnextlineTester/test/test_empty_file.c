#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>
#include "get_next_line.h"

void generate_empty_file()
{
  struct stat buffer;
  const char *path = "test/files/test_empty_file.txt";

  if (stat(path, &buffer) != 0)
  {
    FILE *file = fopen(path, "w");
    if (file == NULL)
    {
      perror("Failed to create test_empty_file.txt");
      exit(EXIT_FAILURE);
    }
    fclose(file);
    printf("Generated: %s\n", path);
  }
}

int main(void)
{
  int fd;
  char *line;
  generate_empty_file();
  fd = open("test/files/test_empty_file.txt", O_RDONLY);
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
  return 0;
}
