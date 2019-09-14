./generator --big-superposition > test_away && valgrind --leak-check=full ./lem-in -qc < test_away
