//
// Created by Frederick Hall on 2019-03-09.
//

#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include <iostream>
#include <vector>
using namespace std;


template <typename Comparable>
vector<int> insertion(vector<Comparable> &comp) {
    cout << "insertion sort" << endl;
    printVector(comp);

    // create counting metrics and storage vector
    vector<int> count;
    int reads = 0;
    int writes = 0;

    // i goes through the indexes of the items to be inserted
    for (int i = 1; i < comp.size(); i++) {
        // store the item to be inserted
        Comparable toBeInserted = comp[i];
        ++reads;
        int currentIndex = i-1;
        while (currentIndex >= 0 && comp[currentIndex] > toBeInserted) {
            // 1 read
            ++reads;
            // slide the larger elements to the right by one index
            comp[currentIndex + 1] = comp[currentIndex];
            // 2 reads 1 write
            ++++reads;
            ++writes;
            --currentIndex;
        }
        // insert the element to the right of where we stopped
        comp[currentIndex + 1] = toBeInserted;
        // 1 write
        ++writes;

        printVector(comp);
    }
    // push metrics back to vector
    // store the number of crimes
    count.push_back(comp.size());
    count.push_back(reads);
    count.push_back(writes);

    return count;
}

#endif //SORT_INSERTION_H