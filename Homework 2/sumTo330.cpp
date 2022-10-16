
// your includes here
#include<bits/stdc++.h>
using namespace std; 


int sumTo330(vector<int> nums) {
    //sort array into ascending order to get sum values easier
    sort(nums.begin(), nums.end()); 
    // generate result as a max value for sake of first comparison and change later on
    int result = INT_MAX;
    //the sum of the current elements being tested
    int currentSum = 0; 
    for (int i = 0; i < nums.size() ; i++) {
        int element2 = i + 1; //resets for each i value after while loop has run completely
        int element3 = nums.size() - 1; //resets before each while loop run
        //loops through all possible combinations of each element i the remaining elements until closest
        //if the value is not close then increases i and searches through those possibilities
        while (element2 < element3) {
            //sums the current element, element, and the greatest element since the array is sorted into asceding order
            currentSum = nums[i] + nums[element2] + nums[element3] ;
            if (330 == result)
                return result; 
            if( fabs(330 - currentSum) < fabs(330 - result))
                result = currentSum; // set result to current sum if closer to 330
            if ( 330 < result) 
                element3 -= 1; //move last point to the left since result is greater than 330
            else 
                element2 += 1; // increase second element for continuous running 
        }
    }
    return result;
}
