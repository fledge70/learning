/**
 * This program demonstrates a strend function that uses pointers to
 * find the given t string within the given string s.
 */
#include <stdio.h>

#define MAXLINE 1000

int strend(char *s, char *t);

int main()
{
  char baseString[MAXLINE],
    searchString[MAXLINE];
  int resultCode;
  
  printf("\nEnter string to search in:\n");
  fgets(baseString, MAXLINE, stdin);
  printf("\nEnter string to match at end of first string:\n");
  fgets(searchString, MAXLINE, stdin);
  resultCode = strend(baseString, searchString);
  
  if (resultCode)
  {
    printf("\n%s was found at the end of %s.\n", searchString, baseString);
  }
  else
  {
    printf("\n%s was not found at the end of %s", searchString, baseString);
  }
  
  return 0;
}

/**
 * strend: returns 1 if given string t is found at the end of given string s,
 * and returns 0 if not. Per the exercise requirements, this function
 * uses pointers (instead of arrays)
 */
int strend(char *s, char *t)
{
  // save starting pointer position, of the search string
  char *startPoint = t;
  
  // increment pointers to get to the end of each char array, by walking
  // through them
  while (*++s)
    ;
  while (*++t)
    ;
  
  // walk backward through strings until non-matching characters are found
  while (*s-- == *t--)
    ;
  
  // add 2 back to account for extra positions walked, and compare to startPoint
  if (t + 2 != startPoint)
  {
    // does not match
    return 0;
  }
  else
  {
    // matches!
    return 1;
  }
}