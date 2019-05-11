//
// Created by Frederick Hall on 2019-03-09.
//

#include "Crime.h"
#include <iomanip>
#include <sstream>
using namespace std;

// default class
Crime::Crime() {
    incidentID = "12345";
    age = 44;
    sex = 'M';
    race = 'W';
    offense = "Aggravated Assault";
    location = "Drug Store/Doctor\'s Office/Hospital";
    weapon = "Knife/Cutting Instrument";
    jurisdiction = "Burlington";
}

Crime::Crime(string incidentID, int age, char sex, char race,
             string offense, string location,
             string weapon, string jurisdiction) {
    this->incidentID = incidentID;
    this->age = age;
    this->sex = sex;
    this->race = race;
    this->offense = offense;
    this->location = location;
    this->weapon = weapon;
    this->jurisdiction = jurisdiction;
}

/*
 * Getters
 */
string Crime::getIncidentID() const {
    return incidentID;
}
int Crime::getAge() const {
    return age;
}
char Crime::getSex() const {
    return sex;
}
char Crime::getRace() const {
    return race;
}
string Crime::getOffense() const {
    return offense;
}
string Crime::getLocation() const {
    return location;
}
string Crime::getWeapon() const {
    return weapon;
}
string Crime::getJurisdiction() const {
    return jurisdiction;
}

/*
 * Setters
 */
void Crime::setIncidentID(string incidentID) {
    this->incidentID = incidentID;
}
void Crime::setAge(int age) {
    this->age = age;
}
void Crime::setSex(char sex) {
    this->sex = sex;
}
void Crime::setRace(char race) {
    this->race = race;
}
void Crime::setOffense(string offense) {
    this->offense = offense;
}
void Crime::setLocation(string location) {
    this->location = location;
}
void Crime::setWeapon(string weapon) {
    this->weapon = weapon;
}
void Crime::setJurisdiction(string jurisdiction) {
    this->jurisdiction = jurisdiction;
}

/*
 * Overloaded Operators: Crime Objects
 */

// overloading << to print formatted object
ostream& operator << (ostream& outs, const Crime &c){
    outs << setw(13) << left << c.getIncidentID();
    outs << setw(6) << c.getAge();
    outs << setw(6) << c.getSex();
    outs << setw(6) << c.getRace();
    outs << setw(38) << c.getOffense();
    outs << setw(22) << c.getLocation();
    outs << setw(25) << c.getWeapon();
    outs << setw(25) << c.getJurisdiction();

    return outs;
}

// allows Crime objects to use division when called
int operator / (const Crime &crime, int num) {
    string incidentID = crime.getIncidentID();
    // converting string to int
    int incident1 = stoi(incidentID);
    return incident1/num;
}


// overloading equals operator to check for same Crime object
bool operator == (const Crime &crime1, const Crime &crime2) {
    string incidentID1 = crime1.getIncidentID();
    string incidentID2 = crime2.getIncidentID();
    if (incidentID1 == incidentID2) {
        return true;
    }
    else { return false; }
}

// Source: Converting Strings to Numbers C/C++
// Used this source to find the built in method stoi()
// https://www.geeksforgeeks.org/converting-strings-numbers-cc/

// overloading greater than operator
bool operator > (const Crime &crime1, const Crime &crime2) {
    string incidentID1 = crime1.getIncidentID();
    string incidentID2 = crime2.getIncidentID();
    // converting string to int
    int incident1 = stoi(incidentID1);
    int incident2 = stoi(incidentID2);

    if (incident1 > incident2) {
        return true;
    }
    else {return false; }
}

// overloading less than operator
bool operator < (const Crime &crime1, const Crime &crime2) {
    string incidentID1 = crime1.getIncidentID();
    string incidentID2 = crime2.getIncidentID();
    // converting string to int
    int incident1 = stoi(incidentID1);
    int incident2 = stoi(incidentID2);

    if (incident1 < incident2) {
        return true;
    }
    else {return false; }
}
// overloading greater than or equal to operator
bool operator >= (const Crime &crime1, const Crime &crime2) {
    string incidentID1 = crime1.getIncidentID();
    string incidentID2 = crime2.getIncidentID();
    // converting string to int
    int incident1 = stoi(incidentID1);
    int incident2 = stoi(incidentID2);

    if (incident1 >= incident2) {
        return true;
    }
    else {return false; }
}
// overloading less than or equal to operator
bool operator <= (const Crime &crime1, const Crime &crime2) {
    string incidentID1 = crime1.getIncidentID();
    string incidentID2 = crime2.getIncidentID();
    // converting string to int
    int incident1 = stoi(incidentID1);
    int incident2 = stoi(incidentID2);

    if (incident1 <= incident2) {
        return true;
    }
    else {return false; }
}

// as the name suggests...
// reading file and populating the vector
void getCrimesFromFile(string filename,
                       vector<Crime> &crimes) {
    // Create an input file stream
    ifstream fileIn;
    // Open the file
    fileIn.open(filename);
    // Declare variables
    int age = 0;
    char sex, race;
    string incidentID = "", offense = "", location = "", weapon = "", jurisdiction = "";
    char comma;

    // Make sure the stream is ready to read
    // And it is not at the end of file (EOF)
    while (fileIn && fileIn.peek() != EOF) {

        // Read incidentID
        getline(fileIn, incidentID, ',');
        // fix start line indentation char by removing white space
        while(!isalnum(incidentID[0])) {
            incidentID = incidentID.substr(1, incidentID.length());}

        // Read age
        fileIn >> age;
        fileIn >> comma;

        // Read sex
        fileIn >> sex;
        fileIn >> comma;

        // Read race
        fileIn >> race;
        fileIn >> comma;

        // Read offense
        getline(fileIn, offense, ',');

        // Read location
        getline(fileIn, location, ',');

        // Read weapon
        getline(fileIn, weapon, ',');

        // Read jurisdiction
        getline(fileIn, jurisdiction, '\n');

        // get rid of the whitespace from the end of a string
        while(!isalnum(jurisdiction[jurisdiction.length() - 1])) {
            jurisdiction = jurisdiction.substr(0, jurisdiction.length()-1);}

        // Create object with data and push to vector
        crimes.push_back(Crime(incidentID,age,sex,race,offense,
                               location,weapon,jurisdiction));
    }
    // Close the file
    fileIn.close();
}

// Takes in the vector for crimes and an offense and outputs a vector
// containing basic age statistics (# of crimes, avg age, min age, max age)
// the offense parameter/

vector<double> getAgeStats(vector<Crime> crimes, string offense) {
    // create variables within the method
    double sumAge;
    double counter;
    double maxAge;
    // set to 100 as a placeholder so it doesn't input and remain 0
    double minAge = 100.0;
    // loop through crimes vector
    for (int i = 0; i < crimes.size(); i++) {
        // only look at crimes with inputted offense
        // update all of the variables each time through
        if(crimes[i].getOffense() == offense) {
            sumAge = sumAge + crimes[i].getAge();
            counter = counter + 1;

            // statements to cycle through and update max and min ages
            if (crimes[i].getAge() > maxAge) maxAge = crimes[i].getAge();
            if (crimes[i].getAge() < minAge) minAge = crimes[i].getAge();
        }
    }

    // Create a vector of doubles to input ages data
    // All are declared doubles to keep it a vector
    // of type double to allow the average age to be
    // a double.
    vector<double> ageStats;
    // calculate the average
    double avgAge = sumAge/counter;

    // enter basic stats into ageStats vector
    ageStats.push_back(counter);
    ageStats.push_back(avgAge);
    ageStats.push_back(maxAge);
    ageStats.push_back(minAge);

    // returns the ageStats vector with above data ordered [0],[1],[2],[3]
    return ageStats;
}

// Opens the integer list file and creates a vector of ints with them
void listReader(string filename, vector<int> &lists) {
    // Create an input file stream
    ifstream fileIn;
    // Open the file
    fileIn.open(filename);
    // Declare variables
    int num;
    // placeholder string to allow formatting adjustments below
    string a;

// Make sure the stream is ready to read
    // And it is not at the end of file (EOF)
    while (fileIn && fileIn.peek() != EOF) {

        // Read incidentID
        getline(fileIn, a, ',');
        // fix start line indentation char by removing white space
        while (!isalnum(a[0])) {
            a = a.substr(1, a.length());
        }

        fileIn >> num;

        // Create object with data and push to vector
        lists.push_back(num);
    }
    // Close the file
    fileIn.close();
}

// This method creates a vector of vectors of unsorted crimes that increase by 100 objects
// beginning at 100 and going to 2600.
// These structures are used by each of the sorting algorithms to iterate over and sort
// while recording the reads, writes and time it takes.
vector<vector<Crime>> crimeVector(vector<Crime> crimes) {
    vector<vector<Crime>> crimeVector;
    vector<Crime> temp;
    int hundo = 100;
    for (int i = 100; i < crimes.size(); i += hundo) {
        int a = 0;
        while (a < i) {
            temp.push_back(crimes[a]);
            ++a;
        }
        crimeVector.push_back(temp);
        temp.clear();
    }
    return crimeVector;
}

// outputs a data file to the data folder...
// ** important to create a data folder **
void createDataFiles(vector<vector<int>> data, string filename) {
    // create ofstream
    ofstream fileOut;

    // headers for read and write files
    vector<string> headers = {"n", "reads", "writes", "time"};
    // create/open timeSorted file
    fileOut.open ("../data/" + filename + ".csv");
    // populate headers in file
    for (string name : headers) {
        fileOut << name;
        fileOut << ",";
    }
    fileOut << "\n";
    // insert timer data
    for (vector<int> row : data) {
        for (int point : row) {
            fileOut << point;
            fileOut << ",";
        }
        fileOut << "\n";
    }
    // close file
    fileOut.close();
}

