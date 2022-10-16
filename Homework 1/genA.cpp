#include <iostream> 
using namespace std; 

//program is generating a catalan number figured out by writing sequence by hand
// and using Wikipedia to figure out the sequence equation https://en.wikipedia.org/wiki/Catalan_number
unsigned long genA(int n) {
    unsigned long result = 1; 
   //C(n) = (2(n-1) choose (n-1)) 
   /* this part calculates the combinatorial form of equation implemented from sample of N choose K 
   https://www.youtube.com/watch?v=o-ZtGGXLogE */
   for (int i = 0; i < (n-1); ++i){
       result *= ((2 * (n-1)) - i);
       result /= (i + 1);
   }
   //divided the cominatorial by ((n-1+1) as catalan equation is/
	return (result / n); 
}
