//
// Created by Frederick Hall on 2019-03-20.
//

#ifndef SORT_RADIX_H
#define SORT_RADIX_H

#include <vector>
#include <iostream>


template <typename Comparable>
vector<int> radix(vector<Comparable> &comp, int numDigits) {

    // create counting metrics and storage vector
    vector<int> count;

    // read - accessing it from the vector to do something (compare)
    // write - changing and assigning back to the vector
    int reads = 0;
    int writes = 0;

    // start timer:
    auto start = chrono::high_resolution_clock::now();

    // Need a bucket for each digit
    vector<vector<Crime>> buckets;
    buckets.resize(10);
    // Loop numDigits times
    int divisionDenominator = 1;
    for (int i = 0; i < numDigits; ++i) {
        // Place each item from comp in its appropriate bucket
        for (int index = 0; index < comp.size(); ++index) {
            int digit = (comp[index] / divisionDenominator) % 10;
            reads += 1;
            buckets[digit].push_back(comp[index]);
            reads += 1;
        }
        divisionDenominator *= 10;
        // Loop through each bucket and place the items back into comp
        int compIndex = 0;
        for (int bucket = 0; bucket < buckets.size(); ++bucket) {
            for (Crime c : buckets[bucket]) {
                comp[compIndex] = c;
                writes += 1;
                ++compIndex;
            }
            buckets[bucket].clear();
        }
        //printVector(comp);
    }
    // stop timer
    auto stop = chrono::high_resolution_clock::now();

    // push metrics back to vector
    // store the number of crimes
    count.push_back(comp.size());
    count.push_back(reads);
    count.push_back(writes);
    count.push_back(chrono::duration_cast<chrono::microseconds>(stop - start).count());

    // set counters back to zero
    return count;
}


#endif //SORT_RADIX_H
