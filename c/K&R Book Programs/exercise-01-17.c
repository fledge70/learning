/**
 * This program reads input containing lines of
 * arbitrary length and prints only lines that are
 * longer than 80 characters
 */
#include <stdio.h>

int mygetline(char s[], int lim);

/**
 * print longest input line
 */
int main()
{	
	// set constants
	const int MAXLINE = 1000;

	// initialize variables
	int len;
	char line[MAXLINE];

	while ( (len = mygetline(line, MAXLINE)) > 0)
	{
        printf("Line length: %d\n", len);
        if (len > 81)
        {
            printf("Contents: %s\n", line);
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