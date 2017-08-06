/**
 * This program folds long input lines into two or more
 * shorter lines after the last non-blank character that
 * occurs before the n-th column of input.  Program
 * intelligently handles very long lines, and instances
 * where there are no blanks or tabs before the desired
 * line length.
 */
#include <stdio.h>
#include <string.h>

// external constant definitions
const int MAXLINE = 1000;
const int LINE_LENGTH = 15;  // set to unrealistically low value to facilitate testing

// function declarations
int mygetline(char s[], int lim);
void foldLine(char to[], char from[], int fromLength, int lineLength);

/**
 * take input and run it against the foldLine function,
 * one line at a time
 */
int main()
{	
	// initialize variables
	char line[MAXLINE],					// original input captured
		modifiedLine[MAXLINE];			// input with spaces instead of tabs
    int len = 0;						// length of original input

    // keep getting lines from input until zero-length string received
	while ( (len = mygetline(line, MAXLINE)) > 0)
	{
        printf("\nLine length: %d\n", len);
        foldLine(modifiedLine, line, len, LINE_LENGTH);
    	printf("\nOriginal input:\n%s", line);
    	printf("\nInput folded:\n%s\n", modifiedLine);

    	// clear line contents before they are reused on next pass
    	memset(line, 0, sizeof(line));
    	memset(modifiedLine, 0, sizeof(modifiedLine));
    }
	return 0;
}

/**
 * mygetline: read a line into s, return length
 */
int mygetline(char s[], int lim)
{
	int c, i;

	// read in chars until max (lim), newline, or EOF is hit
	for (i = 0;
		i < lim - 1 && (c = getchar()) != EOF && c != '\n';
		++i)
	{
		s[i] = c;
	}
	
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/**
 * foldLine: adds newline characters to split
 * a long into line into multiple shorter lines of
 * length lineLength
 */
void foldLine(char to[], char from[], int fromLength, int lineLength)
{
	/**
	 * Summary of what happens in this function:
	 * 1) While copying from[] char array into to[], read ahead
	 *    to determine if that "word" will put the line over the limit
	 * 2) If it will, start a new line and start the counter over again
	 * 3) If the word will fill all of the current line plus all of the
	 *    next line, break it with '-' instead
	 */

	int toColumn = 0,		// track position within the output string
		fromColumn = 0,		// track position within the input string
		curColumn = 0,		// track length of current line
		peekAhead =0;		// track how many characters ahead have been searched

	// loop through length of input string from[]
	while (fromColumn < fromLength)
	{
		// as safeguard, reset peekAhead counter at start of each iteration
		peekAhead = 0;
		// check how long until this word ends and store value in peekAhead
		while (from[fromColumn + peekAhead] != ' '
			&& from[fromColumn + peekAhead] != '\t'
			&& from[fromColumn + peekAhead] != '\n')
		{
			peekAhead++;
		}
		// take action depending on how long the peekAhead buffer is
		if (peekAhead > lineLength)
		{
			// word exceeds more than a lineLength
			// copy what we can, add hyphen and newline, copy one linelength of chars, reset counters, and move on
			for (int i = curColumn; i < lineLength - 1; i++)
			{
				to[toColumn++] = from[fromColumn++];
			}
			to[toColumn++] = '-';
			to[toColumn++] = '\n';
			curColumn = 0;
		}
		else if (curColumn + peekAhead > lineLength)
		{
			// insert the newline character, reset counters, and move on
			to[toColumn++] = '\n';
			curColumn = 0;
		}
		else
		{
			// all is good, copy the character and move on
			to[toColumn++] = from[fromColumn++];
			curColumn++;
			if (curColumn >= lineLength)
			{
				to[toColumn++] = '\n';
				curColumn = 0;
			}
		}
	}
}