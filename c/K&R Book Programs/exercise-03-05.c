/**
 * This program features the itob function, that converts
 * a given integer into a string representation of a
 * variable number-base system.
 */
#include <stdio.h>
#include <string.h>

// define symbolic constants
#define MAXLINE 1000

//function declaration
void itob(int n, char s[], int b);

int main()
{
	int startingNumber,
	  base;
	char result[MAXLINE];

  base = 8;
  
  printf("\nEnter the number to convert: ");
  scanf("%d", &startingNumber);
  printf("Enter the base to convert to: ");
  scanf("%d", &base);

  itob(startingNumber, result, base);

  printf("\n%d expressed in base-%d is %s\n",
  	startingNumber, base, result);

	return 0;
}

/**
 * itob: converts the given int n into a string representation
 * s[] in a "b"-base number system.  (for exmample, hexadecimal
 * has b=16)
 */
void itob(int n, char s[], int b)
{
  int i, sign;
  
  // if n is negative, make it positive and set sign appropriately
  if ( (sign = n) < 0 )
  {
  	n = -n;
  }

  i = 0;

  // work through digits in reverse order
  do
  {
    if (n % b < 10)
    {
    	s[i++] = n % b + '0';
    }
    else
    {
    	s[i++] = n % b - 10 + 'A';
    }
  } while ( (n /= b) > 0);  // integer division, so '0' indicates it's done
  
  if (sign < 0)
  {
  	s[i++] = '-';
  }

  s[i] = '\0';
  // reverse the string so it's back to original order
  strrev(s);
}