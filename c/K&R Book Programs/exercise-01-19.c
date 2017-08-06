/**
 * This program illustrates the use of a function that
 * reverses the character string passed to it.
 */
#include <stdio.h>

int mygetline(char s[], int lim);
void reverse(char to[], char from[], int length);

/**
 * take input and reverse those strings, one line at a time
 */
int main()
{	
	// set constants
	const int MAXLINE = 1000;

	// initialize variables
	char line[MAXLINE],					// original input captured
		reversedLine[MAXLINE];			// reversed input string
    int len = 0;						// length of original input

    // keep getting lines from input until zero-length string received
	while ( (len = mygetline(line, MAXLINE)) > 0)
	{
        printf("Line length: %d\n", len);
        reverse(reversedLine, line, len);
    	printf("Original input:\n%s", line);
    	printf("Input reversed:\n%s\n", reversedLine);
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
 * reverse: reverses the string given in 'from[]' into the
 * char array 'to[]'.  The caller must provide length
 * of the 'from[]' char array so that the function knows
 * which element to start on.
 */
void reverse(char to[], char from[], int length)
{
	for (int i = length - 1; i >= 0; i--)
	{
		to[length - i - 1] = from[i];
	}
}