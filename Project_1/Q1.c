/*
 * Q1.c
 *
 *  Created on: Oct 10, 2013
 *      Author: Emma
 */


/* CS261- Assignment 1 - Q.1*/
/* Name: Emma Paul
 * Date: October 13, 2013
 * Solution description: This program generates random ID scores for 10 students, and computes the min, max, and average score
 * Sources used:  http://www.programmingsimplified.com/c/source-code/c-program-find-minimum-element-in-array
 * Note: I worked with and completed my homework with Ian Paul
 */


#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student //struct combines several data values into a single type, the data type is student
{
	int id;
	int score;
};

struct student *allocate();//pre-written, not sure I quite understand this line

struct student* allocate()//return type is a pointer to type student
{
     /*Allocate memory for ten students*/
	struct student *newStuds = malloc(sizeof(struct student)*10); //malloc is memory allocation, this allocates enough memory for 10 students

     /*return the pointer*/
	return newStuds; //doesn't need a * before newStuds but I'm not sure why because I'm still a little confused about pointers
}

void generate(struct student* students)
{
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     int i;

     for(i = 0; i<10; i++)//creates 10 student id's
     {
    	 students[i].id = i+1;//add 1 so first student id is not 0 but rather 1
     }
     for(i = 0; i < 10; i++)//randomly assigns scores to different id's
     {
    	 students[i].score = rand()%101;//tutor helped us with the %101 to make a score of 100 possible
     }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	int i;
	for(i = 0; i<10; i++)
	{
		printf("\tID %d Score %d\n",students[i].id, students[i].score);


	}

}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/

	int min = 100;//min is 100 so we can find minimum scores with for loop
	int max = 0; //max is 0 so we can find max scores with for loop (backwards logic to get the for loop working properly)
	double total = 0;
	double average;
	double n = 10.0;



	for (int i =0; i < 10; i++)
	{
		if (students[i].score <= min)//this if will go through and find the smallest min of the scores
		{
			min = students[i].score;
		}
	}

	for (int i=0; i < 10; i++)
	{
		if (students[i].score >= max)//this if will go through and find the biggest max of the scores
		{
			max = students[i].score;
		}
	}

	for (int i=0; i < 10; i++)
	{
		total += students[i].score;//for loop adds all the total scores and puts value into variable total
	}

	average = total/n;//total is divided by n (10 students) to find the average

	printf("The minimum student score is: %d\n", min);
	printf("The maximum student score is: %d\n", max);
	printf("The average student score is: %f\n", average);

}

void deallocate(struct student* stud)
{
     /*Deallocate memory from stud*/
	free(stud);
}

int main(){
    srand ( time(0) ); //Seed the random number generator so that the program doesn't always generate the same random number
    //got help from the tutor for this

    struct student* stud = 0;

    /*call allocate*/
    stud = allocate();//allocate function is called and the return value from the function is stored into variable stud


    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
}


