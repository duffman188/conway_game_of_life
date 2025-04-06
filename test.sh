#!/bin/bash

# Helper function to compare the output with the expected output
compare_output() {
    local output="$1"
    local expected_output="$2"
    
    # Normalize output by trimming extra spaces and newlines
    output=$(echo "$output" | tr -s '[:space:]' '\n')
    expected_output=$(echo "$expected_output" | tr -s '[:space:]' '\n')

    # Check if output matches expected output
    if [[ "$output" == "$expected_output" ]]; then
        echo "Pass: Output matches expected grid"
    else
        echo "Fail: Expected grid not found"
        echo "Expected:"
        echo "$expected_output"
        echo "Got:"
        echo "$output"
        exit 1
    fi
}

# Test 1: Run with a 5x5 grid, 5 generations (expected final grid pattern)
echo "Test 1: Running with a 5x5 grid, 5 generations"
output=$(./game_of_life 5 5 5 | tail -n 5)  # Only get the last 5 lines (the grid after 5 generations)

# Expected grid pattern after 5 generations
expected_output="..... ..... ..... ..X.X ...XX"

echo "$output"
compare_output "$output" "$expected_output"

# Test 2: Run with a 5x5 grid, 0 generations (grid should remain unchanged)
echo "Test 2: Running with a 5x5 grid, 0 generations"
output=$(./game_of_life 5 5 0 | tail -n 5)  # Only get the last 5 lines (the grid after 0 generations)

# Initial grid before any generations
expected_output="Error: Width, height, and generations must be positive integers."

echo "$output"
compare_output "$output" "$expected_output"

# Test 3: Run with invalid input (negative width)
echo "Test 3: Running with invalid input (negative width)"
output=$(./game_of_life -5 5 5)
expected_output="Error: Width, height, and generations must be positive integers."
echo "$output"
compare_output "$output" "$expected_output"

# Test 4: Run with a 5x5 grid and 20 generations (testing a larger number of generations)
echo "Test 4: Running with a 5x5 grid, 20 generations"
output=$(./game_of_life 5 5 20 | tail -n 5)  # Get the last 5 lines (grid after 20 generations)

# Expected output (adjust based on pattern)
expected_output=".....
.....
.....
...XX
...XX"

echo "$output"
compare_output "$output" "$expected_output"

echo "All tests completed successfully!"
