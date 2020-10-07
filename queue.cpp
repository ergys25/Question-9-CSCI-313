//
// Created by ergys on 9/25/2020.
//

#include "queue.h"

queue::queue() {
    head = tail = NULL;

}

void queue::addTail(std::string d) { // addTail method to store each digit of the sequence
    node *temp = new node(d);

    if (tail == NULL) {
        head = tail = temp;
        size++;
        return;
    }
    tail->next = temp;
    tail = temp;
    size++;
}

int queue::returnSize() {
    return size;
}

node *queue::getHead()  {
    return head;
}

node *queue::getTail()  {
    return tail;
}




