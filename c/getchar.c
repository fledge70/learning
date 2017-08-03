#include <stdio.h>

/* count characters in input; 3rd version */
int main () {
    long numberBlanks = 0,
        numberTabs = 0;
    int c = 0;
    
    while ( (c = getchar()) != EOF) {
        if (c == '\t')
            numberTabs++;
        else if (c == ' ')
            numberBlanks++;
    }
        
    printf("Tabs: %d\nBlanks: %d\n",
        numberTabs, numberBlanks);

    return 0;
}