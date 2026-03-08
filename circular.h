#pragma once
#include<iostream>
#include<string>

using namespace std;

template<class ItemType>
class qeue {
private:
    ItemType *item;
    int front, rear, count, maxQeue;

public:
    qeue(int max) : maxQeue(max) {
        count = 0;
        front = -1;
        rear = -1;
        item = new ItemType[maxQeue];
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == maxQeue);
    }

    void insert(ItemType val) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } 
        else {
            rear = (rear + 1) % maxQeue;
        }

        item[rear] = val;
        ++count;
    }

    void remove() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } 
        else {
            front = (front + 1) % maxQeue;
        }

        --count;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        for (int c = 0; c < count; c++) {
            cout << item[i] << " ";
            i = (i + 1) % maxQeue;
        }
        cout << endl;
    }

    ~qeue() {
        delete[] item;
    }
};