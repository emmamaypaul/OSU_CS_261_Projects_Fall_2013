/*
 * Q3.c
 *
 *  Created on: Oct 10, 2013
 *      Author: Emma
 */

/* CS261- Assignment 1 - Q.3*/
/* Name: Emma Paul
 * Date: 10/ 13/ 2013
 * Solution description: This program generates an array of 20 random numbers, and then sorts the numbers
 * Sources used: http://stackoverflow.com/questions/4407696/sorting-an-array-in-c-from-low-to-high-without-using-qsort
 * 				 http://in.answers.yahoo.com/question/index?qid=20110106193159AApz7cl
 * Note: I worked with and completed my homework with Ian Paul
 */


#include <stdio.h>

void sort(int* number, int n)
{
     /*Sort the given array number , of length n*/
	int i;
	int j;
	int * tmp;

	//the code below was taken from the sources used
	//it starts on the right and moves to the left putting the smaller number on the left and the bigger on the right
	for (i=0; i<n-1; i++)
	{
		for (j=0; j<n-1-i; j++)
		{
			if (number[j+1] < number[j])  /* compare the two neighbors */
			{
				tmp = number[j]; /* swap a[j] and a[j+1] */
				number[j] = number[j+1];
				number[j+1] = tmp;
			}
		}
	 }
}

int main()
{

	srand ( time(0) ); //Seed the random number generator

    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
	int * myArray = malloc (sizeof(int)* n);

    /*Fill this array with random numbers, using rand().*/
	int i;

	     for(i = 0; i<20; i++)
	     {
	    	 myArray[i] = rand();
	     }

    /*Print the contents of the array.*/
	    printf("Here is an array of 20 random numbers\n");
		for(i = 0; i < 20; i++)
		{
			printf("%d, ", myArray[i]);
		}

		printf("\n\n");
    /*Pass this array along with n to the sort() function of part a.*/
		sort(myArray, n);

    /*Print the contents of the array.*/
		printf("Now they are sorted...\n");
		for(i = 0; i < 20; i++)
		{
			printf("%d, ", myArray[i]);
		}

    return 0;
}

