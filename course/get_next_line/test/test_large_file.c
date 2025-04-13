#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>
#include "../project/get_next_line.h"

void generate_large_file()
{
  const char *path = "test/files/large_file.txt";
  struct stat buffer;

  if (stat(path, &buffer) != 0)
  {
    FILE *file = fopen(path, "w");
    if (file == NULL)
    {
      perror("Failed to create large_file.txt");
      exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 1000; i++)
    {
      fprintf(file, "This is a line in the large file.\n");
    }
    fclose(file);
    printf("Generated: %s\n", path);
  }
}

int main(void)
{
  int fd;
  char *line;
  int result = 0;
  int line_number = 1;
  const char *expected = "This is a line in the large file.\n";

  generate_large_file();
  fd = open("test/files/large_file.txt", O_RDONLY);
  if (fd < 0)
  {
    perror("open");
    return 1;
  }
  while ((line = get_next_line(fd)) != NULL)
  {
    assert(strcmp(line, expected) == 0);
    free(line);
    line_number++;
  }
  close(fd);
  assert(line_number - 1 == 1000);
  printf("\033[0;32mOK\033[0m ");
  return result;
}
