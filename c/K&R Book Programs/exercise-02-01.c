/**
 * This program references values stored in a standard header
 * (limits.h) to print ranges for various data types
 */
#include <stdio.h>
#include <limits.h>

int main()
{
  // list ranges for various data types. Stopped after this
  // exercise became repetitive.  Note that the print format
  // used for long and ulong can vary depending on target
  // platform

  printf("Signed Char:\n");
  printf("Minimum Value: %d\n", SCHAR_MIN);
  printf("Maximum Value: %d\n", SCHAR_MAX);
  printf("\n");

  printf("Unsigned Char:\n");
  printf("Maximum Value: %d\n", UCHAR_MAX);
  printf("\n");

  printf("Char:\n");
  printf("Minimum Value: %d\n", CHAR_MIN);
  printf("Maximum Value: %d\n", CHAR_MAX);
  printf("\n");

  printf("Short:\n");
  printf("Minimum Value: %d\n", SHRT_MIN);
  printf("Maximum Value: %d\n", SHRT_MAX);
  printf("\n");

	printf("Integer:\n");
  printf("Minimum Value: %d\n", INT_MIN);
  printf("Maximum Value: %d\n", INT_MAX);
  printf("\n");

	printf("Unsigned Long:\n");
  printf("Maximum Value: %lld\n", ULONG_MAX);
  printf("\n");

	printf("Long Long:\n");
  printf("Minimum Value: %lld\n", LLONG_MIN);
  printf("Maximum Value: %lld\n", LLONG_MAX);
  printf("\n");  

  return 0;
}