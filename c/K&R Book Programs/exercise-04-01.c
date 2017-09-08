/**
 * This program features the strrindex function, that 
 * returns the position of the rightmost occurrence of
 * a string in another string.
 */
#include <stdio.h>

// define symbolic constants
#define MAXLINE 1000

//function declaration
int strrindex(char s[], char t[]);

int main()
{
  char baseString[MAXLINE] = {},
    searchString[MAXLINE] = {};
  int found = -1;

  printf("\nEnter the string to search IN:\n");
  fgets(baseString, MAXLINE, stdin);
  printf("\nEnter the string to search FOR:\n");
  fgets(searchString, MAXLINE, stdin);

  // TODO: these two printf's here for diagnostic only
  printf("\nbaseString: %s\n", baseString);
  printf("\nsearchString: %s\n", searchString);

  found = strrindex(baseString, searchString);
  printf("\nThe search string was found at position %d\n", found);
}

/**
 * strrindex: returns the position of the string t[] in
 * string s[]
 */
int strrindex(char s[], char t[])
{
  int i = 0;
  int j = 0;
  int possible = -1;
  int found = -1;
  
  // TODO: fix this. After switching to fgets(), this always
  // returns -1.
  
  // step through string s[] until newline found
  while (s[i] != '\n')
  {
  	// current char matches first char of t[], possible match
  	if (s[i] == t[0])
  	{
  		possible = i;
  		j = 0;
  		// compare chars of string t[] to s[] starting at current
  		// position, until newline encountered in either string
  		while (s[i+j] != '\n' && t[j] != '\n')
  		{
  			// as soon as conflict found, cancel this possibility
  			if (s[i+j] != t[j])
  			{
  				possible = -1;
  			}
  			j++;
  		}
  		// cancel possibility if newline found before full match
  		if (s[i+j] == '\n' && t[j] != '\n')
  		{
  			possible = -1;
  		}
  		// assign possible to found value if match found is the
  		// rightmost match so far
  		if (possible > found)
  		{
  			found = possible;
  		}
  	}
  	i++;
  }
  return found;
}