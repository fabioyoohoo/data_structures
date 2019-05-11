//
// Created by Frederick Hall on 2019-03-09.
//

#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H

#include <iostream>
#include <vector>
using namespace std;

//template <typename Comparable>
//void selection(vector<Comparable> &comp);


template <typename Comparable>
vector<int> selection(vector<Comparable> &comp) {

    // create counting metrics and storage vector
    vector<int> count;

    // read - accessing it from the vector to do something (compare)
    // write - changing and assigning back to the vector
    int reads = 0;
    int writes = 0;

    // start timer:
    auto start = chrono::high_resolution_clock::now();

    if (comp.size() > 0) {
        // code for testing selection sort
        cout << "selection sort" << endl;
        printVector(comp);

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
            printVector(comp);
        }
        // spacing
        //cout << "\n" << endl;

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



#endif //SORT_SELECTION_H
