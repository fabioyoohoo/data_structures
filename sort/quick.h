//
// Created by Frederick Hall on 2019-03-09.
//

#ifndef SORT_QUICK_H
#define SORT_QUICK_H

template <typename Comparable>
void quickHelper(vector<Comparable> &comp, int start, int end);

template <typename Comparable>
void quick(vector<Comparable> &comp) {
    cout << "quick sort" << endl;
    printVector(comp);
    quickHelper(comp, 0, comp.size() - 1);
    cout << "\n" << endl;
}

template <typename Comparable>
void quickHelper(vector<Comparable> &comp, int startIndex, int endIndex) {
    // The partition element will be at comp[startIndex]
    // We are doing the stable algorithm
    // Store less than, equal, and greater than vectors
    vector<Comparable> less, equal, greater;
    for (int i = startIndex; i <= endIndex; ++i) {
        if (comp[i] < comp[startIndex]) {
            less.push_back(comp[i]);
        } else if (comp[i] > comp[startIndex]) {
            greater.push_back(comp[i]);
        } else {
            equal.push_back(comp[i]);
        }
    }
    // copy the elements back from the temp vectors into comp
    int i = startIndex; // this will index into comp
    for (Comparable& item: less) {
        comp[i] = item;
        ++i;
    }
    for (Comparable& item: equal) {
        comp[i] = item;
        ++i;
    }
    for (Comparable& item: greater) {
        comp[i] = item;
        ++i;
    }

    printVector(comp);

    // Stop recursion when we have 1 or 0 elements
    if (less.size() > 1) {
        // Start at same point, sort only the less elements
        // Need to calculate endIndex from startIndex
        quickHelper(comp, startIndex, startIndex + less.size() - 1);
    }
    if (greater.size() > 1) {
        // Start after the less and equal elements, go until endIndex
        // THE FIX: added startIndex to second argument
        quickHelper(comp, startIndex + less.size() + equal.size(), endIndex);
    }
}

#endif //SORT_QUICK_H
