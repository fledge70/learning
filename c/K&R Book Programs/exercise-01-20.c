/**
 * This program replaces tabs in the input with the proper
 * number of blanks to space to the next tab stop.  This
 * assumes a fixed set of tab stops, as defined in the
 * constaned below
 */
#include <stdio.h>
#include <string.h>

// external constant definitions
const int tabStop = 8;
const int MAXLINE = 1000;

// function declarations
int mygetline(char s[], int lim);
void detab(char to[], char from[]);

/**
 * take input and 'detab' it, one line at a time
 */
int main()
{	
	// initialize variables
	char line[MAXLINE],					// original input captured
		detabLine[MAXLINE];				// input with spaces instead of tabs
    int len = 0;						// length of original input

    // keep getting lines from input until zero-length string received
	while ( (len = mygetline(line, MAXLINE)) > 0)
	{
        printf("Line length: %d\n", len);
        detab(detabLine, line);
    	printf("Original input:\n%s\n", line);
    	printf("Input detabbed:\n%s\n", detabLine);

    	// clear line contents before they are reused on next pass
    	memset(line, 0, sizeof(line));
    	memset(detabLine, 0, sizeof(detabLine));
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
 * detab: replaces tabs with an appropriate number of "spaces"
 * to line up with the next tab stop (set by constant at top of
 * program).  Note that this uses '*' instead of space to
 * make it easier to confirm the function works.
 */
void detab(char to[], char from[])
{
	int curColumn = 1;  // counter used to track position for tabs
	int i = 0;			// counter used to iterate over from[] char array

	while (from[i] != '\0')
	{
		if (from[i] == '\t')
		{
			for (int j = 0;
				j < ( ( curColumn % tabStop > 0 ) ?
					(curColumn % tabStop) :
					tabStop );
				j++)
			{
				to[curColumn - 1] = '*';
				curColumn++;
			}
		}
		else
		{
			to[curColumn - 1] = from[i];
			curColumn++;
		}
		i++;
	}
}