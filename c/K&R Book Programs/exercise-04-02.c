/**
 * This program features the atof function, which converts
 * a string to a double. This includes additional capability
 * to correctly convert strings containing scientific notation
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// define symbolic constants
#define MAXLINE 1000

//function declaration
double atof(char s[]);

/**
 * Provides a rudimentary calculator to demonstrate the
 * atof function.
 */
int main()
{
	double sum = 0;
	char line[MAXLINE];
  bool validInput = true;

  printf("\nEnter numbers to add.  Enter blank line to quit.\n");

	while (validInput)
	{
		fgets(line, MAXLINE, stdin);
    if (line[0] == '\n' && line[1] == '\0')
    {
    	validInput = false;
    }
		else
		{
		// force a funny looking print format for diagnostics:
		// this exercise illustrates the relevance of significant
		// digits available for the floating point number formats
		printf("\t%.12f\n", sum += atof(line));
	    }
	}
	return 0;
}

/**
 * atof: converts the provided string s[] into a double return value
 */
double atof(char s[])
{
	double val, power;
	int i, sign, snSign, snValue;
	long snMult;

	// skip whitespace
	for (i = 0; isspace(s[i]); i++)
	{
		;
	}
	// account for - negative sign
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
	{
		i++;
	}
	// loop through input string incrementally
	for (val = 0.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
	}
	// account for decimal point. Program effectively ignores
	// any other characters or anything that follows them
	if (s[i] == '.')
	{
		i++;
	}
	// account for any digits found after decimal point
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	// account for scientific notation
	if (s[i] == 'e' || s[i] == 'E')
	{
		i++;
		snSign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
		{
			i++;
		}
		// capture raw "power" value of scientific notation
		for (snValue = 0; isdigit(s[i]); i++)
		{
			snValue = 10 * snValue + (s[i] - '0');
		}
		// convert to decimal by computing 10^snValue
		snMult = 1;
		for (int p = 1; p <= snValue; p++)
		{
			snMult *= 10;
		}
		if (snSign > 0)
		{
			return sign * val / power * snMult;
		}
		else
		{
			return sign * val / power / snMult;
		}
	}
	return sign * val / power;
}