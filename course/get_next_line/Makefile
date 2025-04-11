.SILENT:

BUFFER_SIZE = 42
VALGRID = valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all

CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=${BUFFER_SIZE}
SRC_DIR = project/
INCLUDE_DIR = project/
OBJ_DIR = test/obj

# Library files
LIBRARY = $(SRC_DIR)get_next_line.c $(SRC_DIR)get_next_line_utils.c

# Test sources
TEST_SOURCES = $(wildcard test/test_*.c)
TEST_OBJECTS = $(patsubst test/%.c, $(OBJ_DIR)/%.o, $(TEST_SOURCES))
TEST_BINS = $(patsubst test/%.c, test/%, $(TEST_SOURCES))

# Create the object directory
$(shell mkdir -p $(OBJ_DIR))

# Main target
all: $(TEST_OBJECTS) $(TEST_BINS)

# Compile and link each test separately
test/%: $(OBJ_DIR)/%.o
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $< $(LIBRARY) -o $@

# Compile test source files
$(OBJ_DIR)/%.o: test/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Fully clean (remove everything)
fclean: clean
	rm -f $(TEST_BINS)

# Run all tests
run_tests:
	@for test in $(TEST_BINS); do \
		${VALGRID} ./$$test 2>/dev/null; \
		echo "---------------------------------------------"; \
	done

# Clean up object files and the executables
clean:
	rm -rf $(OBJ_DIR)/*.o

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re run_tests


