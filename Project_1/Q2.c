/*
 * Q2.c
 *
 *  Created on: Oct 10, 2013
 *      Author: Emma
 */


/* CS261- Assignment 1 - Q.2*/
/* Name: Emma Paul
 * Date: 10/13/2013
 * Solution description: This program first prints the values of variables x, y, and z
 * 						then the function foo doubles x, halves the value of y, and then adds those values together and returns the result
 * 						It then prints the new values of x, y, and z
 * 						(Since foo points to the value created rather than overrides the value of z, the original value of z is not lost)
 * Note: I worked with and completed my homework with Ian Paul
 */


#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c)
{
    /*Set a to double its original value*/
	*a = *a * 2;

    /*Set b to half its original value*/
    *b = *b / 2;

    /*Assign a+b to c*/
    c = *a + * b;

    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5;
	int y = 6;
	int z = 7;

    /*Print the values of x, y and z*/
	printf("The value of int x is: %d\n", x);
	printf("The value of int y is: %d\n", y);
	printf("The value of int z is: %d\n\n", z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
	int fooVal = foo(&x, &y, &z);//have to use the & to point to the value at those addresses


    /*Print the value returned by foo*/
	printf("The value returned by foo is: %d\n\n", fooVal);

    /*Print the values of x, y and z again*/
	printf("The new value of int x is: %d\n", x);
	printf("The new value of int y is: %d\n", y);
	printf("The new value of int z is: %d\n", z);
    /*Is the return value different than the value of z?  Why?*/

	//The return value fromt the function foo is different than the value of z
	//int z stays 7 because it is not changed or overridden when the function foo() is called (there is just a pointer to the return value I believe)
    return 0;
}

