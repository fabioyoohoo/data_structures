//
// Created by Frederick Hall on 2019-03-09.
//

#ifndef SORT_HEAP_H
#define SORT_HEAP_H

#include <vector>
#include <iostream>
using namespace std;

// establish read and write variables outside of methods

// read - accessing it from the vector to do something (compare)
// write - changing and assigning back to the vector
int reads = 0;
int writes = 0;

// Declare helper
template <typename Comparable>
void percolateDown(vector<Comparable> &comp, int i, int n);


// ** These variable are already declared in merge.h **
// read - accessing it from the vector to do something (compare)
// write - changing and assigning back to the vector

template <typename Comparable>
vector<int> heap(vector<Comparable> &comp) {

    // create counting metrics and storage vector
    vector<int> count;

    // print title and unsorted crimes
    cout << "heap sort" << endl;
    printVector(comp);

    // start timer:
    auto start = chrono::high_resolution_clock::now();

    // build the heap (with max value at root)
    for (int i = comp.size() / 2 - 1; i >= 0; --i) {
        percolateDown(comp, i, comp.size());
    }
    // printVector(comp);

    // keep deleting the max
    for (int j = comp.size() - 1; j > 0; --j) {
        // swap comp[0] and comp[j]
        Comparable temp = comp[0];
        // 1 read
        reads += 1;
        comp[0] = comp[j];
        // 1 read & 1 write
        reads += 1;
        writes += 1;
        comp[j] = temp;
        // 1 write
        writes += 1;

        percolateDown(comp, 0, j);

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
    reads = 0;
    writes = 0;
    return count;
}

inline int leftChild(int i) {
    return 2 * i + 1;
}

// i is the index of the value being percolated down
// n is the number of items in the heap
template <typename Comparable>
void percolateDown(vector<Comparable> &comp, int i, int n) {
    int child;
    Comparable tmp;

    for(tmp = comp[i]; leftChild(i) < n; i = child) {
        // 1 read
        reads += 1;
        child = leftChild(i);
        // choose the child with the larger value
        // 2 reads
        reads += 2;
        if (child != n - 1 && comp[child] < comp[child + 1]) {
            ++child;
        }
        // if the parent is less than the child, swap them
        // 1 read
        reads += 1;
        if (tmp < comp[child]) {
            comp[i] = comp[child];
            // 1 reads 1 write
            reads += 1;
            writes += 1;
        } else {
            // parent is >= both children. nothing more to do.
            break;
        }
    }
    // 1 write
    writes += 1;
    comp[i] = tmp;

}

#endif //SORT_HEAP_H