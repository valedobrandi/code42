.SILENT:

SRC_DIR = ../
INCLUDE_DIR = ../
OBJ_DIR = test/obj
TEST_DIR = test

VALGRID = @valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all

CC = cc

TEST_BINS = \
	$(TEST_DIR)/test_empty_file \
	$(TEST_DIR)/test_invalid_fd \
	$(TEST_DIR)/test_large_file \
	$(TEST_DIR)/test_multiple_lines \
	$(TEST_DIR)/test_multiple_newlines \
	$(TEST_DIR)/test_one_line_no_newline \
	$(TEST_DIR)/test_only_newlines \
	$(TEST_DIR)/test_single_char \
	$(TEST_DIR)/test_large_line \
	$(TEST_DIR)/test_no_newline_end \
	$(TEST_DIR)/test_multiple_consecutive_new_lines \
	$(TEST_DIR)/test_very_larger_line \
	$(TEST_DIR)/test_multiple_small_lines

ifeq ($(origin BUFFER_SIZE), undefined)
    # BUFFER_SIZE is not defined, no -D BUFFER_SIZE flag
    CFLAGS = -Wall -Wextra -Werror -g
else
    # BUFFER_SIZE is defined, add -D BUFFER_SIZE=$(BUFFER_SIZE)
    CFLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=$(BUFFER_SIZE)
endif

# Library files
LIBRARY = $(SRC_DIR)get_next_line.c $(SRC_DIR)get_next_line_utils.c

# Create the object directory
$(shell mkdir -p $(OBJ_DIR))

# Rule to compile object files for tests
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(SRC_DIR) -c $< -o $@

# Rule to link a test binary
$(TEST_DIR)/%: $(OBJ_DIR)/%.o $(LIBRARY)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(SRC_DIR) $^ -o $@

test_empty_file: $(TEST_DIR)/test_empty_file
	-$(VALGRID) ./$< 2> logs.txt

test_invalid_fd: $(TEST_DIR)/test_invalid_fd
	-$(VALGRID) ./$< 2> logs.txt

test_large_file: $(TEST_DIR)/test_large_file
	-$(VALGRID) ./$< 2> logs.txt

test_large_line: $(TEST_DIR)/test_large_line
	-$(VALGRID) ./$< 2> logs.txt

test_multiple_consecutive_new_lines: $(TEST_DIR)/test_multiple_consecutive_new_lines
	-$(VALGRID) ./$< 2> logs.txt

test_multiple_lines: $(TEST_DIR)/test_multiple_lines
	-$(VALGRID) ./$< 2> logs.txt

test_multiple_newlines: $(TEST_DIR)/test_multiple_newlines
	-$(VALGRID) ./$< 2> logs.txt

test_multiple_small_lines: $(TEST_DIR)/test_multiple_small_lines
	-$(VALGRID) ./$< 2> logs.txt

test_no_newline_end: $(TEST_DIR)/test_no_newline_end
	-$(VALGRID) ./$< 2> logs.txt

test_one_line_no_newline: $(TEST_DIR)/test_one_line_no_newline
	-$(VALGRID) ./$< 2> logs.txt

test_only_newlines: $(TEST_DIR)/test_only_newlines
	-$(VALGRID) ./$< 2> logs.txt

test_single_char: $(TEST_DIR)/test_single_char
	-$(VALGRID) ./$< 2> logs.txt

test_very_larger_line: $(TEST_DIR)/test_very_larger_line
	-$(VALGRID) ./$< 2> logs.txt

all: $(TEST_OBJECTS) $(TEST_BINS)

# Clean up object files and the executables
clean:
	@rm -rf $(OBJ_DIR)/*.o

# Main target

# Fully clean (remove everything)
fclean: clean
	@rm -f $(TEST_BINS)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re \
	test_empty_file test_invalid_fd test_large_file test_multiple_lines test_large_line \
	test_multiple_newlines test_one_line_no_newline test_only_newlines test_single_char \
	test_no_newline_end test_multiple_consecutive_new_lines test_very_larger_line



