#!/bin/bash

# Array of different BUFFER_SIZE values
BUFFER_SIZES=(1 42 64 128 1024 9999)

# All Tests
ALL_TESTS=(
    test_multiple_lines
    test_large_file
    test_multiple_newlines
    test_one_line_no_newline
	test_only_newlines
    test_single_char
    test_empty_file
    test_invalid_fd
)

# Pass a test as params ex: ./buffer_test.sh test_single_char
if [ -n "$1" ]; then
    TESTS=("$1")
else
    TESTS=("${ALL_TESTS[@]}")
fi

logs() {
    if grep -q "failed" logs.txt; then
        grep "failed" logs.txt
        exit 1
    elif ! grep -q "All heap blocks were freed -- no leaks are possible" logs.txt; then
        cat logs.txt
        exit 1
    fi
}

make fclean
for TEST in "${TESTS[@]}"; do
    if [ -f logs.txt ]; then
        rm logs.txt
    fi
    echo -e "\n\033[0;33m$TEST\033[0m"
    echo -e "BUFFER_SIZE..."
    for BUFFER_SIZE in "${BUFFER_SIZES[@]}"; do
        echo -n "$BUFFER_SIZE:"
        make BUFFER_SIZE=$BUFFER_SIZE $TEST 
        logs
    done
        echo -n "Default:"
        make $TEST
        logs
done
echo -e
logs 
if [ -f logs.txt ]; then
        rm logs.txt
fi
make fclean




