#!/bin/bash

# Compile the program using Makefile
make

# Test cases
for i in {1..3}; do
    ./sed_is_for_losers input${i}.txt "string_to_replace" "replacement_string"
    diff test_files/test${i}.txt.replace test_files/expected_output${i}.txt > /dev/null

    if [ $? -eq 0 ]; then
        echo "Test Case $i Passed"
    else
        echo "Test Case $i Failed"
    fi
done

# Edge case: File is empty
echo -n > test_files/test_empty.txt
./sed_is_for_losers test_files/test_empty.txt "string_to_replace" "replacement_string"
if [ -s test_files/test_empty.txt.replace ]; then
    echo "Empty File Test Failed (Output should be empty)"
else
    echo "Empty File Test Passed"
fi

# Edge case: File does not exist
if ./sed_is_for_losers test_files/non_existent.txt "string_to_replace" "replacement_string"; then
    echo "Non-existent File Test Failed (Should not succeed)"
else
    echo "Non-existent File Test Passed"
fi

# Clean up (optional)
rm test_files/test_empty.txt test_files/test_empty.txt.replace

# Other possible test cases:
# - File is a directory
# - File is a symlink
# - File is a device file
# - File is a socket
# - File is a pipe
# - File is a binary file
# - File is a text file
# - File is a large file
# - File is a small file
# - File is a file with no newlines
# - File is a file with only newlines
# - File is a file with only one line
# - File is a file with only one character
# - File is a file with only one word
# - File is a file with only one word and no newlines
# - File is a file with only one word and one newline
# - File is a file with only one word and multiple newlines
# - File is a file with only one word and multiple newlines and spaces
# - File is a file with only one word and multiple newlines and tabs

# - Read-Only File: Attempt to process a file that has read-only permissions. The program should handle this gracefully, possibly by notifying the user.

# - Binary File: Try processing a binary file instead of a text file to see how the program behaves with non-textual data.

# - File with Special Characters: Test files with unusual or special characters in their content, including newlines, tabs, Unicode characters, etc.

# - String to Replace Not Present: Use an input file where the string that is supposed to be replaced does not actually occur. The program should ideally leave the file unchanged.

# - Replacement String is Empty: Check how the program behaves when the replacement string is empty. It should remove occurrences of the target string.

# - Target String is Empty: See how the program reacts if the target string (the one to be replaced) is empty. This might lead to unexpected behavior.

# - File with Only the Target String: Create a file where the entire content is just the string that needs to be replaced.

# - File with No Readable Content: Test with a file that has permissions set in such a way that it cannot be read by the user running the program.

# - Symlink File: Try processing a symbolic link to see how the program handles it.

# - File with Long Lines: Test with a file that has extremely long lines without any newlines, which can be challenging for some line-based processing tools.

#- Target and Replacement Strings are Identical: Check the behavior when the string to be replaced is the same as the replacement string.

# - Concurrent Access: Attempt to process a file that is simultaneously being written to or read by another process. This might not be applicable in all cases but could be relevant for certain applications.

# - Each of these tests can reveal different aspects of how your program deals with less common situations, helping you ensure that it's robust and reliable under a wide range of conditions.
