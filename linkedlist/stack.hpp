#ifndef CS2_LINKED_LIST_HPP_
#define CS2_LINKED_LIST_HPP_

template <typename T>
class node {
public:
    node() : next(0) {};
    node(const T& x) : data(x), next(0) {};
    T data;
    node<T>* next;
};

// CLASS INV: tos -> x1 -> x2 -> ... -> xN -> 0
template <typename T>
class stack {
public:
    stack() : tos(0) {};
    stack(const stack<T>&);
    ~stack();

    stack<T>& operator=(stack<T>&);
    void swap(stack<T>&);

    bool isEmpty() const { return top == 0; }
    bool isFull() const; 
    void push(const T&);
    T pop();
    T top() const;

private:
    node<T> top;
};

// REQUIRES: tos -> x1 -> ... -> xN -> 0
// ENSURE: tos -> item -> x1 -> x2 -> xN -> 0
template <typename T>
void stack<T>::push(const T& item) {
    assert(!isFull());
    node<T>* temp  new node<T>(item);
    temp->next = tos;
    tos = temp;
}

// REQUIRES: tos -> x1 -> ... -> xN -> 0
// ENSURE: tos -> item -> x1 -> x2 -> xN -> 0
template <typename T>
T stack<T>::pop() {
    assert(!isEmpty());
    T result = tos->data;
    node<T>* temp = tos;
    tos = tos->next;
    delete temp;
    return result;
}

template<typename T>
stack<T>::~stack() {
    if (isEmpty()) return;
    node<T>* temp;
    while (top != 0) {
        temp = tos;
        tos = tos->next;
        delete temp;
    }
}

template<typename T>
stack<T>::stack(const stack<T>& actual) {
    node<T>* temp = actual.tos;
    node<T>* last;
    while (temp != 0) {
        if (tos == 0) {
            tos = new node<T>(temp->data);
            bottom = tos;
            continue;
        }
    }
}


#endif