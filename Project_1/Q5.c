/*
 * Q5.c
 *
 *  Created on: Oct 10, 2013
 *      Author: Emma
 */

/* CS261- Assignment 1 - Q.5*/
/* Name: Emma Paul
 * Date: 10/13/2013
 * Solution description: This program askes the user to input a work and then puts every even letter into a capital and every odd into a lowercase so the word is: LiKe ThIs
 * the letters are converted into lower or higher by adding or removing their ASCII letter equivalent
 * Sources used:
 *     http://en.wikipedia.org/wiki/StudlyCaps
 *     http://answers.yahoo.com/question/index?qid=20090811082143AAeb2ls
 *     http://stackoverflow.com/questions/15648531/pointer-and-array-in-c
 *  Note: I worked with and completed my homework with Ian Paul
 */



#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
	if (ch>='a' && ch<='z')
     return ch-'a'+'A';
	else return ch;
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
	if (ch>='A' && ch<='Z')
     return ch-'A'+'a';
	else return ch;
}

void sticky(char* word)
{
     /*Convert to sticky caps*/

	for (int i=0; i < strlen(word); i++)
	{
		if (i % 2 == 0)
		{
			if (word[i] >= 'a' && word[i]<= 'z')
			{
				word[i] = toUpperCase(word[i]);
			}
		}
		else
		{
			if (word[i] >= 'A' && word[i]<= 'Z')
			{
				word[i] = toLowerCase(word[i]);
			}
		}
	}
}

int main(){
    /*Read word from the keyboard using scanf*/
	char word[256];
	char *input;
	input = word;

	printf("Please enter a word to see the craziness:\n");

	scanf("%s", input);



    /*Call sticky*/
	sticky(input);


    /*Print the new word*/
	printf("%s", input);

	for (int i = 0; i <sizeof(input); i++)
	{
		if (input[i] == '\n')
		{
			input[i] = '\0';
			break;
		}
	}

    return 0;
}

