i = 0; while true; do
	echo $i
	./generator --big-superposition > test_big/test$i
	((i++))
done