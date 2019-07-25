#!/bin/sh

input="test.txt"
temp=""
while IFS= read -r line
do
	echo "$line" > /dev/ttyUSB1
  	sleep .5;
done < "$input"
