#include <stdio.h>

/**
 * this program copies its input to its output, replacing each
 * string of one or more spaces with a single space
 */
int main() {

    int c = 0,
    	lastChar = 0;

    while ( (c = getchar()) != EOF) {
    	if ( !(c == ' ' && lastChar == ' ') )
    		putchar(c);
    	lastChar = c;
    }

    return 0;
}