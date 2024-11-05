#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
    T data;
    Node<T> *next;

public:
    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    Node<T> *getNext()
    {
        return next;
    }

    void setNext(Node<T> *next)
    {
        this->next = next;
    }

    T getData()
    {
        return data;
    }
};

template <class T>
class Queue
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
    }

    ~Queue()
    {
        while (head != NULL)
        {
            dequeue();
        }
    }

    void enqueue(T data)
    {
        Node<T> *node = new Node<T>(data);

        if (isEmpty())
        {
            head = node;
            tail = node;
        }

        tail->setNext(node);
        tail = node;

        cout << "Enqueued " << data << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue empty" << endl;
            return;
        }

        Node<T> *node = head;
        head = head->getNext();

        if (head == NULL)
        {
            tail = NULL;
        }

        cout << "Dequeued " << node->getData() << endl;
        delete node;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
};

int main()
{

    Queue<int> *queue = new Queue<int>;

    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);

    delete queue;

    return 0;
}