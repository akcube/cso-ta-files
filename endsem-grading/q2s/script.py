import os
import csv
import subprocess

# Compile all the submission files
for filename in os.listdir('.'):
    if filename.endswith('_q2.s'):
        rollnumber = filename.split('_')[0]
        binary = rollnumber + '_q2'
        try:
            subprocess.run(['gcc', '-o', binary, filename])
        except:
            print("Couldn't compile: ", rollnumber)

# Run tests on each binary and grade
scores = {}
ids = [201556054, 2019101127, 2021101097, 2021101125, 2021113001, 2021113002, 2021113003, 2021113004, 2021113005, 2021113007, 2021113008, 2021113009, 2021113010, 2021113011, 2021113012, 2021113013, 2021113014, 2021113016, 2021113017, 2021113018, 2021114001, 2021114002, 2021114003, 2021114004, 2021114005, 2021114006, 2021114007, 2021114008, 2021114009, 2021114010, 2021114011, 2021114012, 2021114013, 2021114014, 2021114015, 2021114016, 2021114017, 2021114018, 2021115001, 2021115002, 2021115003, 2021115004, 2021115005, 2021115006, 2021115007, 2021115008, 2021115009, 2022909001, 2022909002, 2022909003]
for rno in ids:
    scores[str(rno)] = 0

for filename in os.listdir('.'):
    if filename.endswith('_q2'):
        rollnumber = filename.split('_')[0]
        binary = rollnumber + '_q2'
        score = 0
        for test_file in os.listdir('tests'):
            if test_file.endswith('.txt'):
                input_file = os.path.join('tests', test_file)
                expected_file = os.path.join('sols', test_file)
                with open(input_file, 'r') as f:
                    input_data = f.read().strip()
                    try:
                        print("Running: ", rollnumber, " => test/", test_file)
                        output_data = subprocess.run(['timeout', '5s', './'+binary], input=input_data, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, check=True, text=True).stdout.strip()
                        with open(expected_file, 'r') as f:
                            expected_data = f.read().strip()
                        if output_data == expected_data:
                            score += 1
                    except Exception as e:
                        pass
        scores[rollnumber] = score

# Write scores to a CSV file
with open('scores.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(['Rollnumber', 'Score'])
    for rollnumber, score in sorted(scores.items(), key=lambda x: x[0]):
        writer.writerow([rollnumber, score])
