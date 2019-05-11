
#include "Crime.h"
#include "Stack.h"
#include "Queue.h"
#include "Node.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main() {

    // Establish a vector to store crimes
    vector<Crime> crimes;

    // open up file and add objects to the crimes vector
    getCrimesFromFile("../CRIME_DATA.csv", crimes);


    // Declare Queues
    Queue<int> numberQueue;
    Queue<string> lettersQueue;
    Queue<Crime> crimeQueueTest;

    // Push into Queues
    for (int i = 0; i < 10; i++) {
        numberQueue.push(i);}

    string islands = "archipeligo";
    for (int j = 0; j < islands.size(); j++) {
        // adds substring snippets of the above string to the queue
        lettersQueue.push(islands.substr(j,2*j+1));}

    //
    for (int i = 0; i < 5; i ++) {
        crimeQueueTest.push(crimes[i]);
    }

    // Pop a few
    cout << setw(8) << "Q pop: " << numberQueue.pop() << endl;
    cout << setw(8) << "Q pop: " << lettersQueue.pop() << endl;
    cout << setw(8) << "Q pop: " << crimeQueueTest.pop() << endl;

    // spacing
    cout << endl;

    // Search to get true
    cout << boolalpha << numberQueue.inQueue(1) << endl;
    cout << boolalpha << lettersQueue.inQueue("rch") << endl;
    cout << boolalpha << crimeQueueTest.inQueue(crimes[1]) << endl;
    cout << endl;

    // Search to get false
    cout << boolalpha << numberQueue.inQueue(0) << endl;
    cout << boolalpha << lettersQueue.inQueue("abd") << endl;
    cout << boolalpha << crimeQueueTest.inQueue(crimes[0]) << endl;
    cout << endl;

// Perform the following operations:

    // Create a Queue object and a Stack object, both of the type you created in Project 1.
    Queue<Crime> crimeQueue;
    Stack<Crime> crimeStack;

    // Print and push the first 10 objects from your vector (from Project 1) onto the Queue.
    for (int j = 0; j < 10; j++) {
        cout << setw(3) << j+1 << setw(8) << "Q push: " << crimes[j] << endl;
        crimeQueue.push(crimes[j]);
    }

    // spacing
    cout << endl; cout << "beak 1" << endl; cout << endl;

    // Pop the 10 objects off the Queue and push them onto the Stack.
    for (int j = 0; j < 10; j++) {
        // counter
        cout << j+1 << ":" << endl;

        // pop from Queue
        Crime tenCrimes = crimeQueue.pop();
        cout << setw(8) << "Q pop: " << tenCrimes << endl;

        // push to Stack
        crimeStack.push(tenCrimes);
        cout << "S push: " << tenCrimes << endl;
    }

    //spacing
     cout << endl; cout << "break 2" << endl; cout << endl;

    // Pop and print the 10 objects off the Stack.
    for (int j = 0; j < 10; j++){
        cout << setw(3) << j+1 << setw(8) << " S pop: " << crimeStack.pop() << endl;
    }

    return 0;
}