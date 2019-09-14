./generator --big-superposition > test_away && time ./lem-in -qc < test_away | wc -l && grep line test_away
