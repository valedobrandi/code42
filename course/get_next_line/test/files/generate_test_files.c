#include <stdio.h>
#include <stdlib.h>

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

void generate_single_char_file() {
    FILE *file = fopen("files/single_char.txt", "w");
    if (file == NULL) {
        perror("Failed to create single_char.txt");
        exit(1);
    }
    fprintf(file, "A");
    fclose(file);
    printf("Generated single_char.txt\n");
}


int main() {
    generate_empty_file();
    generate_one_line_no_newline_file();
    generate_multiple_lines_file();
    generate_only_newlines_file();
    generate_large_file();
    generate_multiple_newlines_file();
    generate_single_char_file();

    return 0;
}
