import os
import subprocess
import sys

# Read in arguments
solution_program = sys.argv[1]
test_cases_path = sys.argv[2]
sols_path = sys.argv[3]

# run the test case generator 35 times
for i in range(1, 36):
    # Construct the path for the test case and solution files
    test_case_file = os.path.join(test_cases_path, f"{i}.txt")
    sol_file = os.path.join(sols_path, f"{i}.txt")
    passed = True

    # Run the compiled program against the input test and save the output in output.txt
    with open('output.txt', 'w') as output_file:
        with open(test_case_file, 'r') as input_file:
            try:
                # Use timeout command to limit the execution time of the program
                subprocess.run(["timeout", str(2), solution_program], stdin=input_file, stdout=output_file, check=True)
            except subprocess.TimeoutExpired:
                # The program took too long to execute, so we'll kill the process and fail the case
                os.killpg(os.getpgid(proc.pid), signal.SIGTERM)
                passed = False

    # Compare the output.txt file with the expected output
    with open('output.txt', 'r') as output_file:
        with open(sol_file, 'r') as expected_output_file:
            if output_file.read().strip() != expected_output_file.read().strip():
                passed = False

    if passed:
        print(f"Test case {i}: SUCCESS")
    else:
        print(f"Test case {i}: FAIL")

# Remove temp files
if os.path.exists("output.txt"):
    os.remove("output.txt")
