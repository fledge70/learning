/**
 * This program illustrates the use of the htoi function, which
 * coverts a string of hexadecimal digits into its equivalent
 * integer value.
 */
#include <stdio.h>

// function declarations
int mygetline(char s[], int lim);
int htoi(char s[]);

int main()
{
	const int MAXLINE = 32;

	char inputLine[MAXLINE];
	int len = 0;
	int outputInt;
  
  printf("Enter the hexadecimal number to convert: ");
  len = mygetline(inputLine, MAXLINE);
	printf("\nOriginal value entered:\n%s\n", inputLine);
	outputInt = htoi(inputLine);
	printf("Converted to integer:\n%d\n", outputInt);
	
	return 0;
}

/**
 * htoi: coverts a string of hexadecimal digits (including an optional
 * 0x or 0X) into its equivalent integer value. The allowable digits
 * are 0-9, a-f, and A-F.  Returns -1 for any invalid input
 */
int htoi(char s[])
{
	const int TRUE = 1;
	const int FALSE = 0;
	
	int result = 0;
	int valid = TRUE;
  int i = 0;
  int curDigit = 0;

  // check for optional prefix chars and set iterator accordingly
  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X') )
  {
  	i = 2;
  }

  // loop through input string
  while (s[i] != '\0' && s[i] != '\n')
  {
  	if (s[i] >= '0' && s[i] <= '9')
  	{
  		curDigit = s[i] - '0';
  	}
  	else if (s[i] >= 'A' && s[i] <= 'F')
  	{
  		curDigit = 10 + (s[i] - 'A');
  	}
  	else if (s[i] >= 'a' && s[i] <= 'f')
  	{
  		curDigit = 10 + (s[i] - 'a');
  	}
  	else
  	{
  		valid = FALSE;
  		break;
  	}

  	// add curDigit to running total; multiplying existing by
  	// 16 to account for previous columns
  	result = 16 * result + curDigit;
  	// increment loop counter
  	i++;
  }

	if (!valid)
	{
		return -1;
	}
	else
	{
		return result;
	}
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