//
// Created by Frederick Hall on 2019-02-02.
//

#ifndef VERMONTCRIMES_STACK_H
#define VERMONTCRIMES_STACK_H

#include "Node.h"
#include "Crime.h"

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

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
        //cout << "S push: " << item << endl;
        top = new Node<Object>(item, *top);
    }

    Object pop() {
        if (top->getNext() == nullptr) {
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

    // check if entry is in the Stack
    bool inStack(Object entry) {
        Node<Object> *temp = top;
        while (temp != nullptr) {
            Object returnVal = temp->getItem();
            if (returnVal == entry) {
                temp = nullptr;
                delete temp;
                // entry is in Stack!
                return true;
            }
            temp = temp->getNext();
        }
        // prevent memory leaks
        temp = nullptr;
        delete temp;
        // if entry is not in Stack
        return false;
    }

};


#endif //VERMONTCRIMES_STACK_H
