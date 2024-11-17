#include <iostream>
#define MAX 100

class ArrayQueue {
private:
    int arr[MAX]; // Array to hold queue elements
    int front;    // Index of the front element
    int rear;     // Index of the rear element
    int size;     // Current number of elements

public:
    ArrayQueue() : front(0), rear(-1), size(0) {}

    // Enqueue operation
    void enqueue(int data) {
        if (size >= MAX) {
            std::cout << "Queue overflow\n";
            return;
        }
        rear = (rear + 1) % MAX; // Circular increment
        arr[rear] = data;
        size++;
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue underflow\n";
            return -1;
        }
        int data = arr[front];
        front = (front + 1) % MAX; // Circular increment
        size--;
        return data;
    }

    // Front operation
    int getFront() const {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Check if queue is empty
    bool isEmpty() const {
        return size == 0;
    }
};
