//
// Created by Frederick Hall on 2019-01-16.
//

#include "Lecturer.h"
#include "Stack.h"
#include "Node.h"

#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

Lecturer::Lecturer() {
    name = "Jane Doe";
    office = "MLK Room";
    classes.push_back(101);
    classes.push_back(202);
}

Lecturer::Lecturer(string name, string office, vector<int> classes) {
        this->name = name;
        this->office = office;
        for (int num : classes) {
            this->classes.push_back(num);
        }
    }
    /*
     * Getter
     */
    string Lecturer::getName() const {
        return name;
    }

    string Lecturer::getOffice() const {
        return office;
    }

    vector<int> Lecturer::getClasses() const {
        return classes;
    }

    /*
     * Setter
     */
    void Lecturer::setName(string name) {
        this->name = name;
    }

    void Lecturer::setOffice(string office) {
        this->office = office;
    }

    void Lecturer::setClasses(vector<int> classes) {
        this->classes.clear();
        for (int num : classes) {
            this->classes.push_back(num);
        }
    }

    ostream& operator << (ostream& outs, const Lecturer &lec) {
        outs << left << setw(25) << lec.getName();
        outs << setw(12) << lec.getOffice() << right;
        vector<int> classes = lec.getClasses();

        // more efficient way of cycling through classes
        for (auto c : classes) {
            outs << setw(4) << c << " ";
        }
        return outs;
    }

    // Overloaded operator for comparing lecture objects
    bool operator == (const Lecturer &lec1, const Lecturer &lec2) {
        string name1 = lec1.getName();
        string name2 = lec2.getName();
        if (name1 == name2) {
            return true;
        }
        else { return false;}
    }

    void getLecturersFromFile(string filename,
            vector<Lecturer> &lecturers) {
        // Create an input file stream
        ifstream fileIn;
        // Open the file
        fileIn.open(filename);
        // Declare variables
        string name = "", office = "";
        vector<int> classes;
        int classNum = 0;
        char comma;

        // Make sure the stream is ready to read
        // And we are not at the end of the file (EOF)
        while (fileIn && fileIn.peek() != EOF) {
            // read from file

            // Read the name
            getline(fileIn, name, ',');
            while(!isalnum(name[0])) {
                name = name.substr(1, name.length());}


            // Read class 1
            fileIn >> classNum;
            classes.push_back(classNum);
            fileIn >> comma;

            // Read class 2
            fileIn >> classNum;
            classes.push_back(classNum);
            fileIn >> comma;

            // Read class 3
            fileIn >> classNum;
            if (!fileIn) {
                // No class 3. Clear the stream.
                fileIn.clear();
            } else {
                classes.push_back(classNum);
            }
            fileIn >> comma;

            // Read office.
            // Stop reading at the newline character
            // Because there is no comma at the end of the line
            getline(fileIn, office, '\n');
            // Get rid of the whitespace from the end of a string
            while(!isalnum(office[office.length() - 1])) {
                office = office.substr(0, office.length() - 1);}
            // create object with data and push to the vector
            lecturers.push_back(Lecturer(name, office, classes));

            // clear the classes vector
            classes.clear();
        }
        fileIn.close();
    }

