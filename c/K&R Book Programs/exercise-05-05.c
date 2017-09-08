/**
 * This program demonstrates customized stringCopy and stringCat functions
 * that use pointers to copy/append at most n number of characters
 * to the provided input string
 */
#include <stdio.h>

#define MAXLINE 1000

void stringCopy(char *s, char *t, int n);
void stringCat(char *s, char *t, int n);

int main()
{
  char baseString[MAXLINE],
    copyString[MAXLINE],
    catString[MAXLINE];
  int resultCode,
    numCopy,
    numCat;
  
  printf("\nEnter starting string:\n");
  fgets(baseString, MAXLINE, stdin);
  
  printf("\nEnter string to copy over starting string:\n");
  fgets(copyString, MAXLINE, stdin);
  printf("\nEnter how many characters to copy:\n");
  scanf("%d", &numCopy);
  // get and discard the enter following the captured integer
  getchar();
  
  printf("\nEnter string to add to end of starting string:\n");
  fgets(catString, MAXLINE, stdin);
  printf("\nEnter how many characters to add:\n");
  scanf("%d", &numCat);
  // get and discard the enter following the captured integer
  getchar();
  
  stringCopy(baseString, copyString, numCopy);
  stringCat(baseString, catString, numCat);
  printf("\nFinal result is:\n%s\n", baseString);
  
  return 0;
}

/**
 * stringCopy: copies characters in string t over the beginning of given
 * string s, up to a maximum of n characters
 */
void stringCopy(char *s, char *t, int n)
{
  int counter = 0;
  while (counter++ < n)
  {
    if (!*s || !*t)
    {
      break;
    }
    // account for unwanted newline character that's captured by fgets
    if (*t == '\n')
    {
      break;
    }
    *s++ = *t++;
  }
}

/**
 * stringCat: appends characters in string t to the end of
 * string s, up to a maximum of n characters
 */
void stringCat(char *s, char *t, int n)
{
  int startLength = 0,
    counter = 0;
  // walk to the end of base string s, in this case marked by newline
  while (*++s != '\n')
  {
    startLength++;
  }
  
  while (counter++ < n && startLength + counter < MAXLINE && (*s++ = *t++) )
    ;
}