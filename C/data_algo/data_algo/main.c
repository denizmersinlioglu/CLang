//
//  main.c
//  data_algo
//
//  Created by Deniz Mersinlioğlu on 1/18/20.
//  Copyright © 2020 DevelopmentHouse. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure -> Group of related data members
// Functions -> Group of related instructions
struct Student{
    int id; // --> 2 bytes
    char name[25]; // --> 25 bytes
    char dept[10]; // --> 10 bytes
    char address[50]; // --> 50 bytes
};

struct ComplexNumber{
    int real; // --> 2 bytes
    int imaginary; // --> 2 bytes
};

struct Rectangle{
    int width; // --> 2 bytes
    int length; // --> 2 bytes
};

struct Card{
    int face;
    int shape;
    int color;
};

struct Test{
    int A[5];
    int n;
};

int add(int a, int b) // -> Prototype of a function. Arguments -> Formal parameters
{
    int c;
    c = a+b;
    return (c);
}

void swapByValue(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swapByAddress(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp; // Change the value of addressed memory part with another.
}

// To pass array as a parameter, we need to put empty brackets [], Don't give a size.
// A[] is like a pointer to the array. [] -> Means its a pointer to an array.
// Arrays must be passed by address. They can not passed by values at all.
// You can write the prototype of the function as printArray(int *A, int n) -> It's valid however it can point any value.
// The A[] decleration in the prototype means it can be only the pointer to the arrays.
// If you modify the elements of the array, it will reflect the actual values.
void writeConsoleArray(int A[], int n)
{
    int i;
    for (i=0; i<n; i++) {
        printf("%d\n", A[i]);
    }
}

// You need to put * to return array. [] gets a compiler error.
// You return a pointer. If the call site stores the pointer in its call stack, the call site also can access the same resource.
int * createArray(int n)
{
    int *p;
    p = (int *) malloc(n*sizeof(int));
    return(p);
}


int area(struct Rectangle r) // New seperate structure created (copied) to area function stack frame.
{
    return (r.length * r.width);
}

// Give the pointer to the function and it will change the actual parameters.
// You can use either (*p).length or p->length to change the pointed values.
void changeLength(struct Rectangle *r1)
{
    r1->length = r1->length + 1;
    (*r1).length = (*r1).length + 1;
}


void testStructure(struct Test t1)
{
    t1.A[0] = 5; // You can change the value of the array inside of the struct. -> Pass by value
    t1.A[1] = 9; // However any of the changes would apply to actual parameters. -> Pass by value
}

void initialize(struct Rectangle *r, int l, int w)
{
    r->length = l;
    r->width = w;
}


void introductionToC()
{
    struct Rectangle r1;
    r1.length = 15;
    r1.width = 20;
    
    struct Rectangle r2 = {10,5};
    
    printf("r1 width: %d, length: %d \n", r1.width, r1.length);
    printf("r2 width: %d, length: %d \n", r2.width, r2.length);
    
    
    struct Student s;
    s.id = 10;
    strcpy(s.name, "John Doe");
    // Copy string to s.name. However:
    // name => char [25] => "John Deniz Mersinlioglu D"
    // dept => char [10] => "eniz Mersi"
    // adress => char [50] => "nlioglu"
    // Note that struct memory allocation is continious and the remaining items copied to next addresses.
    printf("Student id: %d, name: %s \n", s.id, s.name);
    
    
    struct Card card = {4,5,6};
    printf("Card face: %d, shape: %d, color: %d \n", card.face, card.shape, card.color);
    
    int deckLength = 52;
    struct Card deck[deckLength];
    int i = 0;
    for (i = 0; i < deckLength; i++){
        struct Card newCard = {i, i, i};
        deck[i] = newCard;
    }
    //
    //    for (i = 0; i < deckLength; i++){
    //        printf("Card face: %d, shape: %d, color: %d \n", deck[i].face, deck[i].shape, deck[i].color);
    //    }
    
    struct Card deck2[4] = {{0,0,0}, {1,1,1}, {2,2,2}, {3,3,3}};
    for (i = 0; i < 4; i++){
        printf("Card face: %d, shape: %d, color: %d \n", deck2[i].face, deck2[i].shape, deck2[i].color);
    }
    
    
    // Pointer -> Address data. Not data itself.
    // Main Memory -> code + func stack + heap -> Program divide main memory into 3 sections.
    // Code -> Our code executes.
    // Program can directly access to Code Section and Stack Section.
    // Program can not directly access to Heap (Yığın)
    // Pointer used
    //      -> To access the resources that are outside the program.
    //      -> To access Heap Memory.
    //      -> To access hard disk files.
    //      -> To access keyboard - mouse input
    //      -> To access network connection.
    //      -> To access a monitor.
    //      -> PARAMETER PASSING.
    
    
    int a = 10; // -> Data variable. (value = 10, address = 201)
    int *p; // -> Address variable. (2 bytes) (self address = 501)
    p = &a; // -> Initialization of a address variable -> assing p to address of a. (value = 201)
    
    // Stack contains main function -> Program.
    // Stack contains value of a. -> 10: 2 bytes.
    // Stack contains pointer p (2 bytes) and pointing to a's address.
    
    printf("the value of a: %d\n", a);
    printf("the p: %d\n", p); // the p: -272632828 -> the pointing address of the a. = &a
    printf("the *p: %d\n", *p); // -> Dereferencing of a variable. Get the value of it. == a
    printf("the &p: %d\n", &p); // the &p: -272632840 -> the self addresss of the p. Different than the pointing address of the p.
    
    // If you declare a variable that definitely takes place in the stack. STACK FRAME OF THE PARTICULAR FUNCTION. -> Static
    // When you write malloc you GET THE MEMORY IN HEAP. -> Dynamic
    
    int *p2;
    
    p2 = (int *) malloc(5*sizeof(int)); // -> Malloc takes a byte size to allocate memory in heap. -> CREATING HEAP MEMORY.
    // sizeof(TYPE) -> compiler decide to pick size for a specific type.
    // malloc function returns a void pointer, we have to cast it to a integer pointer.
    // c++ -> p2 = new int[5] -> Syntax is way easier in c++.
    
    
    struct Rectangle r3 = {5, 15}; // -> Static memory -> rectange in stack frame of main func
    struct Rectangle *p3 = &r3; // -> Size of a pointer is 2 bytes (sizeof(int)) what ever it points.
    (*p3).length = 20; // -> Dereference the pointer and change the value.
    p3->length = 20; // -> The syntatic sugar (*p) == p->
    // For data variable use .
    // For pointer variable use ->
    
    // We create pointer with the type of stored element in the memory.
    // Type cast with (Type *)
    struct Rectangle *p4 = (struct Rectangle *) malloc(sizeof(struct Rectangle)); // -> Dynamic memory -> rectange in heap.
    // malloc function return void pointer -> Generic pointer -> We need to type cast.
    p4->length = 10;
    p4->width = 25;
    
    // You can use pointer to point data variables in function call stack.  -> STATIC OBJECT
    // You can use pointer to point dynamic data in the heap.               -> DYNAMIC OBJECT
    
    
    // PARAMETER PASSING
    //      -> Pass by value        : C + Cpp
    //      -> Pass by Address      : C + Cpp
    //      -> Pass by Reference    : Only Cpp
    
    // Functions -> Group of related instructions
    // Functions are called as modules or procedures.
    // Monolithic programming -> Everything inside a single body
    // Modular - Procedural programming -> Break down into smaller functions.
    int x = 5;
    int y = 10;
    int z = add(x, y); // -> Values are copied to the function call stack. Actual parameters -> (x, y)
    // When a function called -> New stack frame is created for the function.
    // Main has a stack frame - Add also has own stack frame and its own copied variables.
    // When add called from main and activation record(stack frame) created for add function.
    // When add function returns, activation record(stack frame) removed from stack-> in main memory.
    // Functions has own activation record, has a different stack in the memory.
    // Main can not directly access the variables of the add -> Add cannot directly access the variables of the main.
    // Add can access of the variables of the main via pointers -> In direct access.
    

    int n, m;
    n = 10;
    m = 20;
    swapByValue(m, n);
    printf("m is %d, n is %d\n", m, n);
    // -> Pass by value:
    //      - Copy values to stack frame of the swap function.
    //      - Swap values and return. Formal parameters are changed. But actual parameters doesn't effected.
    //      - Only the values copied in to swap stack frame changed. No effect to the main function
    // When you return something -> Pure Function -> You can use pass by value.
    
    
    
    int m1, n1;
    m1 = 3;
    n1 = 2;
    swapByAddress(&n1, &m1);
    printf("m is %d, n is %d\n", m1, n1);
    // -> Pass by address
    //      - You need to pass the address of the parameters. &x and &y.
    //      - You need to swap dereferenced values of the pointers.
    
    
    int A[5] = {2,4,6,8,10};
    writeConsoleArray(A, 5);   // Pass the array by address. You can not pass arrays by values.
    
    int *array;
    array = createArray(5); // You can create an retrieve the pointer of an array with a function.
    writeConsoleArray(array, 5);
    
    // Pass the address of the structure to pass by address. (&r1) -> the address of the structure.
    changeLength(&r1); // Length of the r1 increase by 2: 15->17
    printf("the area: %d\n", area(r1));
    
    // You can pass a structure by value.
    // You cant pass an Array by value.
    // You can pass a structure by value even if it contains an array inside of it.
    // A new structure copied to the stack frame of testStructure function.
    // A new structure and the array contained by the structure copied to another address.
    // Copying array is time consuming. -> Compiler doesn't allow that. However in a struct, compiler have to do it!
    struct Test t = {{2,4,6,8,10}, 5}; // Note that: you can create structures just like NESTED ARRAYS.
    testStructure(t);
    
    
    struct Rectangle *r4 = (struct Rectangle *) malloc(sizeof(struct Rectangle)); // Create a dynamic Rectange in heap.
    struct Rectangle r5;
    initialize(&r5, 20, 25);
    initialize(r4, 15, 15);
    printf("the area of r4: %d\n", area(*r4));
    changeLength(r4);
    printf("the area of r4: %d\n", area(*r4));
    // Writing structures and functions upon these structures is the highest level of programming in C.
    // If every function uses struct as a parameter -> We can encapsulate it to utilize more.
    // This type of programming leads to object orientation.
    // The functions related to the structure -> We will encapsulate it within a class in object oriented paradigm.
    // We will abstract the internal details of the object -> Abstraction
    // We will inherit over the objects -> Inheritance
    // We will overload the functions with arguments -> Polymorphism.
    printf("\n");
}

// ----------- ----------- ----------- -----------

/* Introduction
 Data Structure: Arrangement of collection of data items so that can utilize efficiently operations on.
 The operations are executed in the main memory of the program.
 Any program installed in HDD. Any data stored in HDD. (msword + docx)
 When you open a program, program file transferred to main memory from hdd.
 When you open a docx -> data transferred to main memory.
 Program allocates the data inside the memory to utilize it efficiently. -> Data Structures formed by program.
 Data structures is a part of a running program.
 Database -> Keep data relational and easly accessible in a hard drive with tables or docs.
 Data warehouse -> Keep and store old data in an array of disks. -> Analyze them with data mining algorithms.
 Big Data -> Storing and utilizing large amount of data.
*/

/* Static vs Dynamic Memory Allocation
 Main memory has two dimensions, however address of every byte has single dimension. 0,1,2,3,......n
 A memory address 0...65535 -> 65536 - 64*1024 = 64KB Memory
 In larger memories like 4GB or 8GB, memory divided into segments. -> Segment size is 64KB
 Main memory divided into 3 sections. Actually order: Code - Heap - Stack -> CPU, easy to draw: Code - Stack - Heap -> CPU
 Machine code of the program transfered to code section of the main memory. -> Depends on the size of a program.
 Loaded program to code section of memory is start to used by CPU and they utilize the remaining parts (stack and heap).
 Assume int->2bytes + float->4bytes. The size of the types varies upon compiler, os and hardware. 64bit - 32bit.
 Activition Record = Stack frame of a function -> static variables located on the stack frame.
 How many bytes the program required and every activition record memory decided in compile time -> STATIC
 The size of the memory allocated for a stack frame is constant and static, decided on compile time -> STATIC
 */

/*Static vs Dynamic Memory Allocation Continued
 Top most activation record is belongs to execution function - program.
 The arguments passed by value -> Create a memory allocation inside the stack frame.
 Activition record deleted when a func is terminated.
 Stack section memory behaves like stack -> push and pop the stack frames.
 Compiler automatically determines the required size for a function.
 Compiler will allocate and deallocate the required memory for activation record. Programmer only need to decleare variables.
 Heap-> pile something randomly. Heap can be used for either orginized piles and unorganized piles.
 In main memory -> Heap term used as UNORGANIZED memory.
 Heap memory should be treated like a resource. You should release the heap when you are done.
 Program can access direcly to code and stack section of main memory. It cannot access to Heap memory. -> Use Pointer (sizeOf(int))
 Pointer allocated in stack frame. -> int *p (point to address == 500);
 p = new int[5] -> new keyword allocate memory in heap.
 */

/* Types of Data Structures
 Physical Data Structures -> Arrays + Linked Lists.
    These data structures defines how the memory organized and allocated.
    Array ->        Contiguous memory locations. Locations are side by side.
                    It has fixed size and when it was created, you can not change the size. Size of an array is static.
                    Arrays can be created inside of STACK or HEAP (w/ pointer).
 
    Linked List ->  Complete dynamic data structure. Collection of nodes.
                    Each node contains data and link to next node.
                    Size of the Linked list can reduce or grow dynamically. Variable Length.
                    Always created in Heap. Head pointer allocated in stack.
                    
 Logical Data Structures
    Stack -> linear (LIFO)
    Queues -> linear (FIFO)
    Trees -> non-linear
    Graph -> non-linear
    Hashtable -> tabular
 
    We use arrays or linked lists to implement logical data structures.
    Logical data structures implemented by using physical data structures.
    Array - Linked List or combination of them can be used.
 */

/* Abstract Data Type (ADT)
 Data Type: -> Representation of Data
            -> Operation on Data
        int x; -> 2 bytes = 16 Bits -> 1 bit to sign + 15 bit to value -> Representation of the integer (primitive type.)
        int -> + - * / % ++ -- -> Operations of int. -> Pre increment and post increment also allowed.
 
 Abstract:  -> Hiding the internal details.
            -> We don't know how the binary form performs the operations.
            -> Without knowing the details we can use them. (The type is abstract.)
 
 With using Object Oriented Software Languages -> We can create our own data types. (Classes) are Abstract.
 ADT is related to OOP.
 If we can show the representation of a class and define the operations of it -> It is dataType.
 -> Operations + Representations Abstract: ADT
 -> Let it be used by hiding the internal implementation details -> ABSTRACT DATA TYPE.
 
 As an example List:
    -> Representation: Use array of linked list -> Abstracted from user.
        1- Space for storing elements
        2- Capacity
        3- Size
    -> Operations:
        - add(x) / append(x)
        - add(index, e) / insert(index, e) -> Shift existing elements to right.
        - remove(index)
        - set(index, e) / replace(index, e)
        - get(index)
        - search(key) / contains(key)
        - sort()
 */

int main(int argc, const char * argv[]) {
//    introductionToC();
    
    int *p;
    p = (int *) malloc(5*sizeof(int));
    
    free(p);
    p = NULL;
   
    return 0;
}

