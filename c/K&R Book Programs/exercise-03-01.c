/*
 * This program performs a binary search, and is required
 * to use only one conditional test inside the function's loop -
 * modification to the original example that used two tests.
 */
#include <stdio.h>

// function declaration
int binsearch(int x, int v[], int n);

int main()
{
	const int valueToFind = 499990;
	const int dataSize = 500000;
	int elementFound = -1;
	
	// initialize test data and populate it with ascending values
	int dataToSearch[dataSize];
	for (int i = 0; i < dataSize; i++)
	{
		dataToSearch[i] = i;
	}

  elementFound = binsearch(valueToFind, dataToSearch, dataSize);
  
  if (elementFound > -1)
  {
  	printf("\nThe value %d was found at element %d of the data set.\n",
  			valueToFind, elementFound);
  }
  else
  {
  	printf("\nThe value %d was not found in the data set.\n",
  			valueToFind);
  }


	return 0;
}

int binsearch(int x, int v[], int n)
{
  int low, high, mid;
  int possible;

  low = 0;
  high = n - 1;

  while (low <= high)
  {
  	mid = (low + high) / 2;
  	if (x < v[mid])
  	{
  		high = mid - 1;
  	}
  	else
  	{
  		possible = mid;
  		low = mid + 1;
  	}
  }

  if (x == v[possible])		// match found
  {
  	return possible;
  }
  // no match found
	return -1;
}