/**
 * This program features a function any(s1, s2) that returns
 * the first location in string s1 where any character
 * from the string 2 occurs, or -1 if no match is found.
 */
#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
	char input[] = "The quick brown fox jumps over the lazy dog.";
  char searchString[] = "aie";
  int firstMatchFound = 0;

  printf("\nInput string:\n%s\n", input);
  printf("\nLetters to find:\n%s\n", searchString);
  firstMatchFound = any(input, searchString);
  printf("\nMatch found at: %d\n", firstMatchFound);

	return 0;
}

/**
 * any: returns an integer representing the position, within
 * string s1, where any character from string s2 is found.
 */
int any(char s1[], char s2[])
{
	int match = -1;		// default to no match found

	// loop through string of search parameters
	for (int i = 0; s2[i] != '\0'; i++)
	{
		// loop through each character in s1 until a match is found
		for (int j = 0; s1[j] != '\0'; j++)
		{
			// match found
			if (s1[j] == s2[i])
			{
				if (match == -1)
				{
					match = j;
				}
				else if (j < match)
				{
					match = j;
				}
			}
		}
	}

	return match;
}