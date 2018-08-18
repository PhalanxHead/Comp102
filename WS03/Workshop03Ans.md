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

### Answer

#### Point 1:

```
jane - double function with arguments (double dick, int fred, double dave)
trev - integer variable
argc - integer variable
argv - char*[] variable
beth - double variable
pete - integer variable
bill - integer variable
main - integer function with arguments (int argc, char *argv[])
```

Note that the `bill()` function has been over-written in `main()` by the variable, it's being 'shadowed.' C takes the latest and most local declaration of a variable/function in a given context when a variable is being referenced. In this case, it's the `int bill` variable.

#### Point 2:

```
bill - integer function with arguments (int jack, int jane)
trev - integer variable
jane - integer variable
jack - integer variable
mary - integer variable
zack - double variable
main - integer function with arguments (int argc, char *argv[])
```

Once again the function `jane()` is being shadowed by a local variable, this time it's the function argument. Note that we have access to `bill()` again here.

#### Point 3:

```
bill - integer function with arguments (int jack, int jane)
jane - double function with arguments (double dick, int fred, double dave)
trev - double variable
dick - double variable
fred - integer variable
dave - double variable
main - integer function with arguments (int argc, char *argv[])
```

Note this time that the `trev` global variable is being shadowed by the local variable with a different type. Changes to `trev` in the `jane()` function won't affect the global `trev` value.



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

### Answer

A full implementation is attached in 7.3Ans.c. This isn't the best solution however, it would be much more efficient to create a new array with only the unique values. This changes the efficiency from $O(n^2)$ (mutating the array) to $O(n)$ (Creating a new array) which is much much better.



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

### Answer

A solution is in 6.9Ans.c. Note the wording for this is a little confusing but the solution should match what's being suggested. See if you can work out what it means.

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

### Answer

A full solution is in 7.4Ans.c
There are 2 methods to this problem.

1. Sort the values and take the count of each unique value. You can store this in another array or print it out as the question asks. The 7.3 solution can also be adapted to do this, though it's not recommended due to the efficiency costs.
   Pros: This is intuitive and works for all integer values.

   Cons: The time cost of this is $O(n) + O(n logn) = O(n logn)$  (Comparison plus sorting) which is slower than method 2. NOTE: The solution implemented in 7.4Ans.c actually uses insertion sort  which is $O(n^2)$ not $O(n logn)$. Keep this in mind when you're doing your analysis.

   

2. Limit the minimum and maximum values to some arbitrary number, say 1 and 1000. Declare an array with that many spaces in it (setting all values to 0), and access each space by the value it's given, incrementing it. For example if 87 was read in you'd do this: `A[87] += 1;`

   This way you can print out the non-zero counts. This method may also be known as using a primitive hash table.

   Pros: The time cost of this is $O(n) + O(n) = O(n)$ (zeroing plus assigning) which is faster than method 1.
   Cons: Your array may have a lot of empty indexes, and obviously only works for a limited range of numbers.



## Q7.4 Easy

```
Say, I have a sorted array (of integers), let them write a function to output the frequencies of each number.

e.g. 
     int A[10] = {1,1,1,2,2,3,3,3,4,5};
     int A_len = 10;
     print_freq(A, n);

Output:

Num   Freq
  1      3
  2      2
  3      3
  4      1
  5      1

```

