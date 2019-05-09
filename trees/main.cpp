#include <iostream>

#include "Crime.h"
#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <chrono>

int main() {
    // Create vector of crimes
    vector<Crime> crimes;

    // Load data from randomized file ("average" scenario)
    getCrimesFromFile("../CRIME_DATA_Random.csv", crimes);

    // Load data from ordered file ("worst-case" scenario)
    //getCrimesFromFile("../CRIME_DATA.csv", crimes);

    // ADD 3 DUMMY OBJECTS TO CRIME VECTOR:
    crimes.push_back(Crime("1111111", 17, 'W', 'W', "Espionage", "Parking Lot", "The Russians", "BURLINGTON"));
    crimes.push_back(Crime("2222222", 54, 'M', 'W', "Mischief", "Taco Bell", "Hackysack", "BURLINGTON"));
    crimes.push_back(Crime("3333333", 47, 'M', 'W', "Simple Assault", "Residence", "Personal Weapon", "BURLINGTON"));

    // Tester to see if crimes were added to Crimes vector
    /*for (int i = crimes.size()-1; i >= (crimes.size() - 3); i--){
        cout << crimes[i] << endl;
    }
    */

    // READ IN LISTS AND CREATE VECTORS:
    vector<int> listRandom;
    listReader("../listRandom.csv", listRandom);
    int testA = listRandom[0];
    // Testing Expected Output: 914
    cout << testA << endl;

    vector<int> listSorted;
    listReader("../listSorted.csv", listSorted);
    int testB = listSorted[5];
    // Testing Expected Output: 5
    cout << testB << endl;

    vector<int> listFive;
    listReader("../listFive.csv", listFive);
    int testC = listFive[5];
    // Testing Expected Output: 1
    cout << testC << endl;

    vector<int> listReverse;
    listReader("../listReverse.csv", listReverse);
    int testD = listReverse[5];
    // Testing Expected Output: 2644
    cout << testD << endl;

    // ADD CRIMES TO TREES
    // Making sure not to add the Dummy Crimes

    // BST
    BinarySearchTree<Crime> BST;
    for (int i = 0; i < 2647; i++) {
        BST.add(crimes[i]);
        // tester to ensure 0 through 2646 are added
        // cout << i << endl;
    }
    // AVL
    AVLTree<Crime> AVL;
    for (int i = 0; i < 2647; i++) {
        AVL.add(crimes[i]);
        // tester to ensure 0 through 2646 are added
        // cout << i << endl;
    }
    // Splay
    SplayTree<Crime> Splay;
    for (int i = 0; i < 2647; i++) {
        Splay.add(crimes[i]);
        // tester to ensure 0 through 2646 are added
        //cout << i << endl;
    }

    // Read in the Crime from each of the four list files (random, sorted, five, reverse)
    // Visit the correct node for that crime in each tree (BST, AVL, Splay)
    // Store the depth and time it takes to visit each crime in a vector
    // The timer function (below) is used in the analysis as it accounts for splaying and balancing time
    vector<vector<int>> depthsFive = depthsVector(listFive, BST, AVL, &Splay, crimes);
    vector<vector<int>> depthsRandom = depthsVector(listRandom, BST, AVL, &Splay, crimes);
    vector<vector<int>> depthsSorted = depthsVector(listSorted, BST, AVL, &Splay, crimes);
    vector<vector<int>> depthsReverse = depthsVector(listReverse, BST, AVL, &Splay, crimes);

    // Output above vectors to three separate csv files
    ofstream fileOut;

    // Header vector for each csv file
    vector<string> headers = {"n","bst", "avl", "splay","bstTime","avlTime", "splayTime"};

    // create/open Random file
    fileOut.open ("../depthsRandom.csv");
    // populate headers in file
    for (string name : headers) {
        fileOut << name;
        fileOut << ","; }
    fileOut << "\n";
    // loop through the depths vector
    for (vector<int> row : depthsRandom) {
        for (int point : row) {
            fileOut << point;
            fileOut << ",";
        }
        fileOut << "\n";
    }
    // close file
    fileOut.close();

    // create/create Five file
    fileOut.open ("../depthsFive.csv");
    // populate headers in file
    for (string name : headers) {
        fileOut << name;
        fileOut << ",";
    }
    fileOut << "\n";
    // loop through the depths vector
    for (vector<int> row : depthsFive) {
        for (int point : row) {
            fileOut << point;
            fileOut << ",";
        }
        fileOut << "\n";
    }
    // close file
    fileOut.close();

    // create/open Sorted file
    fileOut.open ("../depthsSorted.csv");
    // populate headers in file
    for (string name : headers) {
        fileOut << name;
        fileOut << ",";
    }
    fileOut << "\n";
    // loop through the depths vector
    for (vector<int> row : depthsSorted) {
        for (int point : row) {
            fileOut << point;
            fileOut << ",";
        }
        fileOut << "\n";
    }
    // close file
    fileOut.close();

    // create/open Reverse file
    fileOut.open ("../depthsReverse.csv");
    // populate headers in file
    for (string name : headers) {
        fileOut << name;
        fileOut << ",";
    }
    fileOut << "\n";
    // loop through the depths vector
    for (vector<int> row : depthsReverse) {
        for (int point : row) {
            fileOut << point;
            fileOut << ",";
        }
        fileOut << "\n";
    }
    // close file
    fileOut.close();


    // Method for creating vectors full of timer data
    // call method and create v
    vector<vector<int>> timeSorted = timer(listSorted, BST, AVL, &Splay, crimes);
    vector<vector<int>> timeFive = timer(listFive, BST, AVL, &Splay, crimes);
    vector<vector<int>> timeRandom = timer(listRandom, BST, AVL, &Splay, crimes);
    vector<vector<int>> timeReverse = timer(listReverse, BST, AVL, &Splay, crimes);


    // Header for time files
    vector<string> timeHeader = {"nodes, bstTime, avlTime, splayTime"};

    // create/open timeSorted file
    fileOut.open ("../timeSorted.csv");
    // populate headers in file
    for (string name : timeHeader) {
        fileOut << name;
        fileOut << ",";
    }
    fileOut << "\n";
    // insert timer data
    for (vector<int> row : timeSorted) {
        for (int point : row) {
            fileOut << point;
            fileOut << ",";
        }
        fileOut << "\n";
    }
    // close file
    fileOut.close();

    // create/open timeFive file
    fileOut.open ("../timeFive.csv");
    // populate headers in file
    for (string name : timeHeader) {
        fileOut << name;
        fileOut << ",";
    }
    fileOut << "\n";
    // insert timer data
    for (vector<int> row : timeFive) {
        for (int point : row) {
            fileOut << point;
            fileOut << ",";
        }
        fileOut << "\n";
    }
    // close file
    fileOut.close();

    // create/open timeRandom file
    fileOut.open ("../timeRandom.csv");
    // populate headers in file
    for (string name : timeHeader) {
        fileOut << name;
        fileOut << ",";
    }
    fileOut << "\n";
    // insert timer data
    for (vector<int> row : timeRandom) {
        for (int point : row) {
            fileOut << point;
            fileOut << ",";
        }
        fileOut << "\n";
    }
    // close file
    fileOut.close();

    // create/open timeReverse file
    fileOut.open ("../timeReverse.csv");
    // populate headers in file
    for (string name : timeHeader) {
        fileOut << name;
        fileOut << ",";
    }
    fileOut << "\n";
    // insert timer data
    for (vector<int> row : timeReverse) {
        for (int point : row) {
            fileOut << point;
            fileOut << ",";
        }
        fileOut << "\n";
    }
    // close file
    fileOut.close();

    // Graphing Options for Analysis
    // R: ggplot (geom_freqpoly, geom_historgram, geom_line, geom_point)
    // Python: numpy, matplotlib, jupiter notebooks (mathmatica)

    return 0;
}