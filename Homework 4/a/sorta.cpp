#include <string>
#include <vector>
#include "sorta.h"
using namespace std;

// bubble sort a 2D vector without using swap function 
void bubbleSort(int ascii_array[][26])
{
    for (int i = 0; i < 26; i++)    
        for (int j = 0; j < 25-i; j++)
            if (ascii_array[1][j] > ascii_array[1][j+1]){
                //first row swap of ascii values 
                ascii_array[0][j] = ascii_array[0][j+1] + ascii_array[0][j];
                ascii_array[0][j+1] = ascii_array[0][j] - ascii_array[0][j+1];
                ascii_array[0][j] = ascii_array[0][j] - ascii_array[0][j+1];
                //second row swap of frequency count 
                ascii_array[1][j] = ascii_array[1][j+1] + ascii_array[1][j];
                ascii_array[1][j+1] = ascii_array[1][j] - ascii_array[1][j+1];
                ascii_array[1][j] = ascii_array[1][j] - ascii_array[1][j+1];
            }
}

std::string sortByFreq(std::string s) {
    int ascii_array[2][26] = {0}; // create a 2d array 
    std::string newstring(""); 

    //count frequency of character in second row of array
    for (int i = 0; i < s.length(); i++)
        ascii_array[1][int(s[i]) - 97]++;   

    // generate ascii equivalent of each character to match character count 
    for (int i = 0; i < 26 ; i++)
        ascii_array[0][i] = (i + 97);  
    
    //bubble sort array - since 2d array best to use bubble sort 
    bubbleSort(ascii_array); 
    
    //concatenate the string with sequence and store
    for (int i = 0; i < 26; i++){
        for (int j = 0 ; j < ascii_array[1][i] ; j++){
            newstring += char(ascii_array[0][i]);
        }
    }

    return newstring;  // you will need to change this
}
