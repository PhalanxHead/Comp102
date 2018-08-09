/**
 * A solution to Ex 4.6 - Counting chars and lines
 * Author:  Luke Hedt
 * Email:   lhedt@student.unimelb.edu.au
 * Date:    04/08/2018
 */

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {

    int ch;
    int lineCount = 0;
    int charCount = 0;

    printf("Enter Text: \n");

    while((ch=getchar()) != EOF) {
        // Increment number of Lines if Newline is found
        if (ch == '\n') {
            lineCount++;
        }
        charCount++;
    }

    // Output Result!
    printf("Lines: %6d\nChars: %6d\n", lineCount, charCount);

    return 0;
}
