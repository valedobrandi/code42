get_next_line test

This project provides a set of tests for buffer size handling in a C project. The tests are designed to evaluate memory management and ensure no memory leaks occur when different buffer sizes are used.

Running All Tests
./buffer_test.sh

Running a Specific Test
To run a single test (e.g., test_single_char), pass the test name as a parameter:
./buffer_test.sh test_single_char

The Makefile includes the following targets:

all: Compiles all tests and objects.

clean: Removes object files.

fclean: Fully cleans (removes object files and executables).

re: Rebuilds everything from scratch.

test_<test_name>: Each individual test (e.g., test_empty_file, test_invalid_fd) will run under Valgrind for memory leak checks.

The tests use Valgrind to check for memory leaks, so if Valgrind reports issues, check the logs (logs.txt) for more detailed information.
