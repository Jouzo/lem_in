#!/bin/bash

FILES=map_samples/bad_tests/*.map
for f in $FILES
do
	ls $f | tee -a output_test.log >> valgrind.log && cat $f | valgrind --log-fd=9 9>> valgrind.log ./lem-in -q >> output_test.log 
done