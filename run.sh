
#!/bin/bash

compile_and_run_tests() {
    local dir=$1
    # echo "Compiling tests in directory: $dir"
    
    for test_file in $dir/**/tests.cpp; do
        output_file="${test_file%.cpp}.out"
        
        # echo "Compiling $test_file to $output_file"
        g++ $test_file -o "$output_file"
        
        if [ $? -eq 0 ]; then
            # echo "Successfully compiled $output_file"
            # echo "Running $output_file"
            ./$output_file  
        else
            echo "Compilation failed for $test_file"
        fi
    done
}

compile_and_run_tests "./Data-Structures"

compile_and_run_tests "./Algorithms"

