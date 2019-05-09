//
// Created by Frederick Hall on 2019-01-21.
//

#ifndef TREE_CRIME_H
#define TREE_CRIME_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "SplayTree.h"
//template <typename Comparable>

using namespace std;

class Crime {

private:
    string incidentID;
    int age;
    char sex;
    char race;
    string offense;
    string location;
    string weapon;
    string jurisdiction;

public:
    /*
     * Constructor
     */
    Crime();
    Crime(string incidentID, int age, char sex, char race,
          string offense, string location,
          string weapon, string jurisdiction);

    /*
     * Getters
     */
    string getIncidentID() const;
    int getAge() const;
    char getSex() const;
    char getRace() const;
    string getOffense() const;
    string getLocation() const;
    string getWeapon() const;
    string getJurisdiction() const;

    /*
     * Setters
     */
    void setIncidentID(string incidentID);
    void setAge(int age);
    void setSex(char sex);
    void setRace(char race);
    void setOffense(string offense);
    void setLocation(string location);
    void setWeapon(string weapon);
    void setJurisdiction(string jurisdiction);

    /*
     * Overloaded Operators
     */
    // allows Crime objects to print when called
    friend ostream& operator << (ostream& outs,
                                 const Crime &c);

    // allows for Crime objects to be compared with "==", ">" , and "<"
    friend bool operator == (const Crime &crime1, const Crime &crime2);
    friend bool operator > (const Crime &crime1, const Crime &crime2);
    friend bool operator < (const Crime &crime1, const Crime &crime2);

};

// function to read in file and stores in vector of objects
void getCrimesFromFile(string filename, vector<Crime> &crimes);

// function to loop through crimes vector and calculate basic age statistics
vector<double> getAgeStats(vector<Crime> crimes, string offense);

// Opens the integer list file and creates a vector of ints with them
void listReader(string filename, vector<int> &lists);


// function to loop through the 3 trees and record the depth and time it took to find each crime
vector<vector<int>> depthsVector(vector<int> list,  BinarySearchTree<Crime> BST,
                                 AVLTree<Crime> AVL, SplayTree<Crime> *Splay, vector<Crime> crimes);

// Records the time it takes to loop through the 4 integer lists for the 3 trees
// with varying amounts of objects
vector<vector<int>> timer(vector<int> list,  BinarySearchTree<Crime> BST,
                          AVLTree<Crime> AVL, SplayTree<Crime> *Splay, vector<Crime> crimes);

#endif //TREE_CRIME_H
