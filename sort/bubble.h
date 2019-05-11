//
// Created by Frederick Hall on 2019-03-06.
//

#ifndef SORT_BUBBLE_H
#define SORT_BUBBLE_H

#include <iostream>
#include <vector>

using namespace std;

// Construct vectorPrint with template
template<typename T>
void printVector(const vector<T> &vec);


template <typename Comparable>
vector<int> bubble(vector<Comparable> &comp) {

     cout << "bubble sort" << endl;
     printVector(comp);

    // start timer:
    auto start = chrono::high_resolution_clock::now();

    // create counting metrics and storage vector
    vector<int> count;
    // read - accessing it from the vector to do something (compare)
    // write - changing and assigning back to the vector
    int reads = 0;
    int writes = 0;

    // boolean to keep track of if program should still run
    bool madeSwaps = true;
    int numSorted = 0;
    while (madeSwaps) {
        madeSwaps = false;
        // moves over vector from the beginning
        for (int i = 0; i + 1 < comp.size() - numSorted; ++i) {
            // 2 reads
            reads += 2;
            if (comp[i] > comp[i+1]) {
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
        // Print after each pass through the vector
        // only works for vectors containing
        printVector(comp);
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

template<typename T>
void printVector(const vector<T> &vec) {
    for (const T &item : vec) {
        //cout << item << ", ";
        // specific for Crimes to print out Incident ID
        cout << item << ", ";
        //cout << item.getIncidentID() << ", ";
    }
    cout << endl;
}

#endif //SORT_BUBBLE_H