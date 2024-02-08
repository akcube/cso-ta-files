import os

# Define the current directory
current_dir = "."

# Iterate over each file in the current directory
for filename in os.listdir(current_dir):
    # Check if the file is a .txt file
    if filename.endswith(".txt"):
        # Construct the command to execute
        command = f"./cda < {filename}"

        # Execute the command and capture the output
        output = os.popen(command).read()

        # Write the output back to the file
        with open(filename, "w") as f:
            f.write(output)
