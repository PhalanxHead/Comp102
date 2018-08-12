/* Author:  Luke Hedt
 * Email:   lhedt@student.unimelb.edu.au
 * Date:    12/08/2018
 *
 * Reads in an array and sorts them.
 */ 

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100

void int_swap(int *A, int *B);
void insertionSort(int A[], int n);

/****************************************************************************/

int main (int argc, char* argv[]) {

    // Readin
    printf("Enter as many as %d values, ^D to end\n", LENGTH);
    int n = 0, excess = 0, next, i;
    int A[LENGTH];

    while (scanf("%d", &next) == 1) {
        if (n == LENGTH) {
            excess += 1;
        } else {
            A[n] = next;
            n++;
        }
    }

    printf("%d values read into the array.\n", n);
    // Print out before sorting
    printf("Before: ");
    for (i=0; i<n; i++) {
        printf("%4d ", A[i]);
    }
    printf("\n");

    // Run the sort!
    insertionSort(A, n);

    // Print out after sorting
    printf("After:  ");
    for (i=0; i<n; i++) {
        printf("%4d ", A[i]);
    }
    printf("\n");
    return 0;
}

/****************************************************************************/

void int_swap(int *A, int *B) 
/* Swaps 2 integers
    Input:
        int *A - A pointer to an integer
        int *B - A pointer to an integer
*********************
    Output: None
*/
{
    int tmp = *A;
    *A = *B;
    *B = tmp;
}

/****************************************************************************/

void insertionSort(int A[], int n) 
/* Sorts an array using insertion sort
    Input:
        int A[] - An array of integers
        int n   - The number of elements in A[]
**********************
    Output: None
*/
{
    int i,j;
    /* Assume that A[0] to A[n-1] have valid values */
    for (i=1; i<n; i++) {
        /* Swap A[i] left into correct position */
        for (j=i-1; j>=0 && A[j+1]<A[j]; j--) {
            /* Not there yet */
            int_swap(&A[j], &A[j+1]);
        }
    }
    /* And that's all there is to it! */
}

/****************************************************************************/