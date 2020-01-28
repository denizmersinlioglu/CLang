//
//  main.cpp
//  data_algo
//
//  Created by Deniz Mersinlioğlu on 1/18/20.
//  Copyright © 2020 DevelopmentHouse. All rights reserved.
//

#include <iostream> // You can include "iosstream.h" depends on compiler you are using.

using namespace std; // You can use cin and cout objects for display or reading.

struct Student{
    int id;
    char name[25];
    char dept[10];
    char address[50];
};

struct ComplexNumber{
    int real;
    int complex;
};

struct Rectangle{
    int width;
    int length;
};

struct Card{
    int face;
    int shape;
    int color;
};

void swapByReference(int &x, int &y) // Actual parameters passed as it is. Just renamed as x and y.
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// Not a seperate struct created or copied. Function copied to call site.
// Just create an alias or another name for passed arguments.
// Any changes on r1 will effect the actual parameter passed to the function.
int area(struct Rectangle &r1)
{
    return r1.length * r1.width;
}

class Rect{ // -> Convert C struct and related functions to class in C++
    
private: // Make fields are private. You can insert private: -> Following functions will be private.
    int width;
    int length;
    
    
public: // Make functions are public. You can insert public: -> Following functions will be public.
    Rect (int length, int w)
    {
        this->length = length;
        this->width = w;
    }
    
    int area()
    {
        return length*width;
    }
    
    void changeLenght(int l)
    {
        this->length = l;
    }
};

// ------------- Rect2 Implementation in C++ -------------
class Rect2{
private:
    int length;
    int breadth;
    
public:
    Rect2(){
        length = breadth = 1; // You can define or assign multiple values at once.
    }
    // Constructor overloading. It will be defining outside using SCOPE RESOLUTION OPERATOR. ( :: )
    // This is just a Prototype - Signature - Header of a Function.
    Rect2(int l, int b);
    int area(); // -> Facilitators (Yardımcılar)
    int perimeter(); // -> Facilitators (Yardımcılar)
    int getLength() { return length; } // -> Accessor - Get Function - Getter Function
    void setLength(int l) { length = l; } // -> Mutator - Set Function - Setter Function
    
    // If you have to destroy anything and if you have any dynamic memory allocation inside the constructor
    // You can release the memory inside the destructor.
    ~Rect2(); // put ~ prefix of a constructor. It will take no arguments at all.
};


Rect2::Rect2(int length, int breadth) // -> Scope resolution and define the function. Header of function defined previously.
{
    this->length = length;
    this->breadth = breadth;
}

int Rect2::area()
{
    return length*breadth;
}

int Rect2::perimeter()
{
    return 2*(length+breadth);
}

Rect2::~Rect2()
{
    
}
// ------------- * -------------


