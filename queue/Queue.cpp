//
//  Queue.cpp
//  queue
//
//  Created by stone on 2020/2/16.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "Queue.hpp"
#include <iostream>

Queue::Queue(int qs) : qsize(qs) {
    head = rear = nullptr;
    items = 0;
}

bool Queue::isfull() const {
    return (items == qsize);
}

bool Queue::isempty() const {
    return (items == 0);
}

int Queue::queuecount() const {
    return items;
}

bool Queue::enqueue(const Item & item) {
    if(isfull()) {
        return false;
    }
    Node* add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if(head == nullptr) {
        head = add;
    } else {
        rear->next = add;
    }
    rear = add;
    return true;
}

bool Queue::dequeue(Item & item) {
    if(head == nullptr) {
        return false;
    }
    item = head->item;
    items--;
    Node* temp = head;
    head = head->next;
    delete temp;
    if(items == 0)
        rear = nullptr;
    return true;
}

void Customer::set(long when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

Queue::~Queue() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
