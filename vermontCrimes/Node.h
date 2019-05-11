//
// Created by Frederick Hall on 2019-02-02.
//

#ifndef VERMONTCRIMES_NODE_H
#define VERMONTCRIMES_NODE_H

/** Represents one Node to be used in a linked list
 * Contains data (object) and reference to next in list
 */

template<typename Object>
class Node {
private:
    Object item;
    // Store a pointer to the next node
    Node *next;

public:
    /** Create new node with specified data
     * Have it reference null
     * @param newItem is data to added to new node
     */
    Node(Object newItem) {
        item = newItem;
        next = nullptr;
    }

    /** Create new node with specified data
     * Have it reference nextNode
     * @param newItem is data to added to new node
     * @param nextNode is reference that new Node's next will hold
     */

    // Pass the address/reference of the nextNode
    Node(Object newItem, Node &nextNode) {
        item = newItem;
        // Store the memory address in the pointer
        next = &nextNode;
    }

    /** set data field (item) of Node
     *  @param newItem, to set item field to
     */
    void setItem(Object newItem) {
        item = newItem;
    } // end setItem

    /** get data field (item) of Node
     *  @return item field
     */
    Object getItem() {
        return item;
    }

    /** set next field of Node
     * @param nextNode, to set next field to
     */
    void setNext(Node &nextNode) {
        next = &nextNode;
    }

    /** get next field Node
     * @return pointer to next Node
     */
    Node* getNext() {
        return next;
    }
};


#endif //VERMONTCRIMES_NODE_H
