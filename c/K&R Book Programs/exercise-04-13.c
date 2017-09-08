/**
 * This program features a version of reverse, which reverses
 * the contents of a string in place, that uses recursion
 */
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[]);
void swap(char s[], int st, int len);

/**
 * illustrates the use of the reverse function by requesting
 * 
 */
int main()
{
  char myString[MAXLINE];
  
  printf("\nEnter the string to reverse: ");
  fgets(myString, MAXLINE, stdin);
  
  printf("\nYou entered:\n%s", myString);
  reverse(myString);
  printf("\nString reversed:\n%s", myString);
  reverse(myString);
  printf("\nReversed back:\n%s", myString);
  
  return 0;
}

/**
 * reverse: reverses the given string s[] in place. This uses
 * a helper function swap, primarily so that the calling function
 * (in this case main) is not expected to supply a starting index
 * or string length
 */
void reverse(char s[])
{
  int length;
  int start;
  // determine length, start at beginning of string
  start = 0;
  for (length = 0; s[length] != '\0'; length++)
    ;
  // backtrack from the '\0' to the index of the last visible char
  length -= 2;
  swap(s, start, length);
}

/**
 * swap: used by the reverse function to do the actual character
 * swap. Per the exercise requirements, this employs recursion.
 */
void swap(char s[], int st, int end)
{
  // return immediately if start and end elements are already the same
  // or invalid
  if (end - st < 1)
  {
    return;
  }
 
  char temp;
 
  // swap the start and end characters
  temp = s[st];
  s[st] = s[end];
  s[end] = temp;
  
  // recurse on the smaller inner string
  swap(s, st + 1, end - 1);
}