/* Author:  Luke Hedt
 * Email:   lhedt@student.unimelb.edu.au
 * Date:    23/08/2018
 *
 * Reads in an array, sorts it using selection sort,
 * Then prints the array back out.
 */ 

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100
#define NUMWIDTH 4

void int_swap(int *A, int *B);
void selectionSort(int A[], int n);
void selectionSort_rec(int A[], int n);
void readVals(int A[], int *A_len);
void printArr(int A[], int A_len);


/****************************************************************************/

int main (int argc, char* argv[]) {

    /* Read In */
    printf("Enter as many as %d values, ^D to end\n", LENGTH);
    int A_len = 0; 
    int A[LENGTH];

    readVals(A, &A_len);

    printf("Before Sorting: \n");
    printArr(A, A_len);

    /* Run the sort! */
    /* Iterative Case */
    selectionSort(A, A_len);
    /* Recursive Case */
    selectionSort_rec(A, A_len);

    /* Print out the sorted Array */
    printf("After Sorting: \n");
    printArr(A, A_len);

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

void selectionSort(int A[], int n) 
/* Sorts an array using an iterative sort
 *  Input:
 *      int A[] - An array of integers
 *      int n   - The number of elements in A[]
 **********************
 *  Output: None
 */
{
  int i, j, big;
	for (i=n; i>0; i--) {
		/* find largest val in A[0..i-1].
            This can be done with a helper function */
        big = 0;
        for (j=1; j<n; j++) {
            if (A[j]>A[big]) {
                big = j;
            }
        }
		/* and swap it to the last location */
		int_swap(A+big, A+i-1);
	}
	return;
}

/****************************************************************************/

void selectionSort_rec(int A[], int n) 
/* Sorts an array using a recursive selection sort
 *  Input:
 *      int A[] - An array of integers
 *      int n   - The number of elements in A[]
 **********************
 *  Output: None
 */
{   
    int big, i;
	if (n<=1) {
		/* easy cases, already sorted */
		return;
	}
	
    /* find largest val in A[0..i-1].
        This can be done with a helper function */
    big = 0;
    for (i=1; i<n; i++) {
        if (A[i]>A[big]) {
            big = i;
        }
    }

	int_swap(A+big, A+n-1);
	/* now get a friend to do the rest of the work */
	sort_int_array_rec(A, n-1);
	return;
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
