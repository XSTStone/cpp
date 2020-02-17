//
//  Queue.hpp
//  queue
//
//  Created by stone on 2020/2/16.
//  Copyright © 2020 Stone. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

class Customer {
private:
    long arrive;
    int processtime;
public:
    Customer() { arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue {
private:
    enum {Q_SIZE = 10};
    struct Node {
        Item item;
        struct Node* next;
    };
    Node* head;
    Node* rear;
    int items;
    const int qsize = 10;
    Queue(const Queue & q) : qsize(0) {}
    Queue & operator=(const Queue & q) {return *this;}
public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item & item);
    bool dequeue(Item & item);
};



#endif /* Queue_hpp */
