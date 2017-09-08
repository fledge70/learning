/**
 * This program features a #define macro called swap,
 * that swaps two values x and y of a given type t
 */
#include <stdio.h>

#define swap(t, x, y) \
  do                  \
  {                   \
    t tempSwap;       \
    tempSwap = x;     \
    x = y;            \
    y = tempSwap;     \
  } while (0)

int main()
{
  // perform simple tests of the swap macro
  int x, y;
  x = 5;
  y = 10;
  printf("Integer values before swap: x:%d y:%d\n", x, y);
  swap(int, x, y);
  printf("Integer values after swap: x:%d y:%d\n", x, y);
  
  double d, e;
  d = 21.8;
  e = 35.3;
  printf("Double values before swap: d:%f e:%f\n", d, e);
  swap(double, d, e);
  printf("Double values after swap: d:%f e:%f\n", d, e);
  
  char c, f;
  c = 'c';
  f = 'F';
  printf("Char values before swap: c:%c f:%c\n", c, f);
  swap(char, c, f);
  printf("Char values after swap: c:%c f:%c\n", c, f);
  
  return 0;
}    
