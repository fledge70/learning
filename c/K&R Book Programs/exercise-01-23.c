/**
 * This program removes all comments from a C program.
 */
#include <stdio.h>
#include <string.h>

// external constant definitions
const int MAXLINE = 1000,
	OUT = 0,
	SINGLE_LINE_COM = 1,
	MULTI_LINE_COM = 2,
	QUOTE = 3;

// function declarations
int myGetInput(char s[], int lim);
void removeComments(char to[], char from[], int fromLength);

/**
 * take input and run it against the removeComments function,
 * one line at a time
 */
int main()
{	
	// initialize variables
	char line[MAXLINE],					// original input captured
		modifiedLine[MAXLINE];			// input with spaces instead of tabs
    int len = 0;						// length of original input

    // keep getting lines from input until zero-length string received
	while ( (len = myGetInput(line, MAXLINE)) > 0)
	{
        printf("\nLine length: %d\n", len);
        removeComments(modifiedLine, line, len);
    	printf("\nOriginal input:\n%s", line);
    	printf("\nComments removed:\n%s\n", modifiedLine);

    	// clear line contents before they are reused on next pass
    	memset(line, 0, sizeof(line));
    	memset(modifiedLine, 0, sizeof(modifiedLine));
    }
	return 0;
}

/**
 * myGetInput: read input string into s, return length
 */
int myGetInput(char s[], int lim)
{
	int c, i;

	// read in chars until max (lim) or EOF is hit
	for (i = 0;
		i < lim - 1 && (c = getchar()) != EOF;
		++i)
	{
		s[i] = c;
	}
	
    /* no longer necessary since input does not stop at newline char
	if (c == '\n')
	{
		s[i] = c;
		++i;
	} */

	s[i] = '\0';
	return i;
}

/**
 * removeComments: removes comments from a C program
 */
void removeComments(char to[], char from[], int fromLength)
{
	/**
	 * Summary of what happens in this function:
	 * 1) the parser crawls through from[], peeking ahead to 
	 *    determine the start of comments
	 * 2) if the parser is not in a comment (state = OUT), then
	 *    it copies the current char to to[] char array
	 */
	
	// state tracks whether the parser is currently in a comment or not
	int state = OUT,
		fromCol = 0,
		toCol = 0;

	while (fromCol < fromLength)
	{
		if (state == OUT)
		{
			// parser is outside any comments (default initial state)
			// add conditions to switch state to either comment type
			// or quotes
			if (from[fromCol] == '"')
			{
				state = QUOTE;
				to[toCol++] = from[fromCol++];
			}
			else if (from[fromCol] == '/' && from[fromCol+1] == '/')
			{
				state = SINGLE_LINE_COM;
				fromCol += 2;
			}
			else if (from[fromCol] == '/' && from[fromCol+1] == '*')
			{
				state = MULTI_LINE_COM;
				fromCol += 2;
			}
			else
			{
				to[toCol++] = from[fromCol++];
			}
		}
		else if (state == SINGLE_LINE_COM)
		{
			// parser is inside a single line comment
			// watch for '\n'
			if (from[fromCol] == '\n')
			{
				state = OUT;
				to[toCol++] = from[fromCol++];
			}
			else
			{
				fromCol++;
			}
		}
		else if (state == MULTI_LINE_COM)
		{
			// parser is inside a multi-line comment
			// watch for "*/" to end comment
			if (from[fromCol] == '*' && from[fromCol+1] == '/')
			{
				state = OUT;
				fromCol += 2;
			}
			else
			{
				fromCol++;
			}
		}
		else if (state == QUOTE)
		{
			// parser is inside quote, so comment chars are ignored
			if (from[fromCol] == '"')
			{
				state = OUT;
				to[toCol++] = from[fromCol++];
			}
			else
			{
				to[toCol++] = from[fromCol++];
			}
		}
	}
}