/* ***
 * Solution for Ex 4.5 - A simple grapher
 * Author:  Luke Hedt
 * Email:   lhedt@student.unimelb.edu.au
 * Date:    04/08/2018
 *
 * This doesn't terminate after printing, not sure how to make it do so.
 */

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {

    int i;
    int next;

    printf("Enter numbers: ");
    // Run scanf until a number isn't found
    while(scanf("%d", &next) == 1) {

        // Print out the number, then that many '*'s.
        printf("%2d |", next);
        for (i = 0; i < next; i++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
