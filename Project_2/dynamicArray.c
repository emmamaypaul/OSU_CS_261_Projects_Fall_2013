
/* CS261- Assignment 2 - dynamicArray.c*/
/* Name: Emma Paul
 * Date: October 20, 2013
 * Solution description: This program demonstrates methods involved with a dynamic array (using bag and stack arrays)
 * Note: I worked with and completed my homework with Ian Paul
 * Note: I referenced my workesheet groups answers for my methods below (specifically Henry Wang)
 */

/*	dynamicArray.c: Dynamic Array implementation. */
#include <assert.h>
#include <stdlib.h>
#include "dynamicArray.h"

struct DynArr//below are variables that make up the dynArr structure
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};


/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold cap elements
	post:	v->data is not null
*/


void initDynArr(DynArr *v, int capacity)
{
	assert(capacity > 0);
	assert(v!= 0);
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);//initialize array to size of the capacity passed into method
	assert(v->data != 0);//post condition, v-> data is not null
	v->size = 0;
	v->capacity = capacity;	//capacity is set to the capacity that was passed into method
}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity
			and 0 elements in it.		
*/
DynArr* createDynArr(int cap)
{
	assert(cap > 0);
	DynArr *r = (DynArr *)malloc(sizeof( DynArr));
	assert(r != 0);
	initDynArr(r,cap);
	return r;
}

/* Deallocate data array in dynamic array. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void freeDynArr(DynArr *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void deleteDynArr(DynArr *v)
{
	freeDynArr(v);
	free(v);
}

/* Resizes the underlying array to be the size cap 

	param: 	v		pointer to the dynamic array
	param:	cap		the new desired capacity
	pre:	v is not null
	post:	v has capacity newCap
*/
void _dynArrSetCapacity(DynArr *v, int newCap)//*v = pointer to the dynamic array , newCap is the new desired capacity
{	
	TYPE *newData = malloc(newCap *sizeof (TYPE));//new array with new capacity
	assert (*newData !=0);
	int i;
	for (i=0; i< v->size; i++)
	{
		newData[i] = v->data[i];//copy old array into new array (newData[i])
	}
	free(v->data);//free up old array
	v->data=newData;//v->data (old array) now points to the array that was just made, keeping data name
	v->capacity=newCap;//and the capacity is set to the new capacity
}

/* Get the size of the dynamic array

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	the size of the dynamic array
*/
int sizeDynArr(DynArr *v)
{
	return v->size;
}

/* 	Adds an element to the end of the dynamic array

	param: 	v		pointer to the dynamic array
	param:	val		the value to add to the end of the dynamic array
	pre:	the dynArry is not null
	post:	size increases by 1
	post:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
*/
void addDynArr(DynArr *v, TYPE val)
{
	assert(v !=0);//testing the precondition "the dynArray is not null"

	if(v->size>=v->capacity) //if the size and capacity are the same, ie no more room on array to add another element
		_dynArrSetCapacity(v, 2 *v->capacity);//call method to set capacity twice as big

		v->data[v->size]=val;//the value is added
		v->size++;//the size is incremented so another value can be added next time

}

/*	Get an element from the dynamic array from a specified position
	
	param: 	v		pointer to the dynamic array
	param:	pos		integer index to get the element from
	pre:	v is not null
	pre:	v is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
*/

TYPE getDynArr(DynArr *v, int pos)
{
	assert(v !=0);
	assert(v->size>0);
	assert(pos<v->size && pos>=0);

	if(pos<=v->size)//when the position is less than or equal to the size, therefore an element in the array
	return v->data[pos];//return value stored at index position
}

/*	Put an item into the dynamic array at the specified location,
	overwriting the element that was there

	param: 	v		pointer to the dynamic array
	param:	pos		the index to put the value into
	param:	val		the value to insert 
	pre:	v is not null
	pre:	v is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val
*/
void putDynArr(DynArr *v, int pos, TYPE val)
{
	assert(v !=0);
	assert(v->size>0);
	assert(pos>=0 && pos< v->size);
	if(v->size>=v->capacity)//if the size is the same or bigger than the capacity
	{
		_dynArrSetCapacity(v, 2* v->capacity);//call the set capactiy method passing in arguments to make the capacity twice as big
	}

		v->data[pos]=val;//add the value to the last position in the array
}

/*	Swap two specified elements in the dynamic array

	param: 	v		pointer to the dynamic array
	param:	i,j		the elements to be swapped
	pre:	v is not null
	pre:	v is not empty
	pre:	i, j >= 0 and i,j < size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(DynArr *v, int i, int  j)
{

	assert(v !=0);
	assert(v->size>0);
	assert(i>=0 && j>=0 && i<v->size && j<v->size);

	TYPE temp;//variable (unknown type so uses TYPE, for temporary storage of value to be swapped)
	temp = v->data[i];//temp is equal to pos i
	v->data[i]=v->data[j];//pos i is now equal to position j
	v->data[j]=temp;//pos j now gets changed to equal what I was (stored in temp)

}

/*	Remove the element at the specified location from the array,
	shifts other elements back one to fill the gap

	param: 	v		pointer to the dynamic array
	param:	idx		location of element to remove
	pre:	v is not null
	pre:	v is not empty
	pre:	idx < size and idx >= 0
	post:	the element at idx is removed
	post:	the elements past idx are moved back one
*/
void removeAtDynArr(DynArr *v, int idx)
{

	assert(v !=0);
	assert(v->size>0);
	assert(idx < v->size && idx >= 0);

	int i = idx;
	for (i=idx; i<v->size;i++)//for loop shifts all the elements to the left one (so the top is removed from list)
	{
		v->data[i]=v->data[i+1];
	}
	v->size--;//then the size is decremented after the shift to fill the gap
}



/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/*	Returns boolean (encoded in an int) demonstrating whether or not the 
	dynamic array stack has an item on it.

	param:	v		pointer to the dynamic array
	pre:	the dynArr is not null
	post:	none
	ret:	1 if empty, otherwise 0
*/
int isEmptyDynArr(DynArr *v)
{

	assert(v !=0);
	if(v->size==0)//if there are no elements in the array
	return 1;//return true
	else return 0;//if not empty, return false
}

/* 	Push an element onto the top of the stack

	param:	v		pointer to the dynamic array
	param:	val		the value to push onto the stack
	pre:	v is not null
	post:	size increases by 1
			if reached capacity, capacity is doubled
			val is on the top of the stack
*/
void pushDynArr(DynArr *v, TYPE val)
{
	assert(v !=0);

	if(v->size >= v->capacity)//first make sure if the size is bigger or greater than the capacity
	{
		_dynArrSetCapacity(v, 2 *v->capacity);//if so make the array twice as big
	}
		v->data[v->size]=val;//the value is pushed onto the array
		v->size++;//and the size is incremented so another element can be added
}

/*	Returns the element at the top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the stack
*/
TYPE topDynArr(DynArr *v)
{

	assert(v !=0);
	assert(v->size > 0);
	
	return v->data[v->size-1];//return the top value (must do size -1 since the array index starts at 0)
}

/* Removes the element on top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	size is decremented by 1
			the top has been removed
*/
void popDynArr(DynArr *v)
{

	assert(v !=0);
	assert(v->size>0);
	removeAtDynArr(v, v->size - 1);//call the remove function to remove the last elemetn (which is size -1

}

/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	v		pointer to the dynamic array
	param:	val		the value to look for in the bag
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the bag
*/
int containsDynArr(DynArr *v, TYPE val)
{

	assert(v !=NULL);
	assert(v->size>0);
	
	int i;
	for(i=0; i < v->size; i++)//for loop goes through bag array
	{
		if(EQ(val, v->data[i])) //if the value being passed is found in the array
			return 1;//return true
	}
	return 0;//otherwise return false
	}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	v		pointer to the dynamic array
	param:	val		the value to remove from the array
	pre:	v is not null
	pre:	v is not empty
	post:	val has been removed
	post:	size of the bag is reduced by 1
*/
void removeDynArr(DynArr *v, TYPE val)
{

	assert(v !=0);
	assert(v->size>0);

	int i;
	for(i=0; i < v->size; i++)
	{
		if(EQ(val, v->data[i]))//if the value is found
			removeAtDynArr(v, i);//remove the value at the index it was found
	}
}

