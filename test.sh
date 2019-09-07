./generator --big-superposition > test_thousand && ./lem-in -qc < test_thousand | wc -l && grep line test_thousand | grep -o '...$'
