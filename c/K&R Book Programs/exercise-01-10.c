#include <stdio.h>

/**
 * this program copies its input to its output, replacing tabs,
 * backspaces, and backslashes with strings representing those
 * characters
 */
int main() {

    int c = 0;

    while ( (c = getchar()) != EOF) {
    	if (c == '\t') {
    		putchar('\\');
    		putchar('t');
    	} else if (c == '\b') {
    		putchar('\\');
    		putchar('b');
    	} else if (c == '\\') {
    		putchar('\\');
    		putchar('\\');
    	} else {
    		putchar(c);
    	}
    }

    return 0;
}