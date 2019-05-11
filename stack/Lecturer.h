//
// Created by Frederick Hall on 2019-01-16.
//

#ifndef LECTURER_LECTURER_H
#define LECTURER_LECTURER_H

#include <string>
#include <vector>

using namespace std;


class Lecturer {

private:
    string name;
    string office;
    vector<int> classes;    // resizable and used for class #s ex: 202, 123, 124

public:
    /*
    * Constructor
    */
    Lecturer();
    Lecturer(string name, string office, vector<int> classes);

    /*
     * Getters
     */
    string getName() const; // const means the method does not change the object
    string getOffice() const;
    vector<int> getClasses() const;

    /*
     * Setters
     */
    void setName(string name);
    void setOffice(string office);
    void setClasses(vector<int> classes);

    /*
     * Overloaded Operators
     */
    friend ostream& operator << (ostream& outs, const Lecturer &lec);

    friend bool operator == (const Lecturer &lec1, const Lecturer &lec2);
};

// The & means instead of making a copy of the parameter it will give
// direct access to what was passed in
void getLecturersFromFile(string filename,
        vector<Lecturer> &lecturers);

#endif //LECTURER_LECTURER_H