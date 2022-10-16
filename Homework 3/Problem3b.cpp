
#include "ListNode.h"
#include <iostream>
#include <algorithm>

using namespace std;

DListNode* twowayBubble(DListNode* head) {
	
	//Variable Declaration
	bool direction = false, isSorted = false;
	//direction sets whether it is iterating through the left or right
	//false = to the right, true = to the left
	//isSorted checks whether the linked list is sorted
	
	struct DListNode* ptr1;
	ptr1 = head; //set ptr1 to head

    // if the list is empty return NULL
    if (head  == NULL)
        return NULL; 
    
    //if the size of the list is one return head
    if (ptr1->next == NULL && ptr1->prev == NULL)
        return head; 
	
	do {
		isSorted = true; //set isSorted to true in case while loop did not sort
		if(!direction) { //if going to the right
			while(ptr1->next != NULL) { //while not at the end
				if(ptr1->val > ptr1->next->val) { //if left node is greater than right node
					ptr1->val = ptr1->val + ptr1->next->val; //swaps variable by getting the sum (x = x + y) 
					ptr1->next->val = ptr1->val - ptr1->next->val;// calculates the next value (y = x - y)
					ptr1->val = ptr1->val - ptr1->next->val; // performs second part of the swap (x = x - y)
					isSorted = false; //Linked list was sorted to set to false
				}
				ptr1 = ptr1->next; //go to next node
			}
			direction = true; //change direction
		} else {
			while(ptr1->prev != NULL) {
				if(ptr1->val < ptr1->prev->val) { //if right node is less than left node
					ptr1->val = ptr1->val + ptr1->prev->val;//swaps variable by getting the sum (x = x + y) 
					ptr1->prev->val = ptr1->val - ptr1->prev->val;// calculates the next value (y = x - y)
					ptr1->val = ptr1->val - ptr1->prev->val;// performs second part of the swap (x = x - y)
					isSorted = false; 
				}
				ptr1 = ptr1->prev; //go to previous node
			}
			direction = false;
		}
	} while (!isSorted); //do while loop to check at least once

	return head; // don't forget to change this
}
