
#include <iostream>
using namespace std; 

char findOdd(char arr[], int arr_size) {
    int temp = 0;
    for (int i = 0; i < arr_size; i++)
    //perform bitwise OR and subrtract from bitwise AND, store odd char int value as temp 
        temp = (temp | (int)arr[i]) - (temp & (int)arr[i]); 
    return (char)temp; /* don't forget to change the return value */
}
