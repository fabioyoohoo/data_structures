//
// Created by Frederick Hall on 2019-03-12.
//

#ifndef SORT_AGE_H
#define SORT_AGE_H

#include <vector>
#include <iostream>
using namespace std;


template <typename Comparable>
vector<int> age(vector<Comparable> &comp) {

    // create counting metrics and storage vector
    vector<int> count;
    // read - accessing it from the vector to do something (compare)
    // write - changing and assigning back to the vector
    int reads = 0;
    int writes = 0;

    // start timer:
    auto start = chrono::high_resolution_clock::now();


    // Sort 1. Selection Sort
        if (comp.size() > 0) {
            // code for testing selection sort
            //cout << "selection sort" << endl;
            //printVector(comp);

            for (int minIndex = 0; minIndex < comp.size() - 1; ++minIndex) {
                int currentMin = minIndex;
                for (int i = minIndex + 1; i < comp.size(); ++i) {
                    // check if this is the new minimum
                    // 2 reads
                    reads += 2;
                    if (comp[i] < comp[currentMin]) {
                        currentMin = i;
                    }
                }
                if (currentMin != minIndex) {
                    // swap the minimum into place
                    Comparable temp = comp[currentMin];
                    // 1 read
                    reads += 1;
                    comp[currentMin] = comp[minIndex];
                    // 2 reads & 1 write
                    reads += 1;
                    writes += 1;
                    // 1 write
                    comp[minIndex] = temp;
                    // 1 write
                    writes += 1;
                }
                //printVector(comp);
            }
            // spacing
            //cout << "\n" << endl;

        }

    // Sort 2. Bubble Sort (stable)

    // boolean to keep track of if program should still run
    bool madeSwaps = true;
    int numSorted = 0;

    while (madeSwaps) {
        madeSwaps = false;
        // moves over vector from the beginning
        for (int i = 0; i + 1 < comp.size() - numSorted; ++i) {
            // 2 reads
            reads += 2;
            if (comp[i].getAge() > comp[i+1].getAge()) {

                // We need to swap the elements
                Comparable temp = comp[i];
                // 1 read
                reads += 1;

                comp[i] = comp[i+1];
                // 1 read & 1 write
                reads += 1;
                writes += 1;

                comp[i+1] = temp;
                // 1 write
                writes += 1;
                madeSwaps = true;
            }
        }
        ++numSorted;
    }

    // stop timer
    auto stop = chrono::high_resolution_clock::now();

    // push metrics back to vector

    // store the number of crimes
    count.push_back(comp.size());
    count.push_back(reads);
    count.push_back(writes);
    count.push_back(chrono::duration_cast<chrono::microseconds>(stop - start).count());

    return count;
}


#endif //SORT_AGE_H
