/* Exercise 4.7: Simple character, word, and line count program.
   In this program, a word is defined as being any sequence of
   alphabetic letters, eg, "one 2 three 4" would contain two words.
   
   Y.M.Jiang   March 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NEWLINE '\n'

int
main(int argc, char *argv[]) {

    int nlines=0, nchars=0, nwords=0;
    int inaword=0;
    int c;

    /* iterate over characters read from the input */
    while ((c=getchar()) != EOF) {

        /* count lines */
        if (c == NEWLINE) {
            nlines += 1;
        }

        /* count words */
        if (isalpha(c)) {
            /* letter is alphabetic... */
            if (!inaword) {
                /* ... and is first in a new word */
                nwords += 1;
            }
            inaword = 1;
        } else {
            /* definitely not in a word */
            inaword = 0;
        }
            
        /* count characters */
        nchars += 1;
    }

    /* generate the required report */
    printf("Lines: %6d\n", nlines);
    printf("Words: %6d\n", nwords);
    printf("Chars: %6d\n", nchars);

    /* that's it */
    return 0;
}
