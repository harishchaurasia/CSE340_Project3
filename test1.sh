#!/bin/bash

let count=0;

for f in $(ls /Users/harishchaurasia/Desktop/CSE340_PROJECT3/testCases/*.txt); do 
    ./a.out < "$f" > "/Users/harishchaurasia/Desktop/CSE340_PROJECT3/testCases/$(basename "$f" .txt).output"; 
done;

for f in $(ls /Users/harishchaurasia/Desktop/CSE340_PROJECT3/testCases/*.output); do
    diff -Bw "$f" "/Users/harishchaurasia/Desktop/CSE340_PROJECT3/testCases/$(basename "$f" .output).txt.expected" > "/Users/harishchaurasia/Desktop/CSE340_PROJECT3/testCases/$(basename "$f" .output).diff";
done

for f in $(ls /Users/harishchaurasia/Desktop/CSE340_PROJECT3/testCases/*.diff); do
    echo "========================================================";
    echo "FILE: $(basename "$f" .diff)";
    echo "========================================================";
    if [ -s "$f" ]; then
        cat "/Users/harishchaurasia/Desktop/CSE340_PROJECT3/testCases/$(basename "$f" .diff).txt";
        echo "--------------------------------------------------------";
        cat "$f"
    else
        count=$((count+1));
        echo "NO ERRORS HERE!";
    fi
done

echo "$count";

rm /Users/harishchaurasia/Desktop/CSE340_PROJECT3/testCases*.output
rm /Users/harishchaurasia/Desktop/CSE340_PROJECT3/testCases*.diff
