//
//  main.c
//  Recursion
//
//  Created by Deniz Mersinlioğlu on 1/21/20.
//  Copyright © 2020 DevelopmentHouse. All rights reserved.
//

#include <stdio.h>

/* How Recursion Works
 Recursion uses stack. -> Push the new activition record and pop finished.
 type fun(param) {
 if (<base_condition>) { -> If base condition validates or terminate the recursion.
 // Ascending phase
 fun(param)          -> Call itself. -> Calling itself -> Recursion.
 // Descending phase
 }
 }
 1- switch on bulb
 2- go to next Room   -> 1 2 3
 
 1- go to next room
 2- switch on bulb    -> 3 2 1
 
 There is calling phase and returning phase of recursive functions. (Ascending - Descending)
 Recursive functions like a rubber band. You strecth the rubber band and release at base condition.
 Loops have only ascending phase. Ascending + Descending of recursion is the power of the recursion.
 Recursive functions uses stack push -> Ascending and pop -> Descending. Recursive functions are memory consuming.
 
 Time complexity of recursive function can be found with recurrence relation.
 T(n) => 1          n = 0
 T(n-1)     n > 0
 We can solve recurrence relation by induction method or successive substitution method.
 -> Convert any constant to 1
 -> T(n) = T(n-1) + 1        => T(n-1) = T(n-2)+1
 -> T(n) = T(n-2) + 2
 .
 -> T(n) = T(n-k) + k        => k = n
 -> T(n) = n + 1             => O(n)
 */

void recursiveFun1(int n)   // fun(3) -> fun(2) -> fun(1) -> fun(0) -> Tracing Tree of recursive func
{                           //  -> 3       ->2       ->1       ->X
    if (n > 0){
        // Calling time - Ascending
        printf("%d ", n);                        // Switch
        recursiveFun1(n-1); // Returning time    // Go to Next Room
        // Returning time - Descending
    }
}

void recursiveFun2(int n)
{
    if (n > 0){
        recursiveFun2(n-1); // Go to Next Room
        printf("%d ", n);   // Switch
    }
}

void tail(int n)
{
    if (n>0)
    {
        printf("%d", n);
        tail(n-1);
    }
}

void head(int n)
{
    if (n>0){
        head(n-1);
        printf("%d", n);
    }
}


/* Static vs Global Variables
Static variables stored in code section in main memory.
Static variables created only loading time of the program in memory.
Static variables has a single copy. All function calls will use the same copy of the x. Variable assign to program stack.
 Global variables also have a single copy. You can use it like static.
 Global variables also loaded when the program loaded to main memory.
 Global variables also maintained under code section of the memory.
*/
int staticVar(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return staticVar(n-1) + x;
    }
    return 0;
}

/* Types of Recursion
 Every loop can be converted to recursion vice versa.
 1- Tail Recursion
    - Recursion call is the last statement of the function.
    - Every operation invoked in calling time.
    - Returning time is empty.
    - fun(n-1) + n; -> +n breaks the tail recursion. +n performed in returning time.
    - Loop -> Time: O(n) - Space: O(1)
    - Recursion -> Time: O(n) - Space O(n)  --> Loop is efficient.
    - Some compilers converts tail recursion to loop. Try to space consumption.
 
 2- Head Recursion
    - Recursion call is the first statement of the function.
    - Every operation invoked in returning time.
    - It can not directly converted to loop. It can be converted in-directly.
 
 3- Tree Recursion
    - Linear Recursion: function calling itself only one time.
    - Tree Recursion: function calling itself more than one time.
    - Time complexity is exponential. Space complexity O(n).
 
 4- Indirect Recursion
    - funA -> funB -> funC -> funA : Circular calling.
 
 5- Nested Recursion
    - Recursive function pass parameter as the returning value of the recursive function.
    - The parameter value need to obtained to call recursive func.
 */

void treeRecursion(int n)  // 2^0 + 2^1 + 2^2 + ... + 2^n = 2^(n+1) - 1 => O(2^n)
{
    if (n>0)
    {
        printf("%d\n", n);
        treeRecursion(n-1);
        treeRecursion(n-1);
    }
}

void indirectRecursionB(int n);
void indirectRecursionA(int n)
{
    if (n>1)
    {
        printf("%d\n", n);
        indirectRecursionB(n-1);
    }
}

void indirectRecursionB(int n)
{
    if (n>1)
    {
        printf("%d\n", n);
        indirectRecursionA(n/2);
    }
}


int nestedRecursion(int n)
{
    if (n>100) return n-10;
    return nestedRecursion(nestedRecursion(n+11));
}

int sumNaturalNumbers(int n) // time: O(n), space: O(n)
{
    if(n > 0) return sumNaturalNumbers(n-1) + n;
    return 0;
}

int factorial(int n)
{
    if (n == 0) return 1;
    return n * factorial(n-1);
}

int power(int m, int n) // O(logn)
{
    if (n==0) return 1;
    if (n%2==0) return power(m*m, n/2);
    return m * power(m*m, n/2);
}

double taylor(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if(n==0) return 1;
    else{
        r = taylor(x, n-1);
        p = p*x;
        f = f*n;
        return r + p/f;
        
    }
}

int main(int argc, const char * argv[]) {
    
    printf("Tail: ");
    recursiveFun1(4); // First print and call recursive -> 4 3 2 1
    printf("\n");
    
    printf("Head: ");
    recursiveFun2(4); // First call recursive, recursive done and print  -> 1 2 3 4
    printf("\n");
    
    int x = 3;
    printf("Tail: ");
    tail(x);
    printf("\n");
    
    printf("Head: ");
    head(x);
    printf("\n");
    
    int a = 5;
    printf("Recursive Result with static variable: %d\n", staticVar(a));
    
    printf("Tree Recursion: \n");
    treeRecursion(3);
    printf("\n");
    
    printf("Indirect Recursion: \n");
    indirectRecursionA(20);
    printf("\n");
    
    printf("Nested Recursion: \n");
    printf("Recursive Result with static variable: %d\n", nestedRecursion(95));
    printf("\n");
    
    printf("SumNaturalNumbers: %d \n", sumNaturalNumbers(20));
    printf("Factorial: %d \n", factorial(5));
    printf("Power: %d \n", power(2,5));
    printf("Taylor: %f \n", taylor(1, 10));
    return 0;
}
