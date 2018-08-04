/* ***
 * A Solution to Ex 2.8 - Farenheit to Celcius Conversion
 * Author:  Luke Hedt
 * Email:   lhedt@student.unimelb.edu.au
 * Date:    04/08/2018
 */

#include <stdio.h>
#include <stdlib.h>

#define ERROR_MSG "Please enter a number!"


int
main(int argc, char* argv[]) {

    double degFar, degCel;

    // Print some text to let the user know what to do
    printf("Please enter a temperature in Farenheit: ");

    // Error checking - Do we have the right number of inputs?
    if(scanf("%lf", &degFar) != 1) {
        printf("Error! %s\n", ERROR_MSG);
        /* 'exit()' closes the program, EXIT_FAILURE indicates there was an error.
         */
        exit(EXIT_FAILURE);
    }

    /* Do the Maths
     * Note: We use the 5.0 marker to keep the division expression as a float.
     * Note: We have the multiplications before the divides as we want to
     * divide large numbers by small numbers to preserve precision where possible.
     */
    degCel = 5.0 * (degFar - 32) / 9;

    // Give the results back to the user!
    printf("%.2f degrees Farenheit converts to %.2f degrees Celcius\n",
            degFar, degCel);

    return 0;
}
