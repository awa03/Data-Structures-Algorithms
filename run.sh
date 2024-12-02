
#!/bin/bash

# Function to compile and run tests while measuring execution time
compile_and_run_tests() {
    local dir=$1
    local total_time=0  # Variable to keep track of total time

    for test_file in $dir/**/tests.cpp; do
        output_file="${test_file%.cpp}.out"

        # Compile the test file
        g++ $test_file -o "$output_file"
        if [ $? -eq 0 ]; then
            # Measure execution time for the test
            start_time=$(date +%s%N)
            ./$output_file
            end_time=$(date +%s%N)

            # Calculate elapsed time in milliseconds
            elapsed=$(( (end_time - start_time) / 1000000 ))
            total_time=$((total_time + elapsed))

            # Print time for this test in bold blue
            echo "\033[1;34mTest completed in ${elapsed} ms\033[0m"
        else
            echo -e "\033[31mCompilation failed for $test_file\033[0m"
        fi
    done

    # Print total time for all tests in the directory in bold blue
    echo "\033[1;34mTotal time for all tests in $dir: ${total_time} ms\033[0m"
}

# Run tests in Data-Structures and Algorithms directories
compile_and_run_tests "./Data-Structures"
compile_and_run_tests "./Algorithms"

