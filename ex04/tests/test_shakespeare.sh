#!/bin/bash

# Define the file paths
original_file="test_files/shakespeare.txt"
modified_file="${original_file}.replace"

# Function to count occurrences of a substring
count_occurrences() {
    local substring=$1
    local file=$2
    grep -o "$substring" "$file" | wc -l
}

# Count occurrences of "the" and "bla" in the original file
count_the_before=$(count_occurrences "the" "$original_file")
count_bla_before=$(count_occurrences "bla" "$original_file")
echo "Before replacement:"
echo "\"the\" occurs $count_the_before times."
echo "\"bla\" occurs $count_bla_before times."

# Call the replacement program
../sed_is_for_losers "$original_file" the bla

# Make sure the replacement was successful and the file exists
if [ ! -f "$modified_file" ]; then
    echo "Replacement file $modified_file not found."
    exit 1
fi

# Count occurrences of "the" and "bla" in the modified file
count_the_after=$(count_occurrences "the" "$modified_file")
count_bla_after=$(count_occurrences "bla" "$modified_file")
echo "After replacement:"
echo "\"the\" occurs $count_the_after times."
echo "\"bla\" occurs $count_bla_after times."
