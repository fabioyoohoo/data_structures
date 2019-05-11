//
// Created by Frederick Hall on 2019-02-02.
//

#ifndef LECTURER_STACK_H
#define LECTURER_STACK_H
#include "Node.h"
#include "Lecturer.h"

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

/*
 * Stack Class
 * It will use the Node class where each Node
 * points to the one below it.
 * We will keep track of where the top Node is located.
 */

template<typename Object>
class Stack {
private:
    Node<Object> *top;

public:
    // Default Constructor
    Stack() {
        top = new Node<Object>(Object());
    }

    // Destructor
    ~Stack() {
        while (top->getNext() != nullptr) {
            pop();
        }
        delete top;
        top = nullptr;
    }

    void push(Object item) {
        top = new Node<Object>(item, *top);
    }

    Object pop() {
        if (top->getNext() == nullptr) {
            // TODO: refine this in a later class
            return Object();
        }
        Node<Object> *temp = top;
        top = top->getNext();
        Object returnVal = temp->getItem();

        // prevent memory leaks
        delete temp;
        temp = nullptr;
        return returnVal;
    }

    // check if the Object is in the Stack
    bool inStack(Object entry) {
        // create temporary top to preserve top
        Node<Object> *temp = top;
        // cycle through as long as temp != nullptr
        while (temp != nullptr) {
            // get object and get name for both objects
            Object returnVal = temp->getItem();
            // compare if the strings are the same and return true if they are
            if (returnVal == entry) {
                // preventing memory leaks
                temp = nullptr;
                delete temp;
                // entry found in Stack!
                return true;
            }
            // update to look at next node in stack
            temp = temp->getNext();
        }
        // preventing memory leaks
        temp = nullptr;
        delete temp;

        // return if object is not in the stack
        return false;
    }

};

#endif //LECTURER_STACK_H
