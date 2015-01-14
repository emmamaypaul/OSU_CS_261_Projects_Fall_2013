/*
 * Q0.c
 *
 *  Created on: Oct 10, 2013
 *      Author: Emma
 */

/* CS261- Assignment 1 - Q. 0*/
/* Name: Emma Paul
 * Date: October 13, 2013
 * Solution description: This program demonstrates the difference between addresses and pointers, as well as their uses
 * Note: I worked with and completed my homework with Ian Paul
 */


#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr) //defining a function, with no return, the argument is of type int* which is a pointer to an integer, iptr is name of variable
{
     /*Print the value pointed to by iptr*/
	printf("The value pointed to by iptr* is: %d\n", *iptr); //%d has to be in "", * finds address of where iptr is and points to the value at that address, %d is for decimal integer

     /*Print the address pointed to by iptr*/
	printf("The address pointed to by iptr* is : %x\n", iptr); //%x is for hexadecimal integers, for addresses its common to use hexadecimal

     /*Print the address of iptr itself*/
	printf("The address of iptr itself is: %x\n", &iptr); //if you want to print an address use %x, & is used to find the address of something
}

int main(){

    /*declare an integer x*/
	int x; //x is initialized to 0 automatically if not initialized to a number

    /*print the address of x*/
	printf("The address of x is: %x\n", &x);

    /*Call fooA() with the address of x*/
	fooA(&x); //the address of x is passed into function foo

    /*print the value of x*/
	printf("The value of x is: %d\n", x);

    return 0;//return 0 means exit normally
}

