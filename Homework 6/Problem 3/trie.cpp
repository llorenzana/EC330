//https://www.geeksforgeeks.org/trie-insert-and-search/ - used for basic functions of trie and sample way of implementing 
//https://www.youtube.com/watch?v=XK8MD9N9WUA - logic on how to do remove function through diagrams, provided good visuals
// https://www.techiedelight.com/memory-efficient-trie-implementation-using-map-insert-search-delete/

#include <string>
#include "trie.h"

using namespace std;


void Trie::insert(string key, int val) {

    TrieNode *tempVar = root; 

    for (int i = 0; i < key.length(); i++){ //traverses through whole tree
        int index = key[i] - 'a';

        if (!tempVar->children[index]  ){ // if it doesn't exist yet
            tempVar->children[index] = new TrieNode(); // on the heap 
            tree_size += 1; //increase tree size to account for new node
        }

        tempVar = tempVar->children[index]; //reset so it can traverse from the next node
    }
    if(tempVar->val == 0)
        map_size += 1; //increase map_size

    tempVar->val = val; 
    return;
}

int Trie::search(string key) {
    
    TrieNode *tempVar = root; 
    for (int i = 0; i < key.length(); i++){ //traverses through whole tree
        int index = key[i] - 'a'; 

        if (!tempVar->children[index] )
            return 0; //if empty return 0
        else
            tempVar = tempVar->children[index];
    }

    return (tempVar->val); // return the value of the specifc node 
}

void Trie::remove(string key) {
    TrieNode *tempVar = root; 
    int empty = 0; // used to count number of empty children which is later used to delete node and decrease map and treesize if it is equivalent to the size of the alphabet
    int lengthMin1 = key.length() - 1; // don't want to go through whole tree you want to stop at the node jsut before the one you want to delete

    for (int i = 0; i < lengthMin1; i++){ // traverse through the whole tree - 1 since it didn't work when I ran it throught the whole tree including the node I wanted to delete 
        int index = key[i] - 'a'; 

        if (tempVar->children[index] == 0)
            return; // no need to continue 
        else    
            tempVar = tempVar->children[index]; // set tempVar to be used in the following statements
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) // go through the whole alphabet using predefined const
        if (!tempVar->children[key[lengthMin1] - 'a']->children[i])
            empty += 1;
    
    // size of alphabet then you can delete the node and decrease map and tree size 
    if (empty == ALPHABET_SIZE){ //use predefined const 
        map_size -= 1; // decrease map size
        tree_size -= 1; //decrease tree size 
        tempVar->children[key[lengthMin1] - 'a'] = NULL; // remove node by setting it to NULL
    } 

    else{
        map_size -= 1; //decrease map size
        tempVar->children[key[lengthMin1] - 'a']->val = 0; //set node value to 0
    }
    return; 
}
