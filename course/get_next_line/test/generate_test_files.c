#include <stdio.h>
#include <stdlib.h>

void generate_empty_file() {
    FILE *file = fopen("files/empty.txt", "w");
    if (file == NULL) {
        perror("Failed to create empty.txt");
        exit(1);
    }
    fclose(file);
    printf("Generated empty.txt\n");
}

void generate_one_line_no_newline_file() {
    FILE *file = fopen("files/one_line_no_newline.txt", "w");
    if (file == NULL) {
        perror("Failed to create one_line_no_newline.txt");
        exit(1);
    }
    fprintf(file, "HelloWorld");
    fclose(file);
    printf("Generated one_line_no_newline.txt\n");
}

void generate_multiple_lines_file() {
    FILE *file = fopen("files/multiple_lines.txt", "w");
    if (file == NULL) {
        perror("Failed to create multiple_lines.txt");
        exit(1);
    }
    fprintf(file, "Line 1\nLine 2\nLine 3\nLine 4\n");
    fclose(file);
    printf("Generated multiple_lines.txt\n");
}

void generate_only_newlines_file() {
    FILE *file = fopen("files/only_newlines.txt", "w");
    if (file == NULL) {
        perror("Failed to create only_newlines.txt");
        exit(1);
    }
    fprintf(file, "\n\n\n\n\n");  // Just newlines
    fclose(file);
    printf("Generated only_newlines.txt\n");
}

void generate_large_file() {
    FILE *file = fopen("files/large_file.txt", "w");
    if (file == NULL) {
        perror("Failed to create large_file.txt");
        exit(1);
    }
    for (int i = 0; i < 1000000; i++) {
        fprintf(file, "This is a line in the large file.\n");
    }
    fclose(file);
    printf("Generated large_file.txt\n");
}

void generate_multiple_newlines_file() {
    FILE *file = fopen("files/multiple_newlines.txt", "w");
    if (file == NULL) {
        perror("Failed to create multiple_newlines.txt");
        exit(1);
    }
    fprintf(file, "First Line\n\n\n\nSecond Line\n\nThird Line\n");
    fclose(file);
    printf("Generated multiple_newlines.txt\n");
}

int main() {
    generate_empty_file();
    generate_one_line_no_newline_file();
    generate_multiple_lines_file();
    generate_only_newlines_file();
    generate_large_file();
    generate_multiple_newlines_file();

    return 0;
}
