#!/bin/bash

# Array of different BUFFER_SIZE values
BUFFER_SIZES=(1 42 64 128 1024 9999)

# All Tests
ALL_TESTS=(
    test_empty_file
    test_invalid_fd
    test_large_file
    test_multiple_lines
    test_multiple_newlines
    test_one_line_no_newline
	test_only_newlines
    test_single_char
)

# Pass a test as params ex: ./buffer_test.sh test_single_char
if [ -n "$1" ]; then
    TESTS=("$1")
else
    TESTS=("${ALL_TESTS[@]}")
fi

for TEST in "${TESTS[@]}"; do
    if [ -f logs.txt ]; then
        rm logs.txt
    fi
    echo -e "\n\033[0;33m$TEST\033[0m"
    echo -e "BUFFER_SIZE..."
    for BUFFER_SIZE in "${BUFFER_SIZES[@]}"; do
        echo -n "$BUFFER_SIZE: "
        make BUFFER_SIZE=$BUFFER_SIZE $TEST
        if grep -q "All heap blocks were freed -- no leaks are possible" "logs.txt"; then
            :
        else
            cat "logs.txt"
            exit 1
        fi
    done

        echo -n "default: "
        make $TEST
        if grep -q "All heap blocks were freed -- no leaks are possible" "logs.txt"; then
            :
        else
            cat "logs.txt"
            exit 1
        fi
done
echo -e




