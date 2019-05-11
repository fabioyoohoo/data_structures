//
// Created by Frederick Hall on 2019-03-09.
//

#ifndef SORT_MERGE_H
#define SORT_MERGE_H

#include <vector>
#include <iostream>
using namespace std;


// read and write already declared in heap.h

// read - accessing it from the vector to do something (compare)
// write - changing and assigning back to the vector
//int reads = 0;
//int writes = 0;

template <typename Comparable>
void mergeHelper(vector<Comparable> &comp, int start, int end);

template <typename Comparable>
vector<int> merge(vector<Comparable> &comp) {
    cout << "merge sort" << endl;
    printVector(comp);

    // start timer:
    auto start = chrono::high_resolution_clock::now();

    // call the recursive helper function
    mergeHelper(comp, 0, comp.size() -1);
    //cout << "\n" << endl;

    // stop timer
    auto stop = chrono::high_resolution_clock::now();

    // push metrics back to vector
    // store the number of crimes
    vector<int> count;
    count.push_back(comp.size());
    count.push_back(reads);
    count.push_back(writes);
    count.push_back(chrono::duration_cast<chrono::microseconds>(stop - start).count());

    // set counters back to zero
    reads = 0;
    writes = 0;

    return count;
}

template <typename Comparable>
void mergeHelper(vector<Comparable> &comp, int startIndex, int endIndex) {
    // Only look at the part of the vector from startIndex to endIndex

    // Recursive base case: I have one element left
    if (startIndex == endIndex) {
        // There is nothing to split or sort.
        return;
    }

    // Recursive step: split in half and call ourself for left and right halves
    int centerIndex = (startIndex + endIndex) / 2;
    mergeHelper(comp, startIndex, centerIndex);
    mergeHelper(comp, centerIndex + 1, endIndex);

    // Now I can assume that the left and right halves are sorted
    // Merge the two sorted halves together
    vector<Comparable> temp;
    int leftIndex = startIndex;
    int rightIndex = centerIndex + 1;
    while (leftIndex <= centerIndex && rightIndex <= endIndex) {
        // 2 reads regardless of if-statement is true or false below
        reads += 2;
        if (comp[leftIndex] <= comp[rightIndex]) {
            temp.push_back(comp[leftIndex]);
            // 1 read
            reads += 1;
            ++leftIndex;
        } else {
            temp.push_back(comp[rightIndex]);
            // 1 read
            reads += 1;
            ++rightIndex;
        }
    }
    // One of the halves will still have items. Need to finish merging.
    while (leftIndex <= centerIndex) {
        temp.push_back(comp[leftIndex]);
        // 1 read
        reads += 1;
        ++leftIndex;
    }
    while (rightIndex <= endIndex) {
        temp.push_back(comp[rightIndex]);
        // 1 read
        reads += 1;
        ++rightIndex;
    }

    // Copy the sorted list back into the original vector
    for (int i = 0; i < temp.size(); ++i) {
        comp[startIndex + i] = temp[i];
        // 1 write
        writes += 1;
    }

    printVector(comp);
}

#endif //SORT_MERGE_H