/**
 * This program illustrates the use of the getfloat function.
 * Per the exercise requirements, getfloat should be the
 * floating-point analog of getint, a function introduced in
 * previous exercises
 */
#include <stdio.h>
#include <ctype.h>

#define MAX 10

int getch(void);
void ungetch(int);
int getfloat(float *);

int main()
{
  int numChars;
  float myFloat;
  printf("Testing the modified getfloat() function.\n");
  printf("Please enter an integer: ");
  numChars = getfloat(&myFloat);
  printf("%d chars in buffer, integer captured is %f.\n", numChars, myFloat);
  return 0;
}

/**
 * getfloat: get next integer from input into *pn
 */
int getfloat(float *pn)
{
  int c;
  float decMult;
  float sign;
  *pn = 0.0;
  while (isspace(c = getch()))    /* skip white space */
  {
    ;
  }
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
  {
    return 0;
  }
  sign = (c == '-') ? -1.0 : 1.0;
  if (c == '+' || c == '-')
  {
    c = getch();
    if (!isdigit(c) && c != '.')
    {
      ungetch(sign == 1.0 ? '+' : '-');
      return 0;
    }
  }
  for (*pn = 0.0; isdigit(c); c = getch())
  {
    *pn = 10.0 * *pn + (float)(c - '0');
  }
  // compute fractional component
  if (c == '.')
  {
    c = getch();
    decMult = 0.1;
    for (; isdigit(c); c = getch())
    {
      *pn += decMult * (float)(c - '0');
      decMult *= 0.1;
    }
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