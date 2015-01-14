/*
 * Q4.c
 *
 *  Created on: Oct 10, 2013
 *      Author: Emma
 */

/* CS261- Assignment 1 - Q.4*/
/* Name: Emma Paul
 * Date: October 13, 2013
 * Solution description: This program assigns random scores to 10 id numbers, and then sorts the id numbers based on the scores
 * Note: I worked with and completed my homework with Ian Paul
 */


#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n)
{
     /*Sort the n students based on their score*/
	int i;
	int j;
	struct student studentTemp;


	for (i=0; i<n-1; i++)
	{
		for (j=0; j<n-1-i; j++)
		{
			if (students[j+1].score < students[j].score)
			{ /* compare the two neighbours */
				studentTemp = students[j]; /* swap a[j] and a[j+1] */
				students[j] = students[j+1];
				students[j+1] = studentTemp;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 20;

    /*Allocate memory for n students using malloc.*/
	struct student *students = malloc(sizeof(struct student)*n);

    /*Generate random IDs and scores for the n students, using rand().*/
	//int id;
	//int score;




	 int i;

	     for(i = 0; i<n; i++)
	     {


	    	 students[i].id = i+1;

	     }
	     for(i = 0; i < n; i++)
	     {
	    	 students[i].score = rand()%101;
	     }

    /*Print the contents of the array of n students.*/
	     for(i=0; i<n; i++)
	     {
	    	 printf("ID %d \tScore %d\n", students[i].id, students[i].score );
	     }

    /*Pass this array along with n to the sort() function*/
	     sort(students, n);

    /*Print the contents of the array of n students.*/

	     printf("\n\nThe Sorted scores are:\n\n");

	     for(i=0; i<n; i++)
	    	     {
	    	    	 printf("ID %d \tScore %d\n", students[i].id, students[i].score );
	    	     }

    return 0;
}
