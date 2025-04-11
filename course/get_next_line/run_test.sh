#!/bin/bash

echo "Building all tests..."

PASS=true

# TESTS=( $(find test -maxdepth 1 -type f -executable -name 'test_*') )
TESTS=(test_large_file.c)

for TEST in "${TESTS[@]}"; do
    echo -e "Running $TEST...\n"

    ./test/$TEST
	result1=$?

	if [ $result -ne 0 ]; then
        echo "$TEST ❌"
        PASS=false
    else
        echo "$TEST ✅"
    fi
done

# Check overall results
if [ "$PASS" = true ]; then
    echo "All tests passed! 🎉"
    exit 0
else
    echo "Some tests failed! ❌"
    exit 1
fi

