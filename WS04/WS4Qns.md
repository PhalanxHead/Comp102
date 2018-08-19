# Workshop 4 Question

## Ex 7.6

An alternative sorting algorithm that you might be familiar with goes like this:

1. Scan the array to find the location of largest element
2. Swap it into the last position
3. Repeat, concentrating on the un-swapped elements (ie anything left of the swapped values).

This is called selection sort. Discuss it and implement it as a function `void selection_sort(int A[], int n)` that orders the n elements in array A.

(Challenge question): How do you do this with recursion rather than iteration?

## Ex 7.7

Write a function that takes as arguments an integer array `A[]` and `int n`, that indicates how many elements of A may be accessed, and returns the value of the integer in A that appears most frequently (ie return the Mode). If there's more than one "most frequent value," return the smallest one. The array A should **not** be modified.

## Ex 7.8

Write a function that takes as arguments an integer array `A[]`, an integer `n` that indicated how many elements in A may be accessed, and an integer `k`. The function should return the `k`th smallest integer in A. That is, the integer returned should slip into `A[k]` if array `A` were to be sorted. That being said, the array `A` should **not** be sorted. Be sure to handle duplicates correctly.

## Ex 7.9

One way of quantifying how close an array is to being sorted is the number of ascending *runs*. For example, in the array `{10, 13, 16, 18, 15, 22, 21}`, there are 3 runs present, starting at 10, 15, and 21. Write a function that returns the number of runs present in the integer array `A` of size `n`.

## Ex 7.10

Another way of quantifying sortedness is to count the number of *inversions* - pairs of elements that are out of order. For example, on the sequence from Ex 7.9, there are 3 inversions, two caused by 15 and one caused by 21. Write a function that returns the number of inversions present in the integer array `A` of size `n`.

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
```

