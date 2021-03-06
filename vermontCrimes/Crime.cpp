//
// Created by Frederick Hall on 2019-01-21.
//

#include "Crime.h"
#include <fstream>
#include <iomanip>
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
     * Overloaded Operator
     */
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

    // Overloaded Operator to compare two Crime objects
    // gets the unique IncidentID to do the comparison
    // used for the inStack and inQueue methods
    bool operator == (const Crime &crime1, const Crime &crime2) {
        string incidentID1 = crime1.getIncidentID();
        string incidentID2 = crime2.getIncidentID();
        if (incidentID1 == incidentID2) {
            return true;
        }
        else { return false; }
    }

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
