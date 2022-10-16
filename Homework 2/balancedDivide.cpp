
#include "balancedDivide.h"
#include <bits/stdc++.h>

using namespace std; 

Assignment balancedDivide(std::vector<int> const &birthdays) {
    int size = birthdays.size(); 
    vector<int> sortedBirth = birthdays; 
    vector<int> subset1;
    vector<int> subset2;

    // if size is one return a vector with zero and a vector with the value 
    if (size == 1) { 
        subset1.push_back(birthdays[0]);
        return  Assignment(birthdays[0], subset1, subset2);
    }

    sort(sortedBirth.begin(), sortedBirth.end());

    int totalSum = 0; 
    for (int i = 0; i < size ; i++)    // calculate the sum of the array 
        totalSum += sortedBirth[i]; 
    
    // used this video to figure out difference using dp table https://www.youtube.com/watch?v=FB0KUhsxXGY
    // code for dp table from video and implementedhttps://gist.github.com/SuryaPratapK/ef15fe6e21f7184f152e6dd65c20a46a used this
    bool dp[size + 1][totalSum + 1];
    for(int i=0; i <= size; ++i){
        for(int j = 0 ;j <= totalSum; ++j){
            if(j==0)
                dp[i][j] = true;
            else if(i==0)
                dp[i][j] = false;
            else if(sortedBirth[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i - 1][j - sortedBirth[ i - 1]];
        }
    }

    int difference = INT_MAX;
    for(int i = 0 ;i <= (totalSum/2) ;++i){
        int first = i;
        int second = totalSum - i;
        if(dp[size][i]==true and difference>abs(first-second))
            difference = abs(first-second);
    }
    


    int halfSum = (totalSum - difference) / 2; 
    int twoSum = halfSum + difference;
    int runningSum = 0; 
    difference = abs(halfSum- twoSum);


  if (difference > 0){
        for (int i = 0; i < size-1; i++){ 
            runningSum = runningSum + sortedBirth[i] + sortedBirth[(size - 1 - i)]; 
            if( sortedBirth[(size-1-i)] == twoSum || sortedBirth[(size-1-i)] == halfSum){ 
                subset1.push_back(sortedBirth[(size-1-i)]);
                break;
            }
            if (runningSum <= halfSum  || runningSum <= twoSum){ 
                subset1.push_back(sortedBirth[i]);
                subset1.push_back(sortedBirth[size-1-i]);
            }
            if (runningSum > twoSum){ 
                subset1.push_back(sortedBirth[i]);
                runningSum -= sortedBirth[size-1-i];
            }

            if (runningSum == halfSum || runningSum == twoSum)
                break; 
        }

        for (int i = 0; i < size; i++) {
            bool isValid = true;
            for (int j = 0; j < subset1.size(); j++) { 
                if (sortedBirth[i] == subset1[j]){
                    isValid = false; 
                    break;
                }
            }
            if (isValid == true)
                subset2.push_back(sortedBirth[i]);
        }
     }


        // Boolean DP table to calculate the equal sum partitioned arrays 
       else{
        bool dp[size + 1][halfSum + 1];
        for (int i = 1; i <= halfSum; i++)
            dp[0][i] = false;
        for (int i = 0; i <= size; i++)
            dp[i][0] = true;
        for (int i = 1; i <= size; i++) {
            for (int runSum = 1; runSum <= halfSum; runSum++) {
                dp[i][runSum] = dp[i - 1][runSum];
                if (sortedBirth[i - 1] <= runSum)
                    dp[i][runSum] = dp[i][runSum] |
                    dp[i - 1][runSum - sortedBirth[i - 1]];
            }
        }
        int i = sortedBirth.size();
        runningSum = halfSum;

        //adds proper elements to each subset
        while (i > 0 && runningSum >= 0) {
            if (dp[i - 1][runningSum]) {
                i--;
                subset2.push_back(sortedBirth[i]);
            }

            else if (dp[i - 1][runningSum - sortedBirth[i - 1]]) {
                i--;
                runningSum -= sortedBirth[i];
                subset1.push_back(sortedBirth[i]);
            }
        }
    }

    return  Assignment(difference, subset1, subset2); // Don't forget to change this
}
