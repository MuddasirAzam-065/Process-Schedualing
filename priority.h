#pragma once
#include <iostream>
#include "circular.h"

using namespace std;

template <class ItemType>
class priorityQueue {
private:
    qeue<ItemType> **pq;
    int totalPriority;
    int size;

public:

    priorityQueue(int priorities, int maxSize) {
        totalPriority = priorities;
        size = maxSize;

        pq = new qeue<ItemType>*[totalPriority];

        for (int i = 0; i < totalPriority; i++) {
            pq[i] = new qeue<ItemType>(size);
        }
    }

    bool isEmpty() {
        for (int i = 0; i < totalPriority; i++) {
            if (!pq[i]->isEmpty())
                return false;
        }
        return true;
    }

    bool isFull() {
        for (int i = 0; i < totalPriority; i++) {
            if (!pq[i]->isFull())
                return false;
        }
        return true;
    }

    void insert(ItemType value, int priority) {
        if (priority < 1 || priority > totalPriority) {
            cout << "Invalid Priority\n";
            return;
        }

        if (pq[priority - 1]->isFull()) {
            cout << "Queue Full at Priority " << priority << endl;
            return;
        }

        pq[priority - 1]->insert(value);
    }

    void remove(int priority) {
    if (priority < 1 || priority > totalPriority) {
        cout << "Invalid Priority\n";
        return;
    }

    if (pq[priority - 1]->isEmpty()) {
        cout << "Queue Empty at Priority " << priority << endl;
        return;
    }

    pq[priority - 1]->remove();
}

    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is Empty\n";
            return;
        }

        for (int i = 0; i < totalPriority; i++) {
            cout << "Priority " << (i + 1) << ": ";
            pq[i]->display();
        }
    }

    

    ~priorityQueue() {
        for (int i = 0; i < totalPriority; i++) {
            delete pq[i];
        }
        delete[] pq;
    }
};