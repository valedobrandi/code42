#!/bin/bash

for file in maps_error/*; do
    echo "🧪 Testing: $file"
    ./cub3d "$file"
    echo "----------------------------"
done
