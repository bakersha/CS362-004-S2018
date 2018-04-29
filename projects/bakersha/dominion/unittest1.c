/*******************************************************
 * Name: unittest1.c
 * Description: unit test suite for getCost() function
 * Author: Sharaya Baker (bakersha) - April 29, 2018
 *******************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(){

	/* Variables */
	
	int testCardNum[30]; 	 // An array to hold all card types plus 3 extra test numbers 
	int i; 					 // For loop counter
	int cost;

	// Array declaration
	for (i = 0; i < 27; i++) // 27 because there are 27 cards the other numbers will be set later
	{
  		testCardNum[i]=i;
  	}

	/* Test 1: Verify return value of every card */
	printf("-------------------------- Starting Test 1 -------------------------\n");
	printf("------ Verifying the return values for every card that exists ------\n");

	for (i = 0; i < 27; i++)
	{
		if (testCardNum[i] == curse || testCardNum[i] == copper)
		{
			cost=0;
		}
		else if (testCardNum[i] == estate || testCardNum[i] == embargo)
		{
			cost=2;
		}
		else if (testCardNum[i] == silver || testCardNum[i] == village || testCardNum[i] == great_hall || 
			testCardNum[i] == steward || testCardNum[i] == ambassador)
		{
			cost=3;
		}
		else if (testCardNum[i] == feast || testCardNum[i] == gardens || testCardNum[i] == remodel || 
			testCardNum[i] == smithy || testCardNum[i] == baron || testCardNum[i] == cutpurse || 
			testCardNum[i] == salvager || testCardNum[i] == sea_hag || testCardNum[i] == treasure_map)
		{
			cost=4;
		}
		else if (testCardNum[i] == duchy || testCardNum[i] == council_room || testCardNum[i] == mine || 
			testCardNum[i] == minion || testCardNum[i] == tribute || testCardNum[i] == outpost)
		{
			cost=5;
		}
		else if (testCardNum[i] == gold || testCardNum[i] == adventurer)
		{
			cost=6;
		}
		else if (testCardNum[i] == province)
		{
			cost=8;
		}
		printf("Cost of card# %d is %d, expected is %d\n", testCardNum[i], getCost(testCardNum[i]), cost);
		assert(getCost(testCardNum[i]) == cost);
	};

	/* Test 2: Check for card type that does not exist */
	printf("-------------------------- Starting Test 2 -------------------------\n");
	printf("------ Verifying the return values for cards that don't exist ------\n");

	cost=-1;			// Expecting all results to be -1 because they are invalid cards
	testCardNum[27]=-1; // Lower boundary
	printf("Cost of card# %d is %d, expected is %d\n", testCardNum[27], getCost(testCardNum[27]), cost);
	assert(getCost(testCardNum[27]) == cost);

	testCardNum[28]=27;	// Upper boundary
	printf("Cost of card# %d is %d, expected is %d\n", testCardNum[28], getCost(testCardNum[28]), cost);
	assert(getCost(testCardNum[28]) == cost);	

	testCardNum[29]=0.5;
	printf("Cost of card# %d is %d, expected is %d\n", testCardNum[29], getCost(testCardNum[29]), cost);
	assert(getCost(testCardNum[29]) == cost);	

	testCardNum[30]='/0';
	printf("Cost of card# %d is %d, expected is %d\n", testCardNum[30], getCost(testCardNum[30]), cost);
	assert(getCost(testCardNum[30]) == cost);	

	/* Test 3: Check return values for card out of order from list and duplicated */
	printf("-------------------------- Starting Test 3 -------------------------\n");
	printf("-- Verifying return values when listed out of order or duplicated --\n");

	testCardNum[0]=copper;			// Cost: 0
	testCardNum[1]=adventurer;		// Cost: 6
	testCardNum[2]=treasure_map;	// Cost: 4
	testCardNum[3]=smithy; 			// Cost: 4
	testCardNum[4]=province;		// Cost: 8
	testCardNum[5]=adventurer;		// Cost: 6

	for (i = 0; i < 6; i++)
	{
		printf("Cost of card# %d is %d, expected is %d\n", testCardNum[i], getCost(testCardNum[i]), cost);
		assert(getCost(testCardNum[i]) == cost);
	}

	printf("\n *~*~*~*~* All tests passed! Testing complete! *~*~*~*~* \n\n");

	return 0;	

}