/*
 * hashMap.c
 *
 *  Created on: Nov 25, 2013
 *      Author: Emma
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"

/*
 *
struct hashLink {
   KeyType key; //the key is what you use to look up a hashLink
   ValueType value; //the value stored with the hashLink, a pointer to int in the case of concordance
   struct hashLink * next; //notice how these are like linked list nodes
//};

typedef struct hashLink hashLink;


struct hashMap {
    hashLink ** table; array of pointers to hashLinks
    int tableSize; number of buckets in the table
    int count; number of hashLinks in the table
};
typedef struct hashMap hashMap;
*/
int compare( KeyType left, KeyType right )//compares two values passed in
{
	int returnVal = strcmp(left, right);
	//printf("Compare return value %d\n", returnVal);
	return returnVal;//returns -1 if left is bigger and 0 if they are the same, 1 if right is bigger
}
/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{
	/*write this*/
	int i;
	for (i = 0; i < ht->tableSize; i++)
	{
		hashLink * currentLink = ht->table[i];

		while(currentLink != NULL)
		{
			hashLink * temp = currentLink->next;
//			free(currentLink->value); don't have to free value beacsue it's an int
			free(currentLink->key);
			free(currentLink);
			currentLink = temp;//do they get the values and key associated with the current link???????????????
		}
	}
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/*
Resizes the hash table to be the size newTableSize
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	printMap(ht);
	/*write this*/
	hashLink **tempTable = ht->table; //new temp table equal to table passed in
	int tempSize = ht->tableSize; //new temp equal to size of hash tavle

	_initMap(ht, newTableSize); //create table twice as big

	int i;
	for(i = 0; i < tempSize; i++)
	{
		hashLink *currentLink = tempTable[i];
		while( currentLink != NULL )
		{
			insertMap(ht, currentLink->key, currentLink->value );
			hashLink * temp = currentLink->next;
			currentLink = temp;
		}
	}
	printf("End of _setTableSize\n");
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".

 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.

 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{
	/*write this*/
//	printf("inserting value %d at key %s\n", v, k);
	if((ht->count / (double)ht->tableSize) > 0.75) //monitor load factor (0.75)
	{
	//	printf("About to double the size\n");
		_setTableSize(ht, ht->tableSize * 2);//resize twice as big if necessary
	}
	ht->count++; //add to count

	 int index = stringHash2(k) % ht->tableSize;

	 hashLink ** currentLink = &ht->table[index];

	 while(*currentLink != NULL)//while there is a link at the index
	 {
	//	 printf("Already a link at the index, other key = %s\n", (*currentLink)->key);
		 currentLink = &(*currentLink)->next; //go to the next link
	 }
		//when you have gotten here there isn't a next link in the chain
	 struct hashLink * newLink = (struct hashLink *) malloc(sizeof(struct hashLink));//allocate memory for a new link
	 assert(newLink != 0);//make sure allocation worked
	 newLink->key = k;
	 newLink->value = v;//new link gets value passed in
	 newLink->next = NULL;
	 *currentLink = newLink; //current link now points to new link which has value passed in

}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.

 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.

 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k)
{
	/*write this*/
	//printf("print at map called with the key %s\n", k);
	int index = stringHash2(k) % ht->tableSize;
	hashLink * currentLink = ht->table[index];
	while(currentLink != NULL)
	{
		//printf("about to compare\n");
		if(compare(k, currentLink->key)==0)//does the compare return 0, if so how???
		{
			//printf("conpare worked\n");
			return &currentLink->value;
		}
		currentLink = currentLink->next;
	}
	return NULL;
}

/*
 a simple yes/no if the key is in the hashtable.
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{
	/*write this*/
	if (atMap(ht, k) == NULL)
		return 0; //not found
	return 1;
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{
	/*write this*/

	//if(compare(k, currentLink->key)==0)
	if(containsKey(ht, k) == 1)//if the key is found we know we need to remove it
	{
		 int idx = stringHash2(k) % ht->tableSize;
		hashLink * currentLink = ht->table[idx];//hashlink (temp) set to bucket index of array
		hashLink * tempLink = ht->table[idx]; //need temp for updating link pointers after removal of currentlink
		if(strcmp(currentLink->key, k) == 0)//while the key isn't equal to the key passed in
		{
			ht->table[idx] = currentLink->next;
			free(currentLink);
			return;
		}
		while(strcmp(currentLink->key, k) != 0)//while the key isn't equal to the key passed in
		{
			tempLink = currentLink; //update temp link to equal the current
			currentLink = currentLink->next; //and the current to be the next link in the line
		}
		//when we jump out of the while loop we know the current link's key is equal to the key passed in
		tempLink->next = currentLink->next; //update temp Link to have it's next be current links next
		//so that when currentLink is removed the links are still connected
		free(currentLink);
	}
	else
	{
		printf("The key %s can't be found.", k);

	}

}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{
	/*write this*/
	return ht->count;//size is equal to number of elements (links) in the hash table
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{
	/*write this*/
	return ht->tableSize; //table size is number of buckets
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{
	/*write this*/
	int idx; //start looking at first element
	int count = 0;
	for(idx = 0; idx < ht->tableSize; idx++)
	{
		if(ht->table[idx] == NULL)//trying to point to the links (which is ht->table) # of buckets
		{
			count++;//if no buckets (empty), add to count
		}
	}
	return count;//return number of empty buckets
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)

 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{
	/*write this*/
	float load = (float)ht->count / ht->tableSize;

	return load;
}
void printMap (struct hashMap * ht)
{
	int i;
	struct hashLink *temp;
	for(i = 0;i < capacity(ht); i++)
	{
		temp = ht->table[i];
		if(temp != 0)
		{
			printf("\nBucket Index %d -> ", i);
		}
		while(temp != 0)
		{
			printf("Key:%s|", temp->key);
			printValue(temp->value);
			printf(" -> ");
			temp=temp->next;
		}
	}
}


