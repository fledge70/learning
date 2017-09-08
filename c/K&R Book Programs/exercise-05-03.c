/**
 * This program demonstrates a mystrcat function that uses pointers to
 * concatenate two strings together.
 */
#include <stdio.h>
#include <string.h>

#define MAXLINE 10

int mystrcat(char *s, char *t);

int main()
{
  char baseString[MAXLINE],
    addString[MAXLINE];
  int resultCode;
  
  printf("\nEnter starting string:\n");
  fgets(baseString, MAXLINE, stdin);
  printf("\nEnter string to add to end:\n");
  fgets(addString, MAXLINE, stdin);
  resultCode = mystrcat(baseString, addString);
  if (!resultCode)
  {
    printf("\nThe result is %s\n", baseString);
  }
  else
  {
    printf("\nThe combined strings are greater than %d. Unable to combine.\n",
      MAXLINE);
  }
  return 0;
}

/**
 * mystrcat: copies string t to the end of s. Per the exercise requirements,
 * this function uses pointers (instead of arrays)
 */
 int mystrcat(char *s, char *t)
 {
   // check if combined string will overrun the MAXLINE setting
   // if it will, return error code
   if (strlen(s) + strlen(t) > MAXLINE)
   {
     return -1;
   }
   // get to end of s, determined by newline '\n' character (ASCII code 0)
   while (*++s != '\n')
     ;
   while (*s++ = *t++)
     ;
   *s = '\0';
   return 0;
 }