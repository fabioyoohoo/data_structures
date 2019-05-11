//
// Created by Frederick Hall on 2019-02-06.
//

#ifndef VERMONTCRIMES_QUEUE_H
#define VERMONTCRIMES_QUEUE_H

#include "Node.h"
#include "Crime.h"

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

template<typename Object>
class Queue {

private:
    Node<Object> *front, *back;
    // counter for tracking
    int count = 0;


public:
    // Default
    Queue() {front = back = nullptr;}

    // Destructor
    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
        delete front;
        front = nullptr;
        back = nullptr;
    }

    // Add to Queue
    void push(Object item) {
        Node<Object>* temp = new Node<Object>(item);

        // for first Node
        if (front == nullptr) {
            front = temp;
            back = temp;
        }
        // point back
        // and set a new back
        else {
            back->setNext(*temp);
            back = temp;
        }
        // prevent memory leaks
        temp = nullptr;
        delete temp;
        count ++;
    }

    // Remove from Queue
    Object pop() {
        // empty Queue
        if (isEmpty()) {
            cout << "Empty" << endl;
            return Object();
        }
        // 1 node in queue
        if (size() == 1) {
            Object returnVal = front->getItem();
            front = back = nullptr;
            count--;
            return returnVal;
        }
        // more than 1 node in queue
        else {
            Object returnVal = front->getItem();
            front = front->getNext();
            count--;
            return returnVal;
        }
    }

    bool inQueue(Object entry) {
        Node<Object> *temp = front;
        // loop over nodes
        while (temp != nullptr) {
            Object returnVal = temp->getItem();
            // operator overloading for Crime objects
            if (returnVal == entry) {
                //prevent memory leaks
                temp = nullptr;
                delete temp;
                // entry found in Queue
                return true;
            }
            temp = temp->getNext();
        }
        // prevent memory leaks
        delete temp;
        // entry not found in Queue
        return false;
    }

     /** Citing outside source code:
      *  Author: Techie Delight
      *  Title: Queue implementation in C++
      *  Availability: https://www.techiedelight.com/queue-implementation-cpp/
     */
     int size() {
        return count;
    }
    bool isEmpty() {
        return (size() == 0);
    }
};


#endif //VERMONTCRIMES_QUEUE_H