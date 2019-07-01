#!/bin/bash

FILES=map_samples/incomplete_map/*.map
for f in $FILES
do
	ls $f >> output_test_incomplete.log && cat $f | ./lem-in -q >> output_test_incomplete.log
done