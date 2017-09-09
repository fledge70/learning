/**
 * This program expands on the provided example "qsort" program
 * modified to store lines in an array.  (The original program
 * used a rudimentary memory allocation function)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 3
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines, char *lineStorage[]);
void writelines(char *lineptr[], int nlines);
void myqsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
  int nlines;
  char *lineStorage[MAXLINES];
  
  if ((nlines = readlines(lineptr, MAXLINES, lineStorage)) >= 0)
  {
    myqsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  }
  else
  {
    printf("error: input too big to sort\n");
    return 1;
  }
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *lineStorage[])
{
  int len, nlines;
  char *line;
  size_t lineBufferSize = MAXLEN;
  
  nlines = 0;
  line = (char *) malloc(lineBufferSize + 1);
  
  while ((len = getline(&line, &lineBufferSize, stdin)) > 1)
  {
    if (nlines >= maxlines)
    {
      return -1;
    }
    else
    {
      line[len-1] = '\0';   // delete newline
      lineStorage[nlines] = (char *) malloc(len +1);
      strcpy(lineStorage[nlines], line);
      lineptr[nlines] = lineStorage[nlines];
      nlines++;
    }
  }
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
  for (int i = 0; i < nlines; i++)
  {
    printf("%s\n", lineptr[i]);
  }
}

/* myqsort: sort v[left]...v[right] into increasing order */
void myqsort(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);
  
  if (left >= right)
  {
    return;
  }
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
  {
    if (strcmp(v[i], v[left]) < 0)
    {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  myqsort(v, left, last - 1);
  myqsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}