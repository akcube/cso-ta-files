#!/bin/bash

filename=$(basename $1)
filename="${filename%.*}"

as -o "$filename.o" "$filename.s"
echo "Finished assembling $filename.s"

ld -o "$filename" -dynamic-linker /lib64/ld-linux-x86-64.so.2 /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o -lc "$filename.o" /usr/lib/x86_64-linux-gnu/crtn.o
echo "Finished linking $filename"
