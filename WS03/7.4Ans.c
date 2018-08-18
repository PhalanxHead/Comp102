/* Author:  Luke Hedt
 * Email:   lhedt@student.unimelb.edu.au
 * Date:    18/08/2018
 *
 * Reads in an array, sorts the values, then prints the unique counts.
 */ 

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100
#define MAXWIDTH 80
#define NUMWIDTH 4
#define MAXVAL 1000
#define MINVAL 0

void int_swap(int *A, int *B);
void insertionSort(int A[], int n);
void readVals(int A[], int *A_len);
void printArr(int A[], int A_len);
void countFreqs(int A[], int *A_len);
void countFreqs_Hash(int A[], int* A_len);


/****************************************************************************/

int main (int argc, char* argv[]) {

    /* Read In */
    printf("Enter as many as %d values, ^D to end\n", LENGTH);
    int A_len = 0; 
    int A[LENGTH];

    readVals(A, &A_len);

    /* Run the sort! */
    insertionSort(A, A_len);

    printf("Number\tFreq\n");
    /* Sorting method */
    // countFreqs(A, &A_len);

    /* Hashing Method */
    countFreqs_Hash(A, &A_len);

    return 0;
}

/****************************************************************************/

void int_swap(int *A, int *B) 
/* Swaps 2 integers
 * Input:
 *     int *A - A pointer to an integer
 *     int *B - A pointer to an integer
 *********************
 * Output: None
 */
{
    int tmp = *A;
    *A = *B;
    *B = tmp;
}

/****************************************************************************/

void insertionSort(int A[], int n) 
/* Sorts an array using insertion sort
 *  Input:
 *      int A[] - An array of integers
 *      int n   - The number of elements in A[]
 **********************
 *  Output: None
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

void readVals(int A[], int *A_len) 
/* Reads values into an array. 
 * Inputs:
 *      int A[]  -  The integer array to write to
 *      int* A_len - The pointer to the variable which holds the length of A.
 * Note: We use the pointer so we can modify the A_len variable without
 *       returning a value.
 *********************
 *   Output: None
 */ 
{
    int next;

    /* Read in integers until the array is full. */
    while (scanf("%d", &next) == 1) {
        if (*A_len == LENGTH) {
            break;

        } else {
            A[*A_len] = next;
            *A_len += 1;
        }
    }

    /* Tell the user how successful you are. */
    printf("%d values read into the array.\n", *A_len);
}

/****************************************************************************/

void printArr(int A[], int A_len) 
/* Prints the contents of an array in a nicely formatted manner.
 * Note: Doesn't like numbers with width > NUMWIDTH
 * Inputs:
 *      int A[]  -  The array to print
 *      int A_len - The number of values in A.
 *********************
 * Output: None
 */
{
    int i;
    int width = 0;
    for (i = 0; i < A_len; i++) {
        /* Keep output width to an appropriate minimum */
        if (width >= MAXWIDTH) {
            printf("\n");
            width = 0;
        }
        /* Should be set to be NUMWIDTH in width */
        printf("%4d ", A[i]);
        width += NUMWIDTH;
    }
    printf("\n");
}

/****************************************************************************/

void countFreqs(int A[], int *A_len)
/* Counts the frequency of values in the sorted array A
 * Inputs:
 *      int A[]  -  The array to Count
 *      int *A_len - The pointer to the number of values in A.
 *********************
 * Output: None
 */
{
    /* Exercise for the reader: Make this work with a for loop */
    int i = 1;
    int count = 1;
    while (i < *A_len) {
        
        if (A[i] == A[i-1]) {
            count++;

        } else {
            printf("%5d %5d\n", A[i-1], count);
            count = 1;
        }
        i++;
    }
    printf("%5d %5d\n", A[i-1], count);
}

/****************************************************************************/

void countFreqs_Hash(int A[], int* A_len)
/* Counts the frequency of values in the sorted array A
 * Inputs:
 *      int A[]  -  The array to Count
 *      int *A_len - The pointer to the number of values in A.
 *********************
 * Output: None
 */
{
    int excess = 0;
    int i;
    int countSize = MAXVAL - MINVAL;
    int count[countSize];

    /* Zero the Array */
    for(i=0; i<countSize; i++) {
        count[i] = 0;
    }

    /* Assumes MINVAL = 0, need to make sure to change this if 
        it's not the case */
    for(i=0; i < *A_len; i++) {
        if(A[i] > MAXVAL || A[i] < MINVAL) {
            excess += 1;
        } else {
            count[A[i] - 1] += 1;
        }
    }

    /* Print them out! */
    printf("%d values outside the range of (%d, %d)\n", excess, MINVAL, MAXVAL);
    for(i=0; i<countSize; i++) {
        if (count[i] != 0) {
            printf("%5d %5d\n", i+1, count[i]);
        }
    }
}

/****************************************************************************/