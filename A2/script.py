import os
import csv

# Define the grading function for each phase
def grade_phase1(answer):
    if answer.strip() == "9000":
        return 5
    else:
        return 0

def grade_phase2(answer):
    try:
        a, b, c = map(int, answer.strip().split())
        if a + b - c == 42:
            return 5
        else:
            return 0
    except ValueError:
        return 0

def grade_phase3(answer):
    if answer.strip().lower().startswith("openthepodbaydoorshal"):
        return 5
    else:
        return 0

def grade_phase4(answer):
    numbers = answer.strip().split()
    try:
        n = int(numbers[0])
        sequence = list(map(int, numbers[1:]))
        if n != len(sequence) or n < 5 or n > 9000:
            return 0
        for i in range(n):
            if i % 2 == 0 and sequence[i] % 2 != 0:
                return 0
            elif i % 2 == 1 and sequence[i] % 2 != 1:
                return 0
        return 5
    except ValueError:
        return 0

def grade_phase5(answer):
    factors = answer.strip().split()
    if set(factors) == set(['2', '3', '5']) and len(factors) == 8:
        return 5
    else:
        return 0

# Get the list of all text files in the current directory
txt_files = [f for f in os.listdir('.') if os.path.isfile(f) and f.endswith('.txt')]

# Initialize a dictionary to store the grades
grades = {}

# Loop through each text file, read its contents, and grade the submission
for file_name in txt_files:
    roll_number = file_name.split('_')[0]
    grades[roll_number] = 0
    with open(file_name, 'r') as f:
        contents = f.read()
        try:
            grades[roll_number] += grade_phase1(contents.split('\n')[0])
            grades[roll_number] += grade_phase2(contents.split('\n')[1])
            grades[roll_number] += grade_phase3(contents.split('\n')[2])
            grades[roll_number] += grade_phase4(contents.split('\n')[3])
            grades[roll_number] += grade_phase5(contents.split('\n')[4])
        except:
            pass

# Write the grades to a CSV file
with open('grades.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(['Rollnumber', 'Grade'])
    for roll_number, grade in grades.items():
        writer.writerow([roll_number, grade])
