/**
 * this program takes input and prints it back
 * with one word per line
 */
#include <stdio.h>

/**
 * echo back input broken out with one word per line
 */
int main() {

	const int IN = 1;
	const int OUT = 0;

	int c = 0,
		state = OUT;

    while ( (c= getchar()) != EOF) {
    	if (c == ' ' || c == '\n' || c == '\t')
    		state = OUT;
    	else if (state == OUT) {
    		state = IN;
    		putchar('\n');
    	}
    	putchar(c);
    }

    return 0;
}