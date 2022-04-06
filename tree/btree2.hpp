#ifndef CS2_BTREE2_
#define CS2_BTREE2_

#include <iostream>

template <typename T>
class btree {
public:
    btree() : root(0) {};
    ~btree();
    btree(const btree<T>&);

    void swap(btree<T>&);
    btree<T>& operator=(btree<T> rhs) { swap(rhs); return *this; };

    bool isEmpty() const { return root; };
    bool isFull() const;
    bool find(const T&) const;
    void binsert(const T&);
    void bremove(const T&);
    void inorder(std::ostream&) const;

private:
    bnode<T>* root;
};

template <typename T>
class bnode {
public:
    bnode() : left(0), right(0) {};
    bnode(const T& item) : left(0), right(0), data(item) {};
    ~bnode();
    bnode(const bnode<T>&);

    bool find(const T&) const;
    void binsert(const T&);
    bnode<T>* bremove(const T&);
    void inorder(std::ostream&) const;

    T predecessor() const;

private:
    bnode<T>* left;
    bnode<T>* right;
    T data;
};


template <typename T>
bool btree<T>::find(const T& key) const {
    if (!root) return false;
    return root->find(key);
}

template <typename T>
bool bnode<T>::find(const T& key) const {
    if (data == key) return true;
    if (key < data) {
        if (left) return left->find(key);
        else return false;
    } else {
        if (right) return right->find(key);
        else return false;
    }
}

template <typename T>
void btree<T>::binsert(const T& x) {
    if (!root) {
        root = new bnode<T>(x);
    } else {
        root->binsert(x);
    }
}

template <typename T>
void bnode<T>::binsert(const T& x) {
    if (x < data) {
        if (left) left->binsert(x);
        else left = new bnode<T>(x);
    } else {
        if (x == data) return;
        if (right) right->binsert(x);
        else right = new bnode<T>(x);
    }
}

template <typename T>
void btree<T>::inorder(std::ostream& out) const {
    if (root) root->inorder(out);
}

template <typename T>
void bnode<T>::inorder(std::ostream& out) const {
    if (left) left->postorder(out);
    out << data << ' '; //visit
    if (right) right->postorder(out);
}

template <typename T>
btree<T>::~btree() {
    if (root) delete root;
    // compiler will get the rest
}

template <typename T>
bnode<T>::~bnode() {
    if (left) delete left;
    if (right) delete right;
    // compiler will get the rest
}

template <typename T>
btree<T>::btree(const btree<T>& actual) : btree() {
    if (actual.root) root = new bnode<T>(*(actual.root));
}

template <typename T>
bnode<T>::bnode(const bnode<T>& actual) : bnode() {
    data = actual.data;
    if (actual.left) left = new bnode<T>(*(actual.left));
    if (actual.right) right = new bnode<T>(*(actual.right));
}

template <typename T>
T bnode<T>::predecessor() const {
    if (right) return right->predecessor();
    else return data;
}

template <typename T>
void btree<T>::bremove(const T& x) {
    if (find(x)) root = root->bremove(x);
}

template <typename T>
bnode<T>* bnode<T>::bremove(const T& x) {
    bnode<T>* temp;
    if (x == data) {           // found value
        if (!left && !right) { // no subtrees
            delete this;
            return 0;
        }
        if (!left && right) {  // only right subtree
            temp = right;
            right = 0;
            delete this;
            return temp;
        }
        if (left && !right) {  // only left subtree
            temp = left;
            left = 0;
            delete this;
            return left;
        }

        // two children
        data = left->predecessor();
        left = left->bremove(data);

    } else {
        if (x < data) left = left->bremove(x);
        else right = right->bremove(x);
    }
    return this;
}

#endif