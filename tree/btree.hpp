#ifndef CS2_BTREE_
#define CS2_BTREE_

#include <iostream>

template <typename T>
class btree {
public:
    btree() : left(0), right(0), empty(true) {};
    btree(const T& item) : left(0), right(0), empty(false), data(item) {};
    ~btree();
    btree(const btree<T>&);
    void swap(btree<T>&);
    btree<T>& operator=(btree<T> rhs) { swap(rhs); return *this; }
    
    bool isEmpty() const { return empty; }
    bool isFull() const;
    bool find(const T&) const;
    void insert(const T&);
    void inorder(std::ostream&) const;
    void preorder(std::ostream&) const;
    void postorder(std::ostream&) const;

private:
    btree<T> *left, *right;
    bool empty;
    T data;
};

// REQUIRES: !isFull()
// ENSURES: x will be inserted into the tree
template <typename T>
void btree<T>::insert(const T& x) {
    if (empty) data = x;
    else {
        if (x < data) {
            if (left) left->insert(x);
            else left = new btree<T>(x);
        } else {
            if (right) right->insert(x);
            else right = new btree<T>(x);
        }
    }

}

// ENSURES: if key in Tree then RETVAL = true
template <typename T>
bool btree<T>::find(const T& key) const {
    if (empty) return false;
    if (key == data) return true;
    if (key < data) {
        if (left) return left->find(key);
        return false;
    } else {
        if (right) return right->find(key);
        return false;
    }
    return false;
}

template <typename T>
void btree<T>::postorder(std::ostream& out) const {
    if (empty) return;
    
    if (left) left->postorder(out);
    if (right) right->postorder(out);
    out << data << ' '; // visit
}

template <typename T>
void btree<T>::inorder(std::ostream& out) const {
    if (empty) return;

    if (left) left->postorder(out);
    out << data << ' '; //visit
    if (right) right->postorder(out);
}

template <typename T>
void btree<T>::preorder(std::ostream& out) const {
    if (empty) return;

    out << data << ' '; // visit
    if (left) left->postorder(out);
    if (right) right->postorder(out);
}


template<typename T>
btree<T>::~btree() {
    if (left)  delete left;  //! recursive because delete calls destructor of object class
    if (right) delete right;

    //* Compiler deallocates object memory (left, right, empty, data) 

}

template<typename T>
btree<T>::btree(const btree<T>& actual): btree<T>() {
    if (actual.empty) return;

    data  = actual.data;
    empty = actual.empty;

    if (actual.left) left   = new btree<T>(*(actual.left));
    if (actual.right) right = new btree<T>(*(actual.right));
    
}

template<typename T>
void  btree<T>::swap(btree<T>& rhs) {
    btree<T>* leftTemp = left;
    left = rhs.left;
    rhs.left = leftTemp;

    btree<T>* rightTemp = right;
    right = rhs.right;
    rhs.right = rightTemp;

    bool tempEmpty = empty;
    empty = rhs.empty;
    rhs.empty = tempEmpty;

    T tempData = data;
    data = rhs.data;
    rhs.data = tempData;
}

#endif