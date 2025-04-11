#!/bin/bash

# Generate test files
cd test
gcc -o generate_test_files generate_test_files.c
./generate_test_files
cd ..

# Array of different BUFFER_SIZE values
BUFFER_SIZES=(1 42 64 128 1024 9999 9999999999)

# Loop through each BUFFER_SIZE value
for BUFFER_SIZE in "${BUFFER_SIZES[@]}"; do
    echo -e "Running tests with BUFFER_SIZE=$BUFFER_SIZE...\n"

	make fclean
    # Run the tests with the current BUFFER_SIZE value
    make re BUFFER_SIZE=$BUFFER_SIZE run_tests

    echo "------------------------------------------------"
done