// C++ support generic (template) functions and generic (template) classes.
// You can use same class for multiple data types.
template <class T> // You need to use the template <class T> in every scope resolution and definition to use T type.
class Arithmetic{
private:
    T a;
    T b;
    
public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add()
{
    return a+b;
}

template <class T>
T Arithmetic<T>::sub()
{
    return a-b;
}

void introductionToCpp()
{
    std::cout << "Hello, World!\n";
    struct Rectangle r1;
    r1.length = 15;
    r1.width = 20;
    
    struct Rectangle r2 = {10,5};
    
    std::cout << "r1 width: " << r1.width << " length: " << r1.length << "\n";
    std::cout << "r2 width: " << r2.width << " length: " << r2.length << "\n";
    
    
    struct Student s;
    s.id = 10;
    strcpy(s.name, "John Doe");
    
    std::cout << "Student id: " << s.id << ", name: " << s.name << "\n";
    
    
    struct Card card = {4,5,6};
    std::cout << "Card face: " << card.face << ", shape: " << card.shape << ", color: " << card.color << "\n";
    
    int deckLength  = 52;
    struct Card deck[deckLength];
    int i = 0;
    for (i = 0; i < deckLength; i++) {
        struct Card newCard = {i,i,i};
        deck[i] = newCard;
    }
    
    struct Card dec2[4] = {{0,0,0}, {1,1,1}, {2,2,2}, {3,3,3}};
    for (i = 0; i<4; i++) {
        std::cout << "Card face: " << dec2[i].face << ", shape: " << dec2[i].shape << ", color: " << dec2[i].color << "\n";
    }
    
    
    int a = 10;
    int *p;
    p = &a;
    
    std::cout << "the value of a: " << a << "\n";
    std::cout << "the POINTING ADRESS of p, ADDRESS OF a: " << p << "\n";
    std::cout << "the value of a, getting with dereferencing by *p: " << *p << "\n";
    std::cout << "the address of pointer p: " << &p << "\n";
    
    int *p2;
    p2 = new int[6]; // malloc a heap memory and address it with pointer. Syntatic sugar
    p2 = (int *) malloc(6*sizeof(int)); // malloc a heap memory and address it with pointer.
    
    // Reference is a nickname given to a variable or alias given to a variable.
    // Reference only exist in Cpp.
    // There is no seperated STACK FRAME for referance passing function.
    int &r = a; // a has a one more name = r. Create just a alias. Two name for same value inside the memory.
    // Reference must to initialized in decleration.
    // a -> Data type
    // *a -> Pointer type
    // &a -> Reference type (Ampersand) only in c++
    std::cout << a << "\n";
    r++;
    std::cout << r << "\n";
    std::cout << a << "\n";
    // It is useful when passing arguments. -> Insert stack frame to another with same parameter aliases.
    // Useful feauture of C++ for writing small functions. Use Reference not use Pointer.
    
    
    int n, m;
    n = 10;
    m = 20;
    swapByReference(m, n);
    std::cout << "m is " << m << ", n is " << n << "\n";
    // -> Pass by reference:
    //      - Just change the syntax of the prototype of the function. Change formal arguments x -> &x
    //      - Give another name for m and n and m.  m --> x and n --> y
    //      - It executes just like main function procedures the swap function with values m and n.
    //      - If you look at the memory -> Swap is not a seperate function when you call the function with &x and &y.
    //      - Main function calls swap function in the same call stack. Just name the parameters as x and y.
    //      - No seperate stack frame created for swap function. Inserted to the main functions call stack.
    //      - When swap function done -> Temp variable removed and m - n variables changed.
    //      - Machine code inserts the body of the swap function to call site (in to the main function).
    //      -> Machine code is monolithic even if c++ code is modular.
    //      - Call by reference need to be used carefully. Write only simple logic to functions that called by reference.
    
    
    Rect rect(5,19); // It is not a struct anymore. It is an object!
    //    rect.initialize(5,19); // To create object in decleration -> Create constructor.
    cout << "the area of rect: " << rect.area() << "\n";
    rect.changeLenght(21);
    cout << "the area of rect: " << rect.area() << "\n";
    
    Rect2 r4(10,5);
    cout<< r4.area() << "\n";
    cout<< r4.perimeter() << "\n";
    r4.setLength(20);
    cout<< r4.getLength() << "\n";
    // The destructor of the Rect2 automatically call at the end of the main function.
    // The objects inside the scope of the main function will be deallocated when the program reaches the end of the scope.
    
    
    
    Arithmetic<int> arInt(10,5);
    cout << "Aritmetic int sub: " << arInt.sub() << ", add: " << arInt.add() << "\n";
    
    Arithmetic<float> arFloat(1.2, 2.5);
    cout << "Aritmetic float sub: " << arFloat.sub() << ", add: " << arFloat.add() << "\n";
}

// ----------- ----------- ----------- -----------




int main(int argc, const char * argv[]) {
//    introductionToCpp();
    
    int *p;
    p = new int[5]; //-> new keyword allocate memory in heap.
    
    delete [] p; // Remove the heap memory.
    p = NULL; // Remove p and p no more point previous location.
    
    return 0;}
