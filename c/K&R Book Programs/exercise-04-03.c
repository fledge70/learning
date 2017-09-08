/**
 * This program features a reverse Polish calculator,
 * including several enhancements to the basic design
 * to support additional features.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100       // max size of operand or operator
#define NUMBER '0'      // signal that a number was found
#define NEG_NUMBER '1'  // signal that a negative number was found
#define MAXVAL 100      // maximum depth of val stack
#define BUFSIZE 100     // buffer size for ungetch

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];

char buf[BUFSIZE];
int bufp = 0;

/**
 * reverse Polish calculator
 */
int main()
{
  int type;
  double op2;
  char s[MAXOP];
   
  while ( (type = getop(s)) != EOF )
    {
      switch (type)
      {
        case NUMBER:
          push(atof(s));
          break;
        case NEG_NUMBER:
          push(atof(s) * - 1);
          break;
        case '+':
          push(pop() + pop());
          break;
        case '*':
          push(pop() * pop());
          break;
        case '-':
          op2 = pop();
          push(pop() - op2);
          break;
        case '/':
          op2 = pop();
          if (op2 != 0.0)
          {
            push(pop() / op2);
          }
          else
          {
            printf("error: zero divisor\n");
          }
          break;
        case '%':
          op2 = pop();
          if (op2 != 0.0)
          {
            push(fmod(pop(), op2));
          }
          break;
        case '\n':
          printf("\t%.8g\n", pop());
          break;
        default:
          printf("error: unknown command %s\n", s);
          break;
      }
    }   
  return 0;
}
 
/**
 * push: push f onto value stack
 */
void push(double f)
{
  if (sp < MAXVAL)
  {
    val[sp++] = f;
  }
  else
  {
    printf("error: stack full, can't push %g\n", f);
  }
}

/**
 * pop: pop and return top value from stack
 */
double pop(void)
{
  if (sp > 0)
  {
    return val[--sp];
  }
  else
  {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/**
 * getop: get next operator or numeric operand
 */
int getop(char s[])
{
  int i, c;
  char lookAhead;
  
  while ((s[0] = c = getch()) == ' ' || c =='\t')
  {
    // do nothing in here, skipping whitespace
    ;
  }
  s[1] = '\0';
  
  i = 0;
  
  // provision to handle negative numbers, search for negative sign
  if (c == '-')
  {
    lookAhead = getch();
    if (lookAhead == '\n' || lookAhead == ' ' || lookAhead == '\t')
    {
      // subtraction operator detected
      ungetch(lookAhead);
      return c;
    }
    else
    {
      ungetch(c = lookAhead);
    }
  }
  else if (!isdigit(c) && c != '.')
  {
    return c;     // not a number
  }
  
  if (isdigit(c)) // collect integer part
  {
    while (isdigit(s[++i] = c = getch()))
    {
      ;
    }
  }
  if (c == '.')   // collect the fraction part
  {
    while (isdigit(s[++i] = c = getch()))
    {
      ;
    }
  }
  s[i] = '\0';
  if (c != EOF)
  {
    ungetch(c);
  }
  return NUMBER;
}

/**
 * getch: get a (possibly pushed back) character
 */
int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

/**
 * ungetch: push character back on input
 */
void ungetch(int c)
{
  if (bufp >= BUFSIZE)
  {
    printf("ungetch: too many characters\n");
  }
  else
  {
    buf[bufp++] = c;
  }
}