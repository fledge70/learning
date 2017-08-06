/**
 * This program reads input containing lines of
 * arbitrary length and prints lines with trailing
 * spaces and tabs removed.  Entirely blank lines are
 * disregarded
 */
#include <stdio.h>

int mygetline(char s[], int lim);
int copy(char to[], char from[]);

/**
 * print input line with trailing spaces and tabs removed
 */
int main()
{	
	// set constants
	const int MAXLINE = 1000;

	// initialize variables
	char line[MAXLINE],		// original input captured
		clean[MAXLINE];		// input with trailing whitespace removed
    int len = 0,			// length of original input
    	cleanLen = 0;		// length of cleaned string

    // keep getting lines from input until zero-length string received
	while ( (len = mygetline(line, MAXLINE)) > 0)
	{
        printf("Line length: %d\n", len);
        // work backward through string, replacing any trailing
        // whitespace chars with string terminator '\0'
        for (int i = len - 2; i >= 0; i--)
        {
            if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
            {
                
                line[i] = '\0';
            }
            else
            {
                // ensure the newline character is retained at the end of the string
                line[i+1] = '\n';
                break;
            }
        }

        if (len > 1) {
            // use the copy function to clean extra occurrences of '\0'
            // from the end of the string
            cleanLen = copy(clean, line);

            // to prove the program works, display text with
            // whitespace chars replaced with unambigious chars
            printf("Formatted output:\n%s\n", line);
            printf("Output displayed with unambiguous whitespace:\n");
            for (int i = 0; i < cleanLen; i++)
            {
                if (clean[i] == ' ')  // replace space with '*'
                {
                    printf("*");
                }
                else if (clean[i] == '\t') // replace tab with '\t'
                {
                    printf("\\t");
                }
                else if (clean[i] == '\n') // replace newline with '\n'
                {
                    printf("\\n");
                }
                else if (clean[i] == '\0') // replace null with '\0'
                {
                    printf("\\0");
                }
                else						// otherwise, print char as-is
                {
                    printf("%c", clean[i]);
                }
            }
            printf("\n");
        }
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
 * copy: copy 'from' into 'to', return length of string copied
 */
int copy(char to[], char from[])
{
	int i;
	i = 0;
	// copy chars until string terminator hit
	while ( (to[i] = from[i]) != '\0')
	{
		++i;
	}
	return i;
}