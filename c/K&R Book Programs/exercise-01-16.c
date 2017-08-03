/**
 * This program reads input containing lines of
 * arbitrary length and prints their length,
 * along with as much as possible of the text.
 */
#include <stdio.h>

int mygetline(char s[], int lim);
void copy(char to[], char from[]);

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
		printf("Contents: %s\n", line);
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

 /**
  * copy: copy 'from' into 'to'; assume to is big enough
  */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
	{
		++i;
	}
}