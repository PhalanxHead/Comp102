# Workshop 03 Questions

## Question 6.2

For each of the 3 marked points in the following program, write down a list of all of the program-declared variables and functions which are in the scope at that point, and for each of these, it's type. Don't forget `main`, `argc`, and `argv.` When there is more than one choice for a given name, be sure to indicate what it is you're referring to.

```c
int bill (int jack, int jane);
double jane (double dick, int fred, double dave);

int trev;

int
main(int argc, char *argv[]) {
	double beth;
	int pete, bill;
	/* point #1 */
	return 0;
}

int
bill (int jack, int jane) {
	int mary;
	double zack;
	/* point #2 */
	return 0;
}

double
jane (double dick, int fred, double dave) {
	double trev;
	/* point #3 */
	return 0.0;
}
```

## Question 7.3

Modify the program of Figure 7.3 (below) so that after the array has been sorted, only the distinct values are retained in the array (with variable n suitably reduced):

Example:

``` 
mac: ./distinct
Enter as many as 1000 values, ^D to end
1 8 15 3 17 12 4 8 4
^D
9 values read into array
Before:    1    8   15    3   17   12    4    8    4
After:     1    3    4    8   12   15   17
```

Figure 7.3 (modified to be in a function):

``` c
/* Sorts an array using insertion sort
    Input:
        int A[] - An array of integers
        int n   - The number of elements in A[]
**********************
    Output: None
*/
void insertionSort(int A[], int n) {
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
```

## Question 6.9

Consider again Exercise 3.6 (Below). Write a function `int try_one_coin(int *cents, int coin)` that reduces the current `cents` amount by the values of the current `coin` as many times as is possible, altering the values of `cents` appropriately, and returning the number of counts of that denomination that should be issued.

Then write a function `void print_change(int cents)` that tests each different coin denomination in the correct ordering, and uses `try_one_coin()` to tell it how to generate the required change.

In the late 1980s in Australia, 1c and 2c coins were taken out of circulation, and \$1 and \$2 coins were introduced. Write a further function `int round_to_5(int cents)` that returns a value rounded off to the nearest multiple of five. For example, 12c of change is rounded to 10c, 23c is rounded to 25c.

Finally, write a driver program that allows you to test your functions on monetary amounts of up to \$10.

------

Exercise 3.6:
Suppose that coins are available in denominations of 50c, 20c, 10c, 5c, 2c and 1c. Write a program `calculatechange` that reads an integer amount of cents between 0 and 99 (your program might check range bounding on these values) and prints out the coins necessary to make up that amount of money:

```
mac: ./calculatechange
Enter amount in cents: 93
The coins required to make 93 cents are:
50, 20, 20, 2, 1
```

## Question 7.4

Write a program that reads as many as 1000 integer values and counts the frequency of each value in the input:

```
mac: ./frequent
Enter as many as 1000 values, ^D to end
1 3 4 6 4 3 6 10 3 5 4 3 1 6 4 3 1
^D
17 values read into array
Value	Freq
   1	  3
   3	  5
   4	  4
   5	  1
   6	  3
  10	  1
```

There are two quite different algorithms for this problem. Can you identify both of them? One of them imposes an upper limit on the input values, so is less general than the other. Does it have any compensating advantages?