# Workshop 4 Question

## Ex 7.6

An alternative sorting algorithm that you might be familiar with goes like this:

1. Scan the array to find the location of largest element
2. Swap it into the last position
3. Repeat, concentrating on the un-swapped elements (ie anything left of the swapped values).

This is called selection sort. Discuss it and implement it as a function `void selection_sort(int A[], int n)` that orders the n elements in array A.

(Challenge question): How do you do this with recursion rather than iteration?

### Answer

A solution is attached in 7.6Ans.c

*How do we do this with recursion?*
The iterative case uses a for loop to start at index n and switch the largest element into place until we hit the start of the array.

The recursive case does much the same thing, except instead of iterating over the same size list, we just give the remote element of the recursion a smaller array element to begin with.
In fact these two functions are almost identical in how they work. 

## Ex 7.7

Write a function that takes as arguments an integer array `A[]` and `int n`, that indicates how many elements of A may be accessed, and returns the value of the integer in A that appears most frequently (ie return the Mode). If there's more than one "most frequent value," return the smallest one. The array A should **not** be modified.

### Answer

Alistair's Solution is attached in 7.7Ans.c

Have a go at deriving the complexity of this function by hand. Go on, I'll wait.





This one is pretty clearly $O(n^2)$. As we can see, we have a nested for loop. The outer loop runs for all [0..n], and the inner loop runs for all [0..n]. In practice this means, for all n elements we complete n operations. (Comparisons in this case). That means we can take the $O(n)$ of the inner loop and multiply it by the $O(n)$ of the outer loop, and get $O(n^2)$.

## Ex 7.8

Write a function that takes as arguments an integer array `A[]`, an integer `n` that indicated how many elements in A may be accessed, and an integer `k`. The function should return the `k`th smallest integer in A. That is, the integer returned should slip into `A[k]` if array `A` were to be sorted. That being said, the array `A` should **not** be sorted. Be sure to handle duplicates correctly.

### Answer

Alistair's 7.8 Solution is attached in 7.8Ans.c.
As you can see, he's used an interesting bit of idiomatic C on lines 74 and 75.

``` C
for (j=0; j<n; j++) {
    smaller += (A[j]<A[i]);
    equal += (A[j]==A[i]);
}
```

So what's happening here, if you haven't already worked it out, is the boolean expression 
`A[j] < A[i]` evaluates to 1 if A[j] < A[i], and 0 if it isn't the case. This is a shorthand that you won't find in many other languages, but it's important to be able to explain why this works.



As for the O() complexity of this one, well it's exactly the same as 7.8 in the average case, usually the return A[i] line isn't triggered, so we say the algorithm is $O(n^2)$ 

## Ex 7.9

One way of quantifying how close an array is to being sorted is the number of ascending *runs*. For example, in the array `{10, 13, 16, 18, 15, 22, 21}`, there are 3 runs present, starting at 10, 15, and 21. Write a function that returns the number of runs present in the integer array `A` of size `n`.

### Answer

In this case we only need a linear scan to see if there are any two elements in the array which are out of order, ie we can see there are inversions at (18,15) and (22,21), making for 3 total runs.

```C
int
num_asc_runs(int A[], int n) {
	int i, runs=1;
	if (n==0) {
		return 0;
	}
	/* try elements in pairs */
	for (i=0; i<n-1; i++) {
		runs += (A[i]>A[i+1]);
	}
	return runs;
}
```

This search is in linear time, ie $O(n)$

## Ex 7.10

Another way of quantifying sortedness is to count the number of *inversions* - pairs of elements that are out of order. For example, on the sequence from Ex 7.9, there are 3 inversions, two caused by 15 and one caused by 21. Write a function that returns the number of inversions present in the integer array `A` of size `n`.

### Answer

This function is a little more complicated. This time we use a quadratic-time function (ie $O(n^2)$) to test pairs which are out of order. That is, inv will increment every time a number in index i is larger than elements to its right.

```C
int
num_inversions(int A[], int n) {
	int i, j, inv=0;
	/* try elements in pairs */
	for (i=0; i<n-1; i++) {
		for (j=i+1; j<n; j++) {
			inv += (A[i]>A[j]);
		}
	}
	return inv;
}
```

This question was worded weird so I don't blame you if you don't get it haha.

## Ex 7.11

Consider the following program, which makes use of the types and functions declared in Figures 7.5 and 7.7, assuming that `SIZE` is 5. What are the final values stored in matrix C at the end of this program?

```C
#define SIZE 5;
// Figure 7.5
typedef double vector_t[SIZE];

void
vector_add(vector_t A, vector_t B, vector_t C, int n) {
	int i;
    for (i=0; i<n; i++) {
    	C[i] = A[i] + B[i];
    }
}

void
sqmatrix_add2(vector_t A[], vector_t B[], vector_t C[],
		int n) {
	int i;
	for (i=0; i<n; i++) {
		vector_add(A[i], B[i], C[i], n);
	}
}

// Figure 7.7
typedef vector_t sqmatrix_t[SIZE];
// Functions cut for berevity

// Question elements
vector_t A, B;
sqmatrix_t C;
int i;

for (i = 0; i < SIZE; i++) {
    A[i] = 0.5 * i;
    B[i] = 1.0 / (i+1);
}

vector_add(A, B, C[0], SIZE);
for (i = 1; i < SIZE; i++) {
    vector_add(A, C[i-1], C[i], SIZE);
}
sqmatrix_add2(C, C, C, SIZE); // Edit: I missed this line orignially, my bad.
```

### Answer

This problem deals with square matrices. Running the code outputs this:

```
 2.000   2.000   2.667   3.500   4.400  
 2.000   3.000   4.667   6.500   8.400  
 2.000   4.000   6.667   9.500  12.400  
 2.000   5.000   8.667  12.500  16.400  
 2.000   6.000  10.667  15.500  20.400  
```

Why?
Well by the for loop we can see that A[] and B[] look like:

```
double A[SIZE] = {0.0, 0.5, 1.0, 1.5, 2.0};
double B[SIZE] = {1.0, 0.5, 0.33, 0.25, 0.2};
```

Then we just add the 2 vectors together for the first row of C, giving:


```
double C[0] = (1.0, 1.0, 1.33, 1.75, 2.2};

```

The remaining for rows, we add the previous row to A, giving

```
C[1] = {1.0, 1.5, 2.33, 3.25, 4.2};
C[2] = {1.0, 2.0, 3.33, 4.75, 6.2};
C[3] = {1.0, 2.5, 4.33, 6.25, 8.2};
C[4] = {1.0, 3.0, 5.33, 7.75, 10.25};
```

Then we do the sqmatrix_add2(), which basically adds every element to itself, yielding the result.