#!/bin/bash

for filename in /Users/jdescler/42/lem_in/test_big/*; 
	do echo "$filename"	>> output_valgrind.log
	valgrind ./lem-in < "$filename" 2>> output_valgrind.log 1>/dev/null
done