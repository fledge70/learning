/**
 * This program uses a function to convert temperatures
 * from Fahrenheit to Celsius.
 */
#include <stdio.h>

float convertToCelsius(float degreesFahr);

/**
 * test temperature conversion functions
 */
int main()
{	
	// initialize variables
	int fahr = 0,
		lower = 0,
		upper = 300,
		step = 20;

	for (fahr = lower; fahr <= upper; fahr += step)
	{
		printf("\n%6d  %5.1f", fahr, convertToCelsius(fahr));
	}

    return 0;
}

/**
 * Accepts a float representing temperature in degrees
 * Fahrenheit and returns a float for that temp in
 * degrees Celsius
 */
float convertToCelsius(float degreesFahr)
{
	return (5.0 / 9.0) * (degreesFahr - 32.0);
}