//
// Created by Frederick Hall on 2019-02-05.
//

#ifndef LECTURER_QUEUE_H
#define LECTURER_QUEUE_H
#include "Node.h"
#include "Lecturer.h"

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

template<typename Object>
class Queue {

private:
    Node<Object> *front, *back;

public:
    // Default constructor
    Queue() {front = back = nullptr;}

    // Destructor
    ~Queue() {
        while (front != nullptr) {
            Node<Object> *temp = front;
            front = front->getNext();
            delete temp;
            temp = nullptr;
        }
        back = nullptr;
    }

    void push(Object item) {
        Node<Object>* temp = new Node<Object>(item);

        // for first Node
        if (front == nullptr) {
            front = temp;
            back = temp;
        }
        // point from old back to new back
        // set new back
        else {
            back->setNext(*temp);
            back = temp;
        }
        cout << item << " has been inserted successfully." << endl;

        // prevent memory leaks...
        // does seem to work deleting temp before setting it to nullptr...
        temp = nullptr;
        delete temp;
    }

    void pop() {
        // nothing exists in queue
        if(front == nullptr) {
            cout << "underflow" << endl;
            return;
        }
        // need to print here as it's deleted after.
        cout << "popping " << front->getItem() << endl;
        // if there is only one Node remaining
        if (front == back) {
            front = back = nullptr;
        }
        else {
            front = front->getNext();
        }
    }

    bool inQueue(Object entry) {
        Node<Object> *temp = front;
        while (temp != nullptr) {
            Object returnVal = temp->getItem();
            if (returnVal == entry) {
                // prevent memory leaks
                delete temp;
                temp = nullptr;
                // entry found in Queue!
                return true;
            }
            temp = temp->getNext();
        }
        // prevent memory leaks
        delete temp;
        temp = nullptr;
        // Entry not found in Queue
        return false;
    }
};



#endif //LECTURER_QUEUE_H
