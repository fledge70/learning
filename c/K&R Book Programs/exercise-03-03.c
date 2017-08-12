/*
 * This program features the expand function, that expands
 * shorthand notations like "a-z" in the first input string
 * into the equivalent complete list "abc...xyz" in the
 * second parameter
 */
#include <stdio.h>
#include <ctype.h>

// define symbolic constants
#define MAXLINE 1000

// function declaration
void expand(char s1[], char s2[]);

int main()
{
	char line[MAXLINE],
  		expandLine[MAXLINE];
	// keep reading input from stdin until EOF is detected
  while ( fgets(line, sizeof(line), stdin) != NULL)
  {
    expand(line, expandLine);
    printf("Expanded: %s\n", expandLine);
  }

	return 0;
}

/**
 * expand: takes the input string s1[] and returns s2[] with
 * shorthand like "a-z" or "0-9" expanded out to "abc...xyz"
 * or "012...789"
 */
void expand(char s1[], char s2[])
{
  int toCol = 0,
	    fromCol = 0;
	char seriesStart,
			seriesEnd;

  while (s1[fromCol] != '\0')
  {
  	if (s1[fromCol] == '-')
  	{
  		if (fromCol == 0)
  		{
  			// handle leading dash
  			seriesStart = '\n';
  			seriesEnd = s1[fromCol+1];
  		}
  		else
  		{
  		  // this also handles the trailing dash appropriately, since
  		  // the input format infers a newline at the end of every string
  			seriesStart = s1[fromCol-1];
  			seriesEnd = s1[fromCol+1];
  			
  		}
		for (int i = seriesStart; i <= seriesEnd; i++)
			{
				if ( isprint(i) )
				{
					s2[toCol++] = i;
				}
			}
  	}
  	fromCol++;
  }
  s2[toCol] = '\0';
	return;
}