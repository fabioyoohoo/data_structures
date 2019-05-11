//
// Created by Frederick Hall on 2019-03-09.
//

#ifndef SORT_CRIME_H
#define SORT_CRIME_H


#include <string>
#include <vector>
#include <fstream>
#include <iostream>
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

    // allows Crime objects to use division when called
    friend int operator / (const Crime &crime, int num);

    // allows for Crime objects to be compared with "==", ">" , "<", ">=", and "<="
    friend bool operator == (const Crime &crime1, const Crime &crime2);
    friend bool operator > (const Crime &crime1, const Crime &crime2);
    friend bool operator < (const Crime &crime1, const Crime &crime2);
    friend bool operator >= (const Crime &crime1, const Crime &crime2);
    friend bool operator <= (const Crime &crime1, const Crime &crime2);

};

// function to read in file and stores in vector of objects
void getCrimesFromFile(string filename, vector<Crime> &crimes);

// function to loop through crimes vector and calculate basic age statistics
vector<double> getAgeStats(vector<Crime> crimes, string offense);

// Opens the integer list file and creates a vector of ints with them
void listReader(string filename, vector<int> &lists);

// This method creates a vector of vectors of unsorted crimes that increase by 100 objects
// beginning at 100 and going to 2600.
// These structures are used by each of the sorting algorithms to iterate over and sort
// while recording the reads, writes and time it takes.
vector<vector<Crime>> crimeVector(vector<Crime> crimes);

// outputs a data file to the data folder...
// ** important to create a data folder **
void createDataFiles(vector<vector<int>> data, string filename);

#endif //SORT_CRIME_H
