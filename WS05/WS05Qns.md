# Workshop 05 Questions

Helpful Resource for working with time complexity from code: 
https://codility.com/media/train/1-TimeComplexity.pdf

Solutions:   github.com/phalanxhead/comp102

## Exercise 7.12 (Palindromes)

Write a function `int is_palindrome(char*)` that returns True if its argument string is a palindrome, that is, it reads exactly the same forwards as it does backwards. It should return False if the string is not a palindrome.

For example "rats live on no evil star" is a palindrome according to this definition, while "A man, a plan, a canal, Panama!" is not. (Note, the second one is if you allow for whitespace, case and punctuation to be ignored. We are not going to ignore them.)

## Exercise 7.14 (atoi)

Write the function `int atoi(char*)` that converts a character string into an integer value.

## Exercise 7.15 (Anagrams) 

Write a function `int is_anagram(char*, char*)` that returns True if its two arguments are an anagram pair, and false if they're not. An anagram pair must have exactly the same set of letters, with the same frequency for each letter, but a different order.
For Example "lustre", "result", "ulster" and "rustle" are all anagrams with respect to each other.

More fun can be had if you include spaces in the set. Try the page at
 www.wordsmith.org/anagram/ 
And you'll find that "Programming is Fun" can be transformed into both "prof margin musing" and "manuring from pigs"

## Exercise 7.16 (Frequency counting for words)  

Modify the following program so that the frequency of each distinct word is listed too. The program is available in Ex7.16Qn.c for easier editing.

```C
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
```

