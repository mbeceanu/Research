# Research
This repository is still a test. It contains some code I wrote for my research.

program2.7.c attempts a computational verification of the Taniyama-Shimura conjecture for primes in Z[i]  with 4k+1 norm up to 45,000 (for 4k+3 they are integers). In practice, this consisted in checking the rank of some large sparse square matrices (of size up to 45,000) with integer coefficients. I used modulo arithmetic. I also attempted to take advantage of the sparsity. In order to make the program run somewhat faster, I reserved a big memory block and defined my own memory allocation procedures :)

myprogram.c computes the period of the continued fraction of sqrt(n) (using integers, not floats) for a range of integers n, with the goal of establishing some asymptotics.
