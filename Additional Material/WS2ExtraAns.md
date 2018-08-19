# Extra Material for Study

Do these questions by hand! Answers will be in the ExtraMaterialAns.md file. Feel free to email me (lhedt@student.unimelb.edu.au) if you have any questions! Note: There's no guarantee that you might get exam questions like this. That being said, it's important to be able to reason about what's happening in the questions.

## 1. What's the Output of this program?

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    int x=3, y=4, z=5;
    int a, b, c;
    
    a = y > x++;
    b = x+y*z*(z-x)/(x+y);
    
    printf("a,b,c=%d,%d,%d\n", a, b, c);
    
    c = 1024*1024*1024;
    printf("c, c*2=%d, %d\n", c, c*2);
    
    return 0;
}
```

### Answer

```bash
a,b,c=1,6,#
c, c*2=1073741824, -2147483648
```

Note: The # is an undefined character. On my machine it was 0, but it may well not be.

## 2. Write a program (by hand!) that reads in a number from the user and prints out the multiplication table of the number.

Example:

```bash
mac: ./Q2
Number? 5
5 x 1 =  5
5 x 2 = 10
...
5 x 9 = 45
```

Hint: Don't forget all of your #include's!

```c
#include <stdio.h>
#include <stdlib.h>

// Define the number of iterations to print
#define ITER 9

int main(int argc, char *argv[]) {
    int inp, i;
    printf("Number? ");
    // Get input from the user and check it was right!
    if(scanf("%d", &inp) != 1) {
        printf("ERROR! Input a number!\n");
        exit(EXIT_FAILURE);
    }

    // Print out ITER times tables.
    for(i=1; i<=ITER; i++) {
        printf("%d x %d = %3d\n", inp, i, inp * i);
    }

    return 0;
}
```



## 3. Why is it important to write comments in your code?

So the next person to read or edit the code (probably you) can understand the code easily. It's particularly pertinent if you have difficult to understand expressions! This is also the reason to format your code nicely/

## 4. Write a function `int fib(int n)` that returns the n-th Fibonacci number. What is the efficiency of your function in Big-O Notation?

Hint: Recall that 
$$
F_n = F_{n-1} + F_{n-2}, (F_0 = 0, F_1 = 1)
$$

```c
// This one uses recursion!

int fib(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    return fib(n-2) + fib(n-1);
}
```

The recursive case has complexity 
$$
O(2^n)
$$
Proof: 
$$
T(n \leq 1) = O(1)
\\
T(n) = T(n-1) + T(n-2) + O(1)\\
\text{Assume:}\hspace{2em}
T(n-1) = O(2^{n-1})\\
\therefore T(n) = T(n-1) + T(n-2) + O(1)\\
\text{which is equal to}\hspace{2em}
T(n) = O(2^{n-1}) + O(2^{n-2}) + O(1) \\
T(n)= O(2^{n})
$$
That's pretty slow! We can do better!

```c
// Iterative Fib

int fib(int n) {
    int fibn, fn1, fn2, i;
    fibn=0; fn1=1; fn2=0;

    // Deal with the weird case of n <= 0
    if(n <= 0) {
        return 0;
    }

    // Apply the iterative version
    for(i=1; i<n; i++) {
        fibn = fn1 + fn2;
        fn2 = fn1;
        fn1 = fibn;
    }

    return fibn;
}
```

This time we use the iterative method, which has no recursion. We can clearly see that the only loop in this is executed a maximum of n times, hence the time complexity is O(n). That's turned a non-polynomial solution into a linear time solution!