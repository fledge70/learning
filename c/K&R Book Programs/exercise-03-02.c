/*
 * This program features the escape function, that coverts
 * escape characters like newline and tab to visible
 * escape sequences like '\n' and '\t'.  Also includes
 * "revEscape" function that coverts the opposite way.
 * Both functions illustrate the use of the 'switch' statement.
 */
#include <stdio.h>

// define contstants
#define MAXLINE 1000

// function declaration
void escape(char s[], char t[]);
void revEscape(char s[], char t[]);

int main()
{
  char line[MAXLINE],
  		escLine[MAXLINE],
  		revLine[MAXLINE];

  // keep reading input from stdin until EOF is detected
  while ( fgets(line, sizeof(line), stdin) != NULL)
  {
    printf("\nOriginal line: %s\n", line);
    escape(escLine, line);
    printf("Whitespace replaced: %s\n", escLine);
    revEscape(revLine, escLine);
    printf("Escape chars replaced: %s\n", revLine);
  }

	return 0;
}

/**
 * escape: copies string t[] into s[], replacing escape characters
 * like newline and tab to visible escape sequences like '\n' and '\t'.
 */
void escape(char s[], char t[])
{
	int toCol = 0,
	    fromCol = 0;
  while (t[fromCol] != '\0')
  {
  	switch (t[fromCol])
  	{
  		// take special action for escape sequences '\n' and '\t',
  		// replacing them with visible characters
  		case '\n':
  			s[toCol++] = '\\';
  			s[toCol++] = 'n';
  			fromCol++;
  			break;
			case '\t':
				s[toCol++] = '\\';
  			s[toCol++] = 't';
  			fromCol++;
				break;
			// not interested in all other characters, so simply
			// copy them over to the output string s[]
			default:
				s[toCol++] = t[fromCol++];
				break;
  	}
  }
	s[toCol] = '\0';
	return;
}

/**
 * revEscape: copies string t[] into s[], replacing visible
 * representations of newline and tab with their escape
 * sequences '\n' and '\t'
 */
void revEscape(char s[], char t[])
{
	int toCol = 0,
	    fromCol = 0;
  while (t[fromCol] != '\0')
  {
  	switch (t[fromCol])
  	{
  		// if a backslash '\\' is found, peek ahead to the next
  		// character to determine action.
  		case '\\':
  		  switch (t[fromCol+1])
  		  {
  		  	case 'n':
  		  	  s[toCol++] = '\n';
  		  	  fromCol += 2;
  		  	  break;
  		  	case 't':
  		  	  s[toCol++] = '\t';
  		  	  fromCol += 2;
  		  	  break;
  		  	default:
  		  	  s[toCol++] = t[fromCol++];
  		  		break;
  		  }
  			break;
			// for all non-'\\' characters, simply copy it to s[]
			default:
				s[toCol++] = t[fromCol++];
				break;
  	}
  }
  s[toCol] = '\0';
	return;
}