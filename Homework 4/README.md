a) In this problem, you are tasked with sorting a string in increasing order based on the number of occurrences of characters. If there is a tie, output them based on alphabetical order, e.g., ‘a’ before ‘e’. You can assume that all the characters are lower-case letters (so a total of 26 possible types of characters). Below are some example inputs and the corresponding expected outputs.

    Input1: “engineers”
    Output2: “girsnneee”

    Input2: “engineering”
    Output2: “rggiieeennn”

Implement sortByFreq in sorta.cpp. You are allowed to use only the libraries <string> and <vector>. You are welcome to implement your own data structure or use built-in ones like int[]. You cannot use any of the built-in sort functions including those provided by the <algorithm> library and will need to implement your own (you should write this as a separate function and call it from sortByFreq). Submit sorta.cpp on Gradescope. [20 pt] Your code will be graded not only on correctness but also on efficiency. For efficiency consideration, you should expect long string inputs (i.e. large n). [10 pt]
  
 b) We will implement a Bloom filter to check active phishing URLs in this problem.
The files phishing-links-ACTIVE.txt and phishing-links-INACTIVE.txt contain two
sets of phishing URLs obtained from 
        https://github.com/mitchellkrogza/Phishing.Database
Each line in these two files is a URL. We will design a Bloom filter so that the Bloom filter contains the set
of ACTIVE phishing links, and the false positive rate for classifying an
INACTIVE phishing link as ACTIVE is minimized. The file phishing-linksINACTIVE.txt contains 10% of all the INACTIVE links that we will use to test your implementation. The size of the Bloom filter is set to 330. Your Bloom filter
implementation should have a false positive rate strictly less than 30%. Submit
bfilter.cpp on Gradescope. [40 pt]
The submissions that has the lowest false positive rate will get 20 bonus points.
We will consider multiple top submissions if the difference is not significant.
Below are some resources for hash functions that you can use. You are free to use
other hash functions.

        http://www.partow.net/programming/hashfunctions/index.html#AvailableHashFunctions
        https://en.wikipedia.org/wiki/Double_hashing
        http://hashlib2plus.sourceforge.net
