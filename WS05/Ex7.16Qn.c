/*
 * Figures 7.13 and 7.14 from 'Programming, Problem Solving
 * & Abstraction in C' by Alistair Moffat, 2013, pg 121,122.
 * 
 * This code has been made available to students on
 * the LMS, on the basis of attribution to Alistair.
 * 
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Definitions */
#define MAXCHARS 10     /* Max Chars per word */
#define MAXWORDS 1000   /* Max distinct words */

typedef char word_t[MAXCHARS + 1];

/* Function Prototypes */
int getword(char W[], int limit);


int
main(int argc, char* argv[]) {
    word_t one_word, all_words[MAXWORDS];
    int numdistinct = 0, totwords = 0, i, found;

    while (getword(one_word, MAXCHARS) != EOF) {
        totwords += 1;
        /* Linear Search in array of previous words */
        found = 0;
        for (i = 0; i < numdistinct && !found; i++) {
            found = (strcmp(one_word, all_words[i]) == 0);
        }

        if (!found && numdistinct < MAXWORDS) {
            strncpy(all_words[numdistinct], one_word, MAXCHARS);
            numdistinct++;
        }
        /* NOTE: Program silently discards words after MAXWORDS distinct ones
           have been found */
    }
    printf("%d words read\n", totwords);
    for (i = 0; i < numdistinct; i++) {
        printf("word #%d is \"%s\"\n", i, all_words[i]);
    }

    return 0;
}


int
getword(char W[], int limit)
/*
 * Extract a single word out of the standard input STDIN, of not more than
 * `limit` characters. Argunebt array W must be `limit+1` chars or bigger.
 */
{
    int c, len = 0;
    /* First, skip over non-alphabetics */
    while ((c = getchar()) != EOF && !isalpha(c)) {
        /* Do nothing more */
    }
    if (c == EOF) {
        return EOF;
    }

    /* Okay, first chars of the next word have been found */
    /* Note this assignment will assign W[len] = c, then increment len */
    W[len++] = c;
    while (len < limit && (c = getchar()) != EOF && isalpha(c)) {
        /* Store another character */
        W[len++] = c;
    }

    /* Now close off the string */
    W[len] = '\0';
    return 0;
}