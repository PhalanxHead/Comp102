# Extra Materials for Workshops 4-6

I recommend doing these before the Mid Semester Test.

Midsem Notes: As stated on the LMS there are several Midsem locations to be disclosed soon.
It's on paper, so you should do a trial run on paper! It's a very different experience than in a text editor, if my dodgy board examples haven't already proven. Learn to write an '&' properly, it's hard.

## Ideas:
### Big O Notation - Algorithmic Complexity

We typically measure algorithms in terms of how long they take to operate on a collection of n items. This is called big O notation. O() notation measures how many operations are typically required to complete the given task. For example, it takes O(n) time to find the smallest value in an unsorted list, but O(1) in a sorted list.

Typically speaking, you're likely to see the following O() values:

$O(1), O(log n), O(n), O(n*logn), O(n^2), O(n^3), O(n!)$

These are in order of least to most complexity.

#### Why is this important?

Being able to measure the speed of an algorithm allows us to not only choose the most appropriate algorithm for a given task, but helps us determine if an algorithm will complete in our lifetime. We've seen that algorithms with high complexity can take hundreds of years to compute, so it's useful to know that what you're trying to do is feasible.

### Three Steps of C Programming:

1. Compile - Convert code to machine code. The preprocessor is run before this
2. Link - Link external libraries. This includes things like stdio, stdlib and math.
3. Execute - Load or Run your program.

With this in mind, what's the difference between `#define N 5` and `int n = 5;`?
Well, #define goes and replaces every occurrence of N with the number 5 just before compilation. N is not a variable, it's treated as a literal. We can't mutate it in the program, it's set.

n = 5 creates a variable called n which we can mutate if we wanted. It takes a small amount of memory though.

#### Function Returns in C

C doesn't let us return tuples like Python does. This sort of thing is not allowed:
`a, b, c = func(array, length);`

There's plenty of times one would wish to return multiple values however, and in C we achieve this in 3 main ways. We'll cover methods 2 & 3 later, it's not examinable in the Mid Semester test, don't stress!

#### Method 1: Return by Reference

Pretty simply, we mutate an input variable using pointers.

``` C
int
f1(int arg, int* ret2) {
	int ret1 = 0;
	*ret2 = ...;
	return ret1;
}
```

#### Method 2: Define a new Struct for return 

```C
struct ret_type {
    int ret1;
    int ret2;
};

struct ret_type
f2(int arg) {
	struct ret_type ret;
    ret.ret1 = ...;
    ret.ret2 = ...;
    return ret;
}
```

#### Method 3: Dynamically Allocate memory using malloc

```C
int*
f3(int arg) {
	int* ret = (int*)malloc(sizeof(int)*2);
	return ret;
}
```



## Practice

### 1. Guess the output:

```C
#include <stdio.h>
#define ARR_SIZE 5

int 
func(int A[], int num, int *key, int sub) {
    int i;
    for (i = 0; i < num; i++) {
        if (A[i] == *key) {		// Edit: Added parens, due to typo.
            A[i] = sub;
            sub = i;
            *key = sub;
            
            return i;
        }
    }
    return i;
}

int
main (int argc, char* argv[]) {
	int arr[ARR_SIZE] = {6,7,8,9,10};
	int key, index;
	
	key = 9;
	index = func(arr, ARR_SIZE, &key, 2);
	printf("index = %d, arr[index] = %d, key = %d\n", index, arr[index], key);
	
	key = 7;
	index = func(arr, ARR_SIZE, &key, 3);
	printf("index = %d, arr[index] = %d, key = %d\n", index, arr[index], key);
	
	key = 2;
	index = func(arr, ARR_SIZE, &key, 4);
	printf("index = %d, arr[index] = %d, key = %d\n", index, arr[index], key);
	
    for(index = 0; index < ARR_SIZE; index++) {
    	printf("arr[%d] = %d\n", index, arr[index]);
    }
    return 0;
}
```

Edit: Fixed a typo in the print lines, the m's were supposed to be ,'s

### Answer:

```
index = 3, arr[index] = 2, key = 3
index = 1, arr[index] = 3, key = 1
index = 3, arr[index] = 4, key = 3
arr[0] = 6
arr[1] = 3
arr[2] = 8
arr[3] = 4
arr[4] = 10
```



