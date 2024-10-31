#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* front; 
    Node<T>* back;  

public:
    Queue() : front(nullptr), back(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            front = back = newNode;
        }
        else {
            back->next = newNode;
            newNode->prev = back;
            back = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, nothing to dequeue." << endl;
            return;
        }
        Node<T>* temp = front;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        }
        else {
            back = nullptr;
        }
        delete temp;
    }

    T peek() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty.");
        }
        return front->data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front of queue: " << queue.peek() << endl; 

    queue.dequeue();
    cout << "Front of queue after dequeue: " << queue.peek() << endl;

    queue.dequeue();
    queue.dequeue();
    queue.dequeue(); 

    return 0;
}
