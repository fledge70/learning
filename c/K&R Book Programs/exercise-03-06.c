/**
 * This program features a modified itoa function, that converts
 * a given integer into a string representation, and pads
 * the left side with spaces to meet a minimum field width.
 */
#include <stdio.h>
#include <string.h>

// define symbolic constants
#define MAXLINE 1000

//function declaration
void itoa(int n, char s[], int width);

int main()
{
	int startingNumber,
	  width;
	char result[MAXLINE];

	printf("\nEnter the number to convert: ");
  scanf("%d", &startingNumber);
  printf("\nEnter the field width: ");
  scanf("%d", &width);

  itoa(startingNumber, result, width);

  printf("\nThe return string is: %s\n", result);

	return 0;
}

/**
 * itoa: converts an integer n to string s[].  The function
 * pads the returned string with spaces, as needed, to meet
 * the given minimum field width 'width'
 */
void itoa(int n, char s[], int width)
{
	int i, sign;
	if ( (sign = n) < 0)
	{
		n = -n;
	}
	i = 0;
	do
	{
		s[i++] = n % 10 + '0';
	} while ( (n /= 10) > 0);
	if (sign < 0)
	{
		s[i++] = '-';
	}

	while (i < width)
	{
		s[i++] = ' ';
	}

	s[i] = '\0';

	strrev(s);
}