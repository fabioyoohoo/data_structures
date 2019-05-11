#include "Lecturer.h"
#include "Stack.h"
#include "Node.h"
#include "Queue.h"

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;


int main() {

/*    Lecturer lec1;
    cout << lec1.getName() << endl;
    cout << lec1.getOffice() << endl;
    vector<int> classes = lec1.getClasses();
    for (int i = 0; i < classes.size(); i++ ){
        cout << classes[i] << endl;
    }

    Lecturer lec2 = Lecturer("Jody Prescott", "200 Lafayette", {300, 334, 378});
    cout << lec2.getName() << endl;
    cout << lec2.getOffice() << endl;
    vector<int> classes2 = lec2.getClasses();
    for (int i = 0; i < classes.size(); i++) {
        cout << classes[i] << endl;
    }*/

/** Keep This Code **/

 vector<Lecturer> lecturers;
    // For filename, it will be looking in the cmake-build-debug folder
    // so we use ../ to get out of that folder
    getLecturersFromFile("../CS_Lecturers.csv", lecturers);


    // print number of objects in lecturers
    cout << "Number of lecturers: " << lecturers.size() << endl;
    cout << endl;

  Stack<Lecturer> lectureStack;
  for (int i = 0; i < 5; i ++){
      cout << setw(8) << "push: " << lecturers[i] << endl;
      lectureStack.push(lecturers[i]);
  }

  cout << endl;

    for (int j = 0; j < 9; j ++) {
        cout << setw(8) << "pop: " << lecturers[j] << endl;
        lectureStack.pop();
    }




/*
    // Create Stack
    Stack<Lecturer> lectureStack;
    for (Lecturer &lec : lecturers) {
       lectureStack.push(lec);
    }


    // Create Queue
    Queue<Lecturer> lectureQueue;
    for (Lecturer &lec : lecturers) {
       lectureQueue.push(lec);
    }

    cout << endl;

    // check if lec is in Queue
    cout << boolalpha << lectureQueue.inQueue(lecturers[1]) << endl;
    cout << boolalpha << lectureStack.inStack(lecturers[2]) << endl;


    for (Lecturer &lec : lecturers) {
       lectureQueue.pop();
    }

    for (Lecturer &lec : lecturers) {
       lectureStack.pop();
    }

    // testing queue search method
    cout << boolalpha << lectureQueue.inQueue(lecturers[1]) << endl;
    cout << boolalpha << lectureStack.inStack(lecturers[2]) << endl;

    // testing stack search method
    //cout << boolalpha << lec1.inQueue(lecturers[6]) << endl;



    Queue<int> nums;
    nums.push(5);
    nums.push(12);
    nums.push(7);

    nums.pop();
    nums.pop();
    nums.pop();

    cout << boolalpha << nums.inQueue(7) << endl;

    */

    return 0;
};