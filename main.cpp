#include <iostream>
#include "Card.h"

using std::cout;
using std::endl;

void question1();

void foo(int& x, double& y, char& c);

void question2();

void changeDoubleWithPointer(double *dPtr);

void changeDoubleWithReference(double &dPtr);

void question3();

bool getCharacter(char *c);

void question4();

void question5();

void swap(int* a, int* b);

int main(void) {
    question1();
    question2();
    question3();
    question4();
    question5();
    return EXIT_SUCCESS;
}

void question1() {
    //corrected code, explanation in comments
    int i = 10;
    double d = 2.5;
    char c = 'e';

    // change the pointer iPtr to hold the address of the variable i which has a value of 10
    int *iPtr = &i;
    // This should be a double*- a pointer to the double d with value 2.5
    double *dPtr = &d;
    cout << "QUESTION 1" << endl;

    // this will print the memory address of the pointers
    cout << "iPtr = " << iPtr << ", dPtr = " << dPtr << endl;

    // this line will print out the values of the pointers i.e. 10 and 2.5
    cout << "*iPtr = " << *iPtr << ", *dPtr = " << *dPtr << endl;

    // The value of the variables of the pointers are changed i.e. i and d
    *iPtr = 5;
    *dPtr = 4.25;
    cout << "*iPtr = " << *iPtr << ", *dPtr = " << *dPtr << endl;

    cout << "i = " << i << ", d = " << d << ", c = " << c << endl;

    // The function now takes in the references of the variables,
    // so that the value of the variable will be altered in the function foo
    foo(i, d, c);
    cout << "i = " << i << ", d = " << d << ", c = " << c << endl;

    // Similarly, the values of the pointers will be altered in the function foo
    foo(*iPtr, *dPtr, c);
    cout << "i = " << i << ", d = " << d << ", c = " << c << endl << endl;
}

// Change the function to take references to variable of the pointer or variable
void foo(int& x, double& y, char& c) {
    x += 1;
    y += 2;
    ++c;
}

void question2() {
    cout << "QUESTION 2" << endl;
    //(a) Declares and initialises an integer
    int i = 20;

    //(b) Declares and initialises a pointer to the integer
    int *iPtr = &i;

    //(c) Directly modifies the value of the integer
    i = 30;

    //(d) Uses the pointer to modify the value of the integer
    *iPtr = 40;

    //(e) Declares and initialises a double
    double d = 40.30;

    //(f) Uses a function to modify the value of the double using a pointer to it
    changeDoubleWithPointer(&d);
    cout << "Change double d using a pointer: " << d << endl;

    //(g) Uses a function to modify the value of the double using a reference to it
    changeDoubleWithReference(d);
    cout << "Change double d using a reference: " << d << endl << endl;
}

void changeDoubleWithReference(double &dRef) {
    dRef = dRef * 2;
}

void changeDoubleWithPointer(double *dPtr) {
    *dPtr = *dPtr * 2;
}

void question3() {
    cout << "QUESTION 3" << endl;
    //(a) Write a simple program to read in a single character from standard input and print it to standard output.
    char c;
    cout << "Enter a character: ";
    std::cin >> c;
    cout << "The char entered is: " << c << endl;

    //(b) Modify your program to instead use the following function to do the reading from standard input:
    char d;
    if (getCharacter(&d)) {
        cout << "SUCCESS! Char was read!" << endl;
    } else {
        cout << "FAIL! Char was not read!" << endl;
    }

    //(c) Modify your program to reads up to 100 characters, and put the characters into a character array:
    char characters[101];
    cout << "Enter characters: ";
    std::cin >> characters;
    cout << "Characters: " << characters << endl;
    cout << "Characters backwards: ";
    reverse_copy(characters, characters + strlen(characters), std::ostream_iterator<char>(cout));
    cout << endl << endl;
}

bool getCharacter(char *c) {
    cout << "Enter a character: ";
    std::cin >> c;
    cout << "The char entered is: " << c << endl;
    return c[0] != EOF;
}

void question4() {
    cout << "QUESTION 4" << endl;
    Card cardRed7(1, "Red", 7, "Highest Card Wins");
    cout << "Red 7: Number: " << cardRed7.getUniqueNumber() << ", Colour: " << cardRed7.getColour()
         << ", Colour Number: " << cardRed7.getColourNumber() << ", Rule: " << cardRed7.getRule() << endl << endl;
}

void question5() {
    cout << "QUESTION 5" << endl;
    int a = 20, b = 45;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    swap(&a, &b);
    cout << "After swapping:" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl << endl;
}

//corrected swap function- swaps the values
void swap(int* a, int* b) {
    int* tmp = a;
    *a = *b;
    *b = *tmp;
}
