// header files
#include "age.h"
#include "bubble.h"
#include "Crime.h"
#include "heap.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"
#include "radix.h"
#include "selection.h"
// packages
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<int> numVector1  = {5,33,2,22,1,442,12,1};
    vector<int> numVector2 = numVector1;
    vector<int> numVector3 = numVector2;
    vector<int> numVector4 = numVector2;
    vector<int> numVector5 = numVector2;
    vector<int> numVector6 = numVector2;


    insertion(numVector1);
    bubble(numVector2);
    selection(numVector3);
    quick(numVector4);
    heap(numVector5);
    merge(numVector6);


//    // step 1: create vector and input random crime data
//    vector<Crime> crimes;
//
//    // Load data from randomized file ("average" scenario)
//    getCrimesFromFile("../CRIME_DATA_Random.csv", crimes);
//
//    // step 2: create sub-vectors of increasing length (100,200,300,...)
//    // make vector<vector<Crime>> for each sort to prevent being sorted
//    // and passed (pre-sorted) to another sort
//
//    vector<vector<Crime>> crimeVector1 = crimeVector(crimes);
//    vector<vector<Crime>> crimeVector2 = crimeVector(crimes);
//    vector<vector<Crime>> crimeVector3 = crimeVector(crimes);
//    vector<vector<Crime>> crimeVector4 = crimeVector(crimes);
//    vector<vector<Crime>> crimeVector5 = crimeVector(crimes);
//    vector<vector<Crime>> crimeVector6 = crimeVector(crimes);
//
//    // step 3: loops over vector<vector<Crime>>
//    // and pushes back to vector to record the reads, writes & time
//    // for each sized vector of crimes of each sorting algorithm
//
//        // 1. Bubble
//        // 2. Selection
//        // 3. Merge
//        // 4. Heap
//        // 5. Two-Sort (using age sort that sorts a second time by age)
//        // 6. Radix
//
//    vector<vector<int>> bubbleCounts;
//    for (vector<Crime> crime : crimeVector1) {
//        bubbleCounts.push_back(bubble(crime)); }
//
//    vector<vector<int>> selectionCounts;
//    for (vector<Crime> crime : crimeVector2) {
//        selectionCounts.push_back(selection(crime)); }
//
//    vector<vector<int>> mergeCounts;
//    for (vector<Crime> crime : crimeVector3) {
//        mergeCounts.push_back(merge(crime)); }
//
//    vector<vector<int>> heapCounts;
//    for (vector<Crime> crime : crimeVector4) {
//        heapCounts.push_back(heap(crime)); }
//
//    vector<vector<int>> twoSortCounts;
//    for (vector<Crime> crime : crimeVector5) {
//        twoSortCounts.push_back(age(crime)); }
//
//    // Needs the max length integer as a parameter
//    vector<vector<int>> radixCounts;
//    for (vector<Crime> crime : crimeVector6) {
//        radixCounts.push_back(radix(crime, 7)); }
//
//
//    // step 4: output file for reads, writes, and time for each sort
//    // ** important to have a folder named "data" to put these csv files **
//
//    createDataFiles(bubbleCounts, "bubble");
//    createDataFiles(selectionCounts, "selection");
//    createDataFiles(mergeCounts, "merge");
//    createDataFiles(heapCounts, "heap");
//    createDataFiles(twoSortCounts, "two-sort");
//    createDataFiles(radixCounts, "radix");

    return 0;
}