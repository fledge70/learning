/**
 * This program replaces strings of blanks with the
 * minimum number of tabs and blanks to achieve the
 * same spacing.
 */
#include <stdio.h>
#include <string.h>

// external constant definitions
const int TABSTOP = 8;
const int MAXLINE = 1000;

// function declarations
int mygetline(char s[], int lim);
void entab(char to[], char from[]);

/**
 * take input and 'entab' it, one line at a time
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
        entab(modifiedLine, line);
    	printf("\nOriginal input:\n%s", line);
    	printf("\nInput entabbed:\n%s\n", modifiedLine);

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
 * entab: replaces consecutive blanks with the minimum
 * number of tabs and blanks needed to achieve the same
 * spacing.
 */
void entab(char to[], char from[])
{
	int toStep = 0,  	// counter used to track position in to[] char array
		toColumn = 0,	// track position in actual string out in to[] char array
		fromColumn = 0;	// counter used to iterate over from[] char array

	while (from[fromColumn] != '\0')
	{
		if (from[fromColumn] == ' ')
		{
			/**
			 * Summary of code within this 'if' block
			 * 1) walk ahead until it finds a non-space character
			 * 2) count number of chars walked through (increment fromColumn)
			 * 3) calculate how many tabs, and how many spaces are
			 *    needed to align spacing
			 * 4) increment toStep and fromColumn accordingly as it goes
			 */

			/**
			 * walk ahead until finding a non-space character.
			 * printf commands provide diagnostics only to prove
			 * the program works.
			 */
			while (from[fromColumn] == ' ')
			{
				fromColumn++;
			}
			// as long as fromColumn and toColumn are more than a TABSTOP apart,
			// add tabs and increment toColumn as needed
			while (fromColumn / TABSTOP > toColumn / TABSTOP)
			{
				printf("Adding a tab, toStep=%d, toColumn=%d\n",
					toStep, toColumn);
				printf("fromColumn=%d\n", fromColumn);
				to[toStep] = '\t';
				toStep++;
				toColumn = ( (toColumn + TABSTOP) / TABSTOP ) * TABSTOP;
			}
			// now that toColumn should be within a TABSTOP of
			// fromColumn, use as many spaces as needed to align them
			while (toColumn < fromColumn)
			{
				printf("Adding a space, toStep=%d, toColumn=%d\n",
					toStep, toColumn);
				to[toStep] = ' ';
				toStep++;
				toColumn++;
			}
		}
		else
		{
			// if no spaces, simply copy characters and increment counters
			to[toStep] = from[fromColumn];
			toStep++;
			toColumn++;
			fromColumn++;
		}
	}
}