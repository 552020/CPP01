#!/bin/bash

# Compile the program using Makefile
make

# Test cases
for i in {1..3}; do
    # Generate expected output (adjust this command based on your program's logic)
    sed 's/string_to_replace/replacement_string/g' input${i}.txt > expected_dynamic_output${i}.txt

    ./sed_is_for_losers input${i}.txt "string_to_replace" "replacement_string"
    diff input${i}.txt.replace expected_dynamic_output${i}.txt > /dev/null
    if [ $? -eq 0 ]; then
        echo "Test Case $i Passed"
    else
        echo "Test Case $i Failed"
    fi
done
