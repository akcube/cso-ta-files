import os
import subprocess
import csv

# Get the list of all text files in the current directory
txt_files = [f for f in os.listdir('.') if os.path.isfile(f) and f.endswith('.cpp')]
names_to_filter = ["helper.cpp", "sgemm_bench.cpp", "gen.cpp"]

filtered_names = []
for name in txt_files:
    if name in names_to_filter:
        continue
    filtered_names.append(name)

# Initialize a dictionary to store the grades
grades = {}

print("Filtered file set: ", filtered_names)

# Loop through each text file, read its contents, and grade the submission
for file_name in filtered_names:
    print("Grading: ", file_name)

    try:
        roll_number = file_name.split('.')[0]
        
        # Copy the contents of the submission to "gemm.cpp"
        with open(file_name, 'r') as f1, open('gemm.cpp', 'w') as f2:
            f2.write(f1.read())
        
        # Compile the benchmarking code
        compiled = False
        try:
            result = subprocess.run(['g++', '-Ofast', '-march=native', 'sgemm_bench.cpp', '-o', 'sgemm_bench', '-std=c++11', '-w'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            if result.returncode != 0:
                score = 0
                grades[roll_number] = score
                print(" => Compilation error: ", e)
            else:
                compiled = True
        except Exception as e:
            grades[roll_number] = 0
            print(" => Compilation error: ", e)
        
        if not compiled:
            continue
        # Run the benchmarking code and get the output
        try:
            result = subprocess.run('./sgemm_bench', stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            print(result.stdout)
            # Check if the benchmarking code ran successfully
            if result.returncode != 0:
                score = 0
                print(" => Wrong return code")
            else:
                # Get the score from the output
                try:
                    score = float(result.stdout)
                    print(score)
                except Exception as e:
                    print(" => Error: ", e)
                    score = 0
        except Exception as e:
            print(" => Error: ", e)
            score = 0
        
        # Store the score in the grades dictionary
        grades[roll_number] = score
    except Exception as e:
        print(" => Unexpected Error: ", e)

print(grades)
# Write the grades to a CSV file
with open('grades.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(['Rollnumber', 'Grade'])
    for roll_number, grade in grades.items():
        writer.writerow([roll_number, grade])

subprocess.run(['rm', 'gemm.cpp'])