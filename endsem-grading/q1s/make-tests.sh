#!/bin/bash

for file in tests/*.txt
do
  filename=$(basename "$file")
  output_file="sols/$filename"
  ./gcd < "$file" > "$output_file"
done
