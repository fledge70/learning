/*
 * This program features the 'lower' function, that converts
 * upper case letters to lower case, using a conditional
 * expression (instead of if-else)
 */
#include <stdio.h>

// define contstants
#define MAXLINE 1000

// declare functions
void lower(char s[]);

int main()
{
  char line[MAXLINE];

  // keep reading input from stdin until EOF is detected
  while ( fgets(line, sizeof(line), stdin) != NULL)
  {
    printf("\nOriginal line: %s\n", line);
    lower(line);
    printf("All upper case now lowered: %s\n", line);
  }
	return 0;
}

void lower(char s[])
{
	for (int i = 0; s[i] != '\0'; i++)
	{
    // TODO: complete this assignment using the conditional expression
		s[i] = (s[i] >= 65 && s[i] <= 90) ? s[i]+32 : s[i];
	}
	return;
}