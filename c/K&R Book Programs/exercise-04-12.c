/**
 * This program features a version of itoa, which converts
 * an integer to a string, that uses recursion
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define   MAXLINE   1000

void ritoa(int n, char s[]);

/**
 * itoa with recursion
 */
int main()
{
  int num;
  char numAsString[MAXLINE];
  
  printf("\nEnter the number to convert: ");
  scanf ("%d",&num);
  ritoa(num, numAsString);
  printf("\n%d represented in string form is %s\n", num, numAsString);
  ritoa(12345, numAsString);
  printf("\n12345 represented in string form is %s\n", numAsString);
  
  return 0;
}

void ritoa(int n, char s[])
{
  static int counter;
  static bool neg;
  
  if (n < 0)
  {
    s[counter++] = '-';
    neg = true;
  }
  else
  {
    neg = false;
  }
  
  if (n / 10)
  {
    ritoa(n / 10, s);
  }
  else
  {
    if (neg)
    {
      counter = 1;
    }
    else
    {
      counter = 0;
    }
  }
  s[counter++] = abs(n) % 10 + '0';
  s[counter] = '\0';
}