/**
 * This program reads a set of input lines and prints
 * the longest line.
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
	int len,
		max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ( (len = mygetline(line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)		// there was a line
	{
		printf("%s", longest);
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