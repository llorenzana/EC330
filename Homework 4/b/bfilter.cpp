#include <vector>
#include "bfilter.h"

// (a)

class SillyHashFun : public HashFun {
    unsigned int operator()(const std::string& key) {
        // Here's my silly hash function that always returns 0.
        // You should make some good hash functions and not use this one.
        // This is just an example of how to inherit the HashFun class.
        return 0;
    }
};

class GoodHashFun_0 : public HashFun {
    unsigned int operator()(const std::string& key) {
        // You've seen my silly hash function above.
        // Your good hash function should go here!
        unsigned int ascii_count = 0; 
        for (int i = 0; i < key.length(); i++){
            ascii_count += key[i];
        }

        return ascii_count; // You'll need to change this
    }
};

// ...
// You can make as many hash functions as you want!
// ...

class three30_HashFun : public HashFun {
    unsigned int operator()(const std::string& key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) 
            hash += key[i] * pow(31, i); //31 is a goodchoice for the english language 
        return hash;
    }
};

void BloomFilter::add_hash_funs() {
    // You will need to implement this function, it is responsible
    // for adding your custom hash functions to your bloom filter.
    three30_HashFun *h1 = new three30_HashFun();
    GoodHashFun_0 *h2 = new GoodHashFun_0();
    this->hash_funs.push_back(h1);
    this->hash_funs.push_back(h2);
}

void BloomFilter::insert(const std::string& key) {
    // You will need to implement this function, it is responsible
    // for inserting key into the bloom filter.
    // You'll need to use the results of the hash function to update this->filter
    // Here's an example
    for (int i = 0; i < hash_funs.size(); i++)
        (this->filter)[this->call_hash(i, key) % 330] = 1;
}

bool BloomFilter::member(const std::string& key) {
    // This function should report true if key is potentially in the bloom filter.
    // It should only return false if you know for sure that key is not in the bloom filter.

    //
    // your code here ...
    //
    int count = 0; 
    for(int i = 0; i < hash_funs.size(); i++){ 
        if((this->filter)[this->call_hash(i, key) % 330] == 1)
            count++;
    }

    if (count == hash_funs.size())
        return true; 
    
    return false; // you will need to change this.

}
