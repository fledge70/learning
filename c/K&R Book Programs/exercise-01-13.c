/**
 * this program prints a histogram of the lengths of words
 * in its input
 */
#include <stdio.h>

/**
 * take input, count its word lengths, and report that
 * information in a histogram
 */
int main() {

    // define constants to increase readability of 'state' variable
	const int IN = 1;
	const int OUT = 0;

    // define and initialize variables
	int c = 0,
        currentWordLength = 0,
		state = OUT,
        counts[9] = {0},
        countsLength = 0;

    while ( (c = getchar()) != EOF) {
    	if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (currentWordLength < 8) {
                ++counts[currentWordLength];
            } else {
                ++counts[8];
            }
        }
    	else if (state == OUT) {
    		state = IN;
    		currentWordLength = 1;
    	} else {
            currentWordLength++;
        }
    }

    // Confirm number of elements in counts array
    countsLength = sizeof(counts) / sizeof(int);
    // Display histogram
    printf("\nHistogram distribution of word lengths:\n");
    for (int i = 1; i < countsLength; i++) {
        printf("%2d", i);
        if (i == countsLength - 1) {
            putchar('+');
        } else {
            putchar(' ');
        }
        printf(": ");
        for (int j = 0; j < counts[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}