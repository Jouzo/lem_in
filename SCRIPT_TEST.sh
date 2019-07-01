#!/bin/bash

FILES=map_samples/bad_tests/*.map
for f in $FILES
do
	ls $f >> output_test.log && cat $f | ./lem-in -q >> output_test.log
done