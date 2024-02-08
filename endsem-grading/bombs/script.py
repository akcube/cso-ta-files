import os
import csv

# Define the grading function for each phase
def grade_phase1(answer):
    if answer.strip() == "*":
        return 2
    else:
        return 0

def grade_phase2(answer):
    if answer.strip().startswith("pERHAPStHEsECRETpASSWORDyOUaRElOOKINGfOR"):
        return 3
    else:
        return 0

def grade_phase3(answer):
    sequence = list(map(int, answer.strip().split()))
    expected = [17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1]
    prefix_len = 0
    for i, num in enumerate(sequence):
        if i >= len(expected) or num != expected[i]:
            break
        prefix_len += 1
    return min(5, prefix_len*2 / len(expected) * 5)

# Get the list of all text files in the current directory
txt_files = [f for f in os.listdir('.') if os.path.isfile(f) and f.endswith('.txt')]

# Initialize a dictionary to store the grades
grades = {}
ids = [201556054, 2019101127, 2021101097, 2021101125, 2021113001, 2021113002, 2021113003, 2021113004, 2021113005, 2021113007, 2021113008, 2021113009, 2021113010, 2021113011, 2021113012, 2021113013, 2021113014, 2021113016, 2021113017, 2021113018, 2021114001, 2021114002, 2021114003, 2021114004, 2021114005, 2021114006, 2021114007, 2021114008, 2021114009, 2021114010, 2021114011, 2021114012, 2021114013, 2021114014, 2021114015, 2021114016, 2021114017, 2021114018, 2021115001, 2021115002, 2021115003, 2021115004, 2021115005, 2021115006, 2021115007, 2021115008, 2021115009, 2022909001, 2022909002, 2022909003]
for rno in ids:
    grades[str(rno)] = 0

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
        except:
            pass


# Write the grades to a CSV file
with open('grades.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(['Rollnumber', 'Grade'])
    for roll_number, grade in sorted(grades.items(), key=lambda x: x[0]):
        writer.writerow([roll_number, grade])

