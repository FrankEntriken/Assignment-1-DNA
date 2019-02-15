Frank Entriken
2298368
entriken@chapman.edu
CPSC 350
Assignment 1: DNA

This program will process a list of random nucleotide strings within a text file. The program will find the probability of
each nucleotide and nucleotide bigram, as well as take statistics such as the mean, sum, variance, and standard deviation
from the length of each string in the file. The program will then generate a list of 1000 new strings that follow the Gaussian
Distribution of the given file. These generated strings will also follow the probability of each singular nucleotide from
the given file.

Known Error: When processing a file a second time after prompted, all zero values will instead show up as an incredibly low number
             that is approximately zero (6.95288e-310). This does not affect the outcome of any of the computed values like sum,
             mean, variance, or standard deviation.

Sources are cited inline with where they were used.

Sources used:
https://www.geeksforgeeks.org/how-to-convert-a-single-character-to-string-in-cpp/
https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case
http://www.cplusplus.com/forum/beginner/30644/
https://stackoverflow.com/questions/9459035/why-does-rand-yield-the-same-sequence-of-numbers-on-every-run
https://stackoverflow.com/questions/1727881/how-to-use-the-pi-constant-in-c
