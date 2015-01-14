/*
 * cirListDeque.c
 *
 *  Created on: Oct 25, 2013
 *      Author: Emma
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q)
{
  	assert(q != 0);//pre: q is not null
  	q->Sentinel = (struct DLink *) malloc(sizeof(struct DLink));//allocate memory for the sentinel
  	assert(q->Sentinel != 0);//make sure the allocation worked

  	q->Sentinel->next = q->Sentinel;//the sentinels next pointer points to itself
  	q->Sentinel->prev = q->Sentinel;//the sentinels previous pointer points to itself
  	//doing the two lines of code above creates a circularly linked list

  	q->size = 0;//the size is set to zero so the sentinel is not part of the size
}

/*
 create a new circular list deque

 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
    struct DLink *newLink = (struct DLink *) malloc(sizeof(struct DLink));//allocate memory for a new link
    assert(newLink != 0);//make sure the allocation worked
    newLink->value = val;//the new link receives the value passed in
    return newLink;//and the new link is returned
}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	link		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	link is not null
	pre:	link is in the deque
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *link, TYPE v)
{
	assert(q != 0);//pre: q is not null
	assert(link != 0);//pre: link is not null

    struct DLink *newLink = _createLink(v);//new link is created using the _createLink method
    newLink->next = link->next;//the new link's next pointer is set to the link's next that was passed in (so it is after)
    newLink->prev = link;//the new links previous points to the link passed in
    newLink->value = v;//the new links value is set

    link->next->prev = newLink; //now the link's next link's previous points to the new link
    link->next = newLink;//and the link's next points to the new link
    //note: the two lines of code above must be in that order or else the relocation of pointers won't work

    q->size++;//after a link is added the size is updated
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val)
{
	assert(q != 0);//pre: q is not null
	_addLinkAfter(q, q->Sentinel->prev, val);//add link after the sentinels previous link to add to the back of the circle deque
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	assert(q != 0);//pre: q is not null
    _addLinkAfter(q, q->Sentinel, val);//add link after front sentinel
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q)
{
	assert(q != 0);//pre: q is not null
	assert(!isEmptyCirListDeque(q));//pre: q is not empty
	return q->Sentinel->next->value;//returns the value of the front link the sentinels next points to
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	assert(q != 0);//pre: q is not null
	assert(!isEmptyCirListDeque(q));//pre: q is not empty
    return q->Sentinel->prev->value;//returns value of the back link
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	link		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *link)
{
	assert(q != 0);//pre: q is not null
	assert(!isEmptyCirListDeque(q));//pre: q is not empty

	link->next->prev = link->prev;//updates link's next link's previous to point to the links previous
	link->prev->next = link->next;//same for next so that nothing points to link anymore
	free(link);//you have to free the link in memory
   	q->size--;//and decrement the size

}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q)
{
	assert(q != 0);//pre: q is not null
	assert(!isEmptyCirListDeque(q));//pre: q is not empty
	_removeLink(q, q->Sentinel->next);

}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
	assert(q != 0);//pre: q is not null
	assert(!isEmptyCirListDeque(q));//pre: q is not empty
  	_removeLink(q, q->Sentinel->prev);
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	while(q->size > 0)
	{
        _removeLink(q, q->Sentinel->next);//removes all the links (besides the sentinel because it's not part of the size)
	}

}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {

	assert(q != 0);//pre: q is not null

	if(q->size == 0)//if the size equals 0 the list is empty
        return(1);//so it returns true
    else
        return(0);//if not empty return false
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	assert(q != 0);//pre: q is not null
	assert(!isEmptyCirListDeque(q));//pre: q is not empty

	struct DLink* currentLink = q->Sentinel->next;//create a currentLink variable
	assert(currentLink !=0);//make sure allocation worked

    printf("The values starting from the front of the sentinel to  the back of the sentinel are:\n");
	while(currentLink != q->Sentinel)//while the currentLink is not the sentinel
	{
    	printf("%f\n", currentLink->value);//print the value of the currentLink is at
    	currentLink = currentLink->next;//and update currentLink to point to the next link in the deque
	}

}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	//Note: I tried for a long time to figure out how to have a currentLink go through the links and reverse their directions
	//however because the pointers got turned around I could never make anything work
	//and couldn't figure out how to have just one current link so I started thinking I needed a whole new deque
	//and found this method online at: http://stackoverflow.com/questions/12981833/reversing-the-order-of-a-circular-deque-c

	assert(q != 0);//pre: q is not null
	assert(!isEmptyCirListDeque(q));//pre: q is not empty

	struct cirListDeque* newDeque = createCirListDeque();//create a new deque
	assert(newDeque != 0); //make sure allocation worked

    while(!isEmptyCirListDeque(q))//while q is not empty
    {
        addBackCirListDeque(newDeque, backCirListDeque(q));//add the back link of q to the back of the new deque
        removeBackCirListDeque(q);//remove the back link of q
        //as the loop keeps happening back elements push what was the back of q up to the front of the new deque
    }
    q->Sentinel = newDeque->Sentinel;//now q's sentinel needs to be updated to be the new deques sentinel
    q->size = newDeque->size;//size is updated too
    free(newDeque);//now we can free the newDeque becasue the reverse order is stored in q

}

