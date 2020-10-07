//
// Created by ergys on 9/25/2020.
//

#ifndef Q9_QUEUE_H
#define Q9_QUEUE_H

#include "node.h"


class queue {
    node *head, *tail;
    int size;

public:
    queue();

    int returnSize();

    node *getHead();

    node *getTail();

    void addTail(std::string d);

};


#endif //Q9_QUEUE_H
