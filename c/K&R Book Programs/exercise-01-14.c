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

    // define and initialize variables. 'charCounts' is large enough
    // to support standard ASCII set represented by one byte
	int c = 0,
        charCounts[256] = {0};

    // read input and count occurences of each character
    while ( (c = getchar()) != EOF) {
    	charCounts[c]++;
    }

    /**
     * loop through charCounts array. Assuming its size is unknown
     * (or changed) so I can practice getting its length.
     * Print character and its histogram line for any non-zero values.
     */
    int charCountsLength = sizeof(charCounts) / sizeof(int);
    //this counter starts at 33 so that non-printable chars are skipped
    for (int i = 33; i < charCountsLength; i++) {
    	if (charCounts[i] > 0) {
    		printf("\n%2c: ", i);
    		for (int j = 0; j < charCounts[i]; j++) {
    			printf("*");
    		}
    	}
    }

    // print blank line for cosmetic purposes
    putchar('\n');

    // return control back to the OS with a clean exit code
    return 0;
}