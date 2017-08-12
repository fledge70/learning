/**
 * This program provides an alternate version of squeeze(s1, s2)
 * that deletes each character in s1 that matches any character
 * in s2.
 */
#include <stdio.h>

// function declarations
void mySqueeze(char s1[], char s2[]);

int main()
{
  char input[] = "The quick brown fox jumps over the lazy dog.";
  char searchString[] = "aeiou";

  printf("\nInput string:\n%s\n", input);
  printf("\nLetters to remove:\n%s\n", searchString);
  mySqueeze(input, searchString);
  printf("\nAltered string:\n%s\n", input);
	return 0;
}

void mySqueeze(char s1[], char s2[])
{
  int i = 0;
  int j = 0;
  int parserColumn = 0;  // parserColumn tracks position within the altered string

  while (s2[i] != '\0')
  {
  	j = 0;
  	parserColumn = 0;
  	while (s1[j] != '\0')
  	{
  		if (s1[j] == s2[i])
  		{
  			// found matching char at s1[j]
  			s1[parserColumn] = s1[j+1];
  		}
  		else
  		{
  			s1[parserColumn++] = s1[j];
  		}
  		j++;
  	}
  	s1[parserColumn] = '\0';
  	i++;
  }
}