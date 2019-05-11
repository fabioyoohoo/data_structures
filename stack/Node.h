//
// Created by Frederick Hall on 2019-02-02.
//

#ifndef LECTURER_NODE_H
#define LECTURER_NODE_H

/** Represents one Node to be used in a linked list
 * Contains data (object) and reference to next in list
 */

template<typename Object>
class Node {
private:
    Object item;
    Node *next;

public:
    Node(Object newItem) {
        item = newItem;
        next = nullptr;
    }

    Node(Object newItem, Node &nextNode) {
        item = newItem;
        next = &nextNode;
    }

    void setItem(Object newItem) {
        item = newItem;
    }

    Object getItem() {
        return item;
    }

    void setNext(Node &nextNode) {
        next = &nextNode;
    }
    Node* getNext() {
        return next;
    }
};


#endif //LECTURER_NODE_H
