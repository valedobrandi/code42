#!/bin/bash

EXECUTABLE="./RPN"
TESTS=(
    "8 9 * 9 - 9 - 9 - 4 - 1 +"
    "7 7 * 7 -"
    "1 2 * 2 / 2 * 2 4 - +"
    "(1 + 1)"
    ""
    "0"
    "8 9 * 9 - 9 - 9 - 4 - 1 + 0 - 8 * 2 + 8"
    "0 10 /"
)

for arg in "${TESTS[@]}"; do
    echo -n "$arg" "=> "
    "$EXECUTABLE" "$arg"
done