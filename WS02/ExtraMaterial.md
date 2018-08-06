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

## 3. Why is it important to write comments in your code?

## 4. Write a function `int fib(int n)` that returns the n-th Fibonacci number. What is the efficiency of your function in Big-O Notation?

Hint: Recall that 
$$
F_n = F_{n-1} + F_{n-2}, (F_0 = 0, F_1 = 1)
$$
