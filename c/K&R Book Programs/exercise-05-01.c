/**
 * This program illustrates the use of an improved getint function.
 * Per the exercise requirements, getint should properly handle
 * a + or - sign followed by a non-digit.
 */
#include <stdio.h>
#include <ctype.h>

#define MAX 10

int getch(void);
void ungetch(int);
int getint(int *);

int main()
{
  int myInt, numChars;
  printf("Testing the modified getint() function.\n");
  printf("Please enter an integer: ");
  numChars = getint(&myInt);
  printf("%d chars in buffer, integer captured is %d.\n", numChars, myInt);
  return 0;
}

/**
 * getint: get next integer from input into *pn
 */
int getint(int *pn)
{
  int c, sign;
  *pn = 0;
  while (isspace(c = getch()))    /* skip white space */
  {
    ;
  }
  if (!isdigit(c) && c != EOF && c != '+' && c != '-')
  {
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
  {
    c = getch();
    if (!isdigit(c))
    {
      ungetch(sign == 1 ? '+' : '-');
      return 0;
    }
  }
  for (*pn = 0; isdigit(c); c = getch())
  {
    *pn = 10 * *pn + (c - '0');
  }
  *pn *= sign;
  if (c != EOF)
  {
    ungetch(c);
  }
  return c;
}

int bufp = 0;
int buf[MAX];

int getch(void)
{
	return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp < MAX)
		buf[bufp++] = c;
}