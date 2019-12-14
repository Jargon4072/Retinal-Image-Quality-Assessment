#!/bin/bash
if [[ $# -eq 1 ]]; then 
#./featur $1; 
#./res theta.txt feature.txt; 

# relative path 
#for file in ./$1/*; do
#absolution path
#for file in $1/*; do
for file in ./$1/*; do
    echo "$(basename "$file")"
    ./featur $file; 
	#echo $file >> txt
	./res theta.txt feature.txt $file >> txtVF1_02_07122019.csv;
done
fi

