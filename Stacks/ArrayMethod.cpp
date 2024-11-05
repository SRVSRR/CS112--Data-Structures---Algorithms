#include <iostream>
using namespace std;

template <class T>
class Stack
{
public:
    int size;
    int head;
    T *array;

    Stack(int size)
    {
        this->size = size;
        array = new T[size];
        head = -1;
    }

    ~Stack()
    {
        delete[] array;
    }

    bool push(T data)
    {
        if (isFull())
        {
            return false;
        }

        array[++head] = data;
        return true;
    }

    bool pop()
    {
        if (isFull())
        {
            return false;
        }

        T data = array[head--];
        return true;
    }

    bool isFull()
    {
        return head == (size - 1);
    }
};

int main()
{

    Stack<int> stack(5);

    for (int i = 0; i < stack.size; i++)
    {
        stack.push(i * 2);
        cout << stack.array[i] << " ";
    }

    for (int i = 0; i < stack.size; i++)
    {
        cout << stack.array[i] << " ";
    }

    return 0;
}