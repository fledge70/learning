/**
 * this program counts lines, words, and characters; where a word
 * is loosely defined as any sequence of characters that does not
 * contain a blank, tab, or newline
 */
#include <stdio.h>

/**
 * count lines, words, and chars in input
 */
int main() {

    const int IN = 1;
    const int OUT = 0;
    
    int c = 0,
    	nl = 0,
    	nw = 0,
    	nc = 0,
    	state = OUT;

    while ( (c= getchar()) != EOF) {
    	nc++;
    	if (c == '\n')
    		nl++;
    	if (c == ' ' || c == '\n' || c == '\t')
    		state = OUT;
    	else if (state == OUT) {
    		state = IN;
    		nw++;
    	}
    }
    printf("\nlines: %d, words: %d, chars: %d\n", nl, nw, nc);

    return 0;
}