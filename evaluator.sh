#!/bin/sh

#Count the line after removing extra new lines
sed '/^$/d' $1 > .tempfile
cnt=$(cat .tempfile | wc -l)

#Compile the code
gcc TemporalDifference.c -o TemporalDifference.o -lm

#Run the code on the argumented data file
./TemporalDifference.o $1 $cnt
rm -f .tempfile
