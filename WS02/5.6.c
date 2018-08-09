/**
 * Solution to textbook Ex 5.6 - The Amicable Pairs problem.
 * Author:  Luke Hedt
 * Email:   lhedt@student.unimelb.edu.au
 * Date:    04/08/2018
 */

 #include <stdio.h>
 #include <stdlib.h>

// Function Decs
 int
 areAmicable(int n1, int n2);

// MAIN
 int
 main(int argc, char *argv[]) {

     int n1, n2;

     // Scaffolding
     printf("Input 2 numbers to check for Amicable Pairs: ");

     if(scanf("%d %d", &n1, &n2) != 2) {
         printf("Error! Enter 2 numbers!\n");
         exit(EXIT_FAILURE);
     }

     if(areAmicable(n1, n2)) {
         printf("%d and %d are an amicable pair!\n", n1, n2);
     } else {
         printf("%d and %d are NOT an amicable pair!\n", n1, n2);
     }

     return 0;
 }


/**
 * Input Variables:
 *  n1 - int: The first number in the pair to check
 *  n2 - int: The second number in the pair to check
 *  ************************************
 * Output: int - True if the numbers are amicable pairs
 *             - That is, if n1's factors add to n2 and vice versa
 */
int
areAmicable(int n1, int n2) {
    // Find sum of all factors of n1
    int sumFactN1 = 0;
    int i;

    for (i=1; i < n1; i++) {
        if ((n1 % i) == 0) {
            sumFactN1 += i;
        }
    }

    // Find sum of all factors of n2
    int sumFactN2 = 0;
    for (i=1; i < n2; i++) {
        if ((n2 % i) == 0) {
            sumFactN2 += i;
        }
    }

    // returns True if they're the same!
    return ((sumFactN1 == n2) && (sumFactN2 == n1));
}
