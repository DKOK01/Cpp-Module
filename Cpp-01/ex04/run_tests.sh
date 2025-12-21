#!/bin/bash

# Test script for the replace program
# This script tests various edge cases and scenarios

echo "=== Building the program ==="
make re
echo ""

echo "=== Test 1: Basic replacement ==="
echo "Command: ./replace test1.txt hello hi"
./replace test1.txt hello hi
echo "Original file:"
cat test1.txt
echo ""
echo "Result file:"
cat test1.txt.replace
echo ""

echo "=== Test 2: No matches found ==="
echo "Command: ./replace test2.txt NOTFOUND REPLACEMENT"
./replace test2.txt NOTFOUND REPLACEMENT
echo "Original file:"
cat test2.txt
echo ""
echo "Result file:"
cat test2.txt.replace
echo ""

echo "=== Test 3: Overlapping patterns ==="
echo "Command: ./replace test3.txt AAA BBB"
./replace test3.txt AAA BBB
echo "Original file:"
cat test3.txt
echo ""
echo "Result file:"
cat test3.txt.replace
echo ""

echo "=== Test 4: Empty file ==="
echo "Command: ./replace empty.txt hello world"
./replace empty.txt hello world
echo "Original file (empty):"
cat empty.txt
echo ""
echo "Result file:"
cat empty.txt.replace
echo ""

echo "=== Test 5: Replace with empty string (deletion) ==="
echo "Command: ./replace test1.txt hello ''"
./replace test1.txt hello ""
echo "Original file:"
cat test1.txt
echo ""
echo "Result file:"
cat test1.txt.replace
echo ""

echo "=== Test 6: Error - Empty s1 ==="
echo "Command: ./replace test1.txt '' world"
./replace test1.txt "" world
echo ""

echo "=== Test 7: Error - Wrong number of arguments ==="
echo "Command: ./replace test1.txt hello"
./replace test1.txt hello
echo ""

echo "=== Test 8: Error - File doesn't exist ==="
echo "Command: ./replace nonexistent.txt hello world"
./replace nonexistent.txt hello world
echo ""

echo "=== All tests completed ==="