### 2. Write a function "`get_average()`" that takes an array of integers as a parameter and returns the arithmetic average (ie the Mean) of the integers. What is the efficiency of your program in big-O notation?

Example:

```
int A[5] = {20,30,40,50,60};
int average;

average = get_average(A, 5);
printf("Average = %d\n", average);
```

### Answer

```C
double
get_average(int A[], int A_len) {
    double sum = 0;
    int i;
    // Get the sum of the array
    for (i = 0; i < A_len; i++) {
        sum += A[i];
    }
    return sum / A_len;
}
```

The runtime of this function is $O(n)$. As you can see, the function operates from [0..n] elements, with one operation per element.

### 3. The following functions `fib1()` and `fib2()` calculate the nth Fibonacci number using different algorithms. Define the runtime efficiency of each function in Big-O Notation.

```C
int
fib1(int n) {
	if (n == 0) {
		return 0;
	}
    if (n == 1) {
    	return 1;
    }
    
    return fib(n-1) + fib(n-2);
}

int
fib2(int n) {
	int first = 0, second = 1, next, i;
	
    if (n == 0) {
    	return 0;
    }
    if (n == 1) {
    	return 1;
    }
    
    for (i = 2; i <= n; i++) {
    	next = first + second;
    	first = second;
    	second = next;
    }
    
    return next;
}
```

### Answer

![Fib1Proof](/Fib1Proof.PNG)

In words: Each recursive call starts 2 new recursive calls. This creates 2 new problems for every n calls of fib1. Therefore we have $O(2^n)$

Fib2 has efficiency $O(n)$

We operate on the array [2..n], with special cases for n == 0 or 1. Ergo it's linear or O(n).



### 4. Write a function  that takes an array of arbitrary numbers and returns (a) the smallest integer number in the array and (b) the count of the smallest number.

Recall: C functions can only return a single value, so we need to give back a mutated value elsewhere for at least one of these values.
As a hint, here's the function prototype:

`void smallest(int Arr[], int Arr_len, int* smallest_num, int* count);`

### Answer

```C
void 
smallest(int Arr[], int Arr_len, int* smallest_num, int* count) {
    int i;
    /* Need a baseline, better to use the first array 
    item (as we know it's in bounds) */
    int smallest = Arr[0];
    int counter = 1;
    
    for (i = 1; i < Arr_len; i++) {
    	/* Reset the counter if we find a smaller number */
        if(A[i] < smallest) {
			smallest = A[i];
			counter = 1;
        }
        else if (A[i] == smallest) {
        	counter++;
        }
    }
    *smallest_num = smallest;
    *count = counter;
}
```

This function has efficiency $O(n)$ as we operate from [1..n] with one operation.

### 5. Write a function that takes an array of integers, and identifies the starting index of the longest run of descending values, and its length. What is the efficiency in Big-O notation?

Example:

```C
int A[10] = {3, 1, 5, 4, 3, 2, 1, 5, 3, 2};
int A_len = 10;
// The longest descending run is {5,4,3,2,1}, beginning at A[2]
int index;
int length;
long_desc(A, A_len, &index, &length);

printf("The longest descending run begins at A[%d] with length %d\n", index, length);
```

### Answer

```C
void
long_desc(int A[], int A_len,int *index, int *length) {
    int i;
    /* Holds the length of the current run */
    int longest = 1;
    /* Holds the length of the longest run */
    int maxlen = 1;
    /* Holds the starting index of the current run */
    int indexer = 0;
    
    for (i = 1; i < A_len; i++) {
    	/* If left < right, the descending run has ended */
        if (A[i-1] < A[i]) {
	    	/* If this run is longer than the current maximum,
			   override the current maximum. Otherwise do nothing */
            if (longest > maxlen) {
				*length = longest;
				maxlen = longest;
				*index = indexer;
            } else {
				/* This line is a little redundant to be honest. */
				*length = maxlen;
            }
			/* Irrespective of the length of the last run, reset the values */
            indexer = i;
            longest = 1;
        } else {
			/* If right > left, the run continues. */
        	longest++;    
        }
    }
}
```

Despite the long stretch of code inside the for loop, this code is O(n).
