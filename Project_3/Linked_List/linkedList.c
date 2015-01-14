
/* CS261- Assignment 3- linkedList.c*/
/* Name: Emma Paul
 * Date: October 13, 2013
 * Solution description: This program demonstrates the different methods involving a double linked list
 * 						with a front and back sentinel (initialization, addition, removal, contains)
 * Note: I worked with and completed my homework with Ian Paul
 */


#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink //link variables (value with next and previous pointers)
{
	TYPE value;//value variable to hold value of a link
	struct DLink * next;//next pointer variable to point to the next link
	struct DLink * prev;//previous pointer variable to point to the previous link
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList//linked list variables (size of list as well as a front and back sentinel
{
	int size;//size variable to keep
	struct DLink *frontSentinel;//front sentinel
	struct DLink *backSentinel;//back sentinel
};

/*
	initList
	param list the linkedList
	pre: list is not null
	post: list size is 0
*/

void _initList (struct linkedList *list) {//initialize the linked list structure

   assert(list != 0); //pre: list is not null

   list->frontSentinel = (struct DLink *) malloc(sizeof(struct DLink));//allocate room for front sentinel
   assert (list->frontSentinel != 0);//make sure the allocation worked

   list->backSentinel = (struct DLink *) malloc (sizeof(struct DLink));//allocate room for back sentinel
   assert(list->backSentinel != 0);//make sure allocation worked

   list->frontSentinel->prev = 0;//set the front sentinels previous pointer to 0 (front sentinel always has a null previous pointer)
   //having the front sentinel point to null and then having it's next pointer to the back sentinel is how you connect the two
   list->frontSentinel->next = list->backSentinel; //front sentinel next pointer points to the back sentinel

   list->backSentinel->next = 0;//set the back sentinels's next pointer to 0 (back sentinel always has a null next pointer)
   list->backSentinel->prev = list->frontSentinel;//having the back sentinels previous pointer to the front sentinel
   //completse the double connection going both directions

   list->size = 0;//the list size is set to 0 so that the front and back sentinels are not part of the size of the list
}

/*
 createList
 param: none
 pre: none
 post: frontSentinel and backSentinel reference sentinels
 */

struct linkedList *createLinkedList()//create a linked list
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: list, the linkedList
	param: link, the  link in the list to add before
	param: v the value to add
	pre: list is not null
	pre: link is not null
	post: list is not empty
*/

/* Adds Before the provided link, link */

void _addLinkBefore(struct linkedList *list, struct DLink *link, TYPE v)
{
	 assert(list != 0); //pre: list is not null
	 assert(link != 0); //pre: link is not null

    struct DLink * newLink = (struct DLink *) malloc(sizeof(struct DLink));//allocate memory for a new link
    assert(newLink != 0);//make sure allocation worked

    //it's important to first set the directions of the new link
	newLink->next = link;//newLinks next pointer is set to the link (so it is before the link passed in)
	newLink->prev = link->prev;//the newLinks previous pointer is set to the links previous link
	newLink->value = v;//the new link's value is set to the value v passed in

	//now the the new link's directions are set, the link needs to update it's directions
	link->prev->next = newLink;//the links previous link's next pointer now points to the newLink
	link->prev = newLink;//and the link's previous pointer now poitns to the newLink.

   	list->size++;//once a link has been added, the size is updated
}


/*
	addFrontList
	param: list the linkedList
	param: e the element to be added
	pre: list is not null
	post: list is not empty, increased size by 1
*/

void addFrontList(struct linkedList *list, TYPE e)
{
	assert(list != 0); //pre: list is not null
	_addLinkBefore(list, list->frontSentinel->next, e);//adding a link before the front sentinels next link
	//will add a link to the front of the list after the front sentinel
}

/*
	addBackList
	param: list the linkedList
	param: e the element to be added
	pre: list is not null
	post: list is not empty, increased size by 1
*/

void addBackList(struct linkedList *list, TYPE e)
{
	assert(list != 0); //pre: list is not null
	 _addLinkBefore(list, list->backSentinel, e);//adding a link before the last link adds a link to the back of the list
}

/*
	frontList
	param: list the linkedList
	pre: list is not null
	pre: list is not empty
	post: none
*/

TYPE frontList (struct linkedList *list)
{
	assert(list != 0); //pre: list is not null
	assert(!isEmptyList(list));//pre: list is not empty
    return list->frontSentinel->next->value;//this returns value of the first link that the front sentinel's next points to
}

/*
	backList
	param: list the linkedList
	pre: list is not null
	pre: list is not empty
	post: list is not empty
*/

TYPE backList(struct linkedList *list)
{
	assert(list != 0); //pre: list is not null
	assert(!isEmptyList(list));//pre: list is not empty
	return list->backSentinel->prev->value;//returning the value of the back sentinels previous link is the back of the list
}

/*
	_removeLink
	param: list the linkedList
	param: l the link to be removed
	pre: list is not null
	pre: l is not null
	post: list size is reduced by 1
*/

void _removeLink(struct linkedList *list, struct DLink *l)
{
	assert(list != 0); //pre: list is not null
	assert(l != 0);//pre: l is not null

	l->next->prev = l->prev;//the link to be removed has its next link's previous now point to the removed links previous
	l->prev->next = l->next;//the link to be remove has its previous link's next now point to the removed links next
	free(l);//then you have to free the space the removed link allocated
   	list->size--;//and the list size is reduced by 1
}

/*
	removeFrontList
	param: list the linkedList
	pre:list is not null
	pre: list is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *list)
{
	assert(list != 0); //pre: list is not null
    assert(!isEmptyList(list));//pre: list is not empty
    _removeLink(list, list->frontSentinel->next);//removes the the front link in the list
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *list)
{
	assert(!isEmptyList(list));
	_removeLink(list, list->backSentinel->prev);//removes back link in the list
}

/*
	isEmptyList
	param: list the linkedList
	pre: list is not null
	post: none
*/

int isEmptyList(struct linkedList *list)
{
	return (list->frontSentinel->next == list->backSentinel);//returns true if the front and back sentinel
	//point to eachother so therefore the list is empty
}


/* Function to print list
 Pre: list is not null
 */
void _printList(struct linkedList* list)
{
    struct DLink *link = list->frontSentinel->next;//a link is created to go through the links
	printf("The values in the double linked list are: ");
    while(link != list->backSentinel)//while the link doesn't point to the back sentinel
	{
		printf("%d->", link->value);//print the value of the current link
		link = link->next;//and point the link to the next one to iterate through the list in the while loop
	}

	printf("\n");//then print a new line
}

/*
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
    assert(lst != 0);
	addBackList(lst, v);//adds an item to the bag
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	list		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	list is not null
	pre:	list is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *list, TYPE e)
{
	struct DLink *currentLink;//create a currentLink to iterate through the list
	assert(list != 0);//make sure the list is not null
	assert(!isEmptyList(list));//make sure list is not empty
	currentLink = list->frontSentinel->next; //initiliaze the currentLink to start pointing at the first link after the front sentinel
	while(currentLink != list->backSentinel)//while the current link doesn't point to the back sentinel
	{
		if(EQ(currentLink->value,e))//if the current link's value equals the value e passed in
			return 1;//return true, aka found!
		currentLink = currentLink->next;//and update the current link to point to the next link in the list
	}
	return 0;//if value e not found, return false
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	list	pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	list is not null
	pre:	list is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *list, TYPE e) {

	assert(list != 0);//pre: list is not null
	assert(!isEmptyList(list));//pre: list is not empty
	struct DLink *currentLink;//create a current
	currentLink = list->frontSentinel->next; //Initialize current link to be first link in list
	while(currentLink != list->backSentinel)//while the current link is not the back sentinel
	{
		if(EQ(currentLink->value,e))//if the current link's value equals value e passed in
		{
			_removeLink(list,currentLink);//remove the current link from the list
			break;//break so you only remove one copy of it
		}
		currentLink = currentLink->next;//and update the current pointer to point to the next link
	}
}

