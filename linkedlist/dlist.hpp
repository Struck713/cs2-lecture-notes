#ifndef CS2_DLIST_HPP_
#define CS2_DLIST_HPP_

// REQUIRES: assignable(T)
template<typename T>
class dnode {
public:
        dnode()           : next(0), prev(0) {};
        dnode(const T& x) : data(x), next(0), prev(0) {};
    T   data;
    dnode<T> *next;
             *prev;

};

template <typename T> class List;

// Iterator for List.
// CLASS INV: current == 0 || current->dnode<T>()
// REQUIRES : assignable(T) && copyconstructable(T)
template <typename T>
class Itr {
public:
    Itr               () : current(0) {};
    Itr               (dnode<T>* ptr) : current(ptr) {};

    Itr<T>&   operator++()    { // pre  ++i 
        if (current) current = current->next;
        return *this;
    }

    Itr<T>    operator++(int) { // post i++ dummy parameter 
        Itr result(current);
        if (current) current = current->next;
        return result;
    }

    Itr<T>&   operator--()    {
        if (current) current = current->prev;
        return *this;
    };

    Itr<T>    operator--(int) {
        Itr result(current);
        if (current) current = current->prev;
        return result;
    };

    bool      operator==(Itr<T> rhs) const { return current == rhs.current; }
    bool      operator==(Itr<T> rhs) const { return current != rhs.current; } 

    T         operator* () const { return current->data };
    T&        operator* ()       { return current->data };

    // Overloading ->
    // Must be a method (not a free function)
    // Must return a pointer (or object of that class)
    dnode<T>* operator->() const { return current; };
    dnode<T>* operator->()       { return current; };

    friend class List;

private:
    dnode<T> *current;
};

/////////////////////////////////////////////////
// CLASS INV: (beginning == 0 && ending == 0) ||
//             beginning -> X[0] <-> X[1] <-> ...
//                  <-> X[length() - 1] <- ending
// REQUIRES :
//
template<typename T>
class List {
public:
    List              () : begining(0), ending(0) {};
    ~List             ();
    List              (const List<T>&);
    void swap         (List<T>&);
    List<T>& operator=(List<T> rhs) { swap(rhs); return *this; };

    bool       isEmpty() const { return beginning == 0; };
    bool       isFull () const;
    int        length () const;
    void  insertBefore(const T&, Itr<T>);
    void   insertAfter(const T&, Itr<T>);
    void        remove(Itr<T>);

    // const
    Itr<T>       begin() const { return Itr<T>(beginning); };
    Itr<T>         end() const { return Itr<T>(ending);    };
    T            front() const { return beginning->data;   };
    T             back() const { return ending->data;      };
    Itr<T>  find(const T&) const;
    Itr<T>  operator[](int) const;

    // ref
    Itr<T>&      begin() { return Itr<T>(beginning); };
    Itr<T>&        end() { return Itr<T>(ending);    };
    T&           front() { return beginning->data;   };
    T&            back() { return ending->data;      };
    Itr<T>& find(const T&);
    Itr<T>& operator[](int);

private:
    dnode<T> *beginning, *ending;
};

template <typename T>
Itr<T> List<T>::operator[](int n) const {
    int i = 0;
    Itr<T> result(beginning);
    while (i != n) {
        if (result == 0) break;
        ++i;
        ++result;
    }
    return result;
}

// ENSURES: RETVAL == Itr->dnode(key) || 0
template <typename T>
Itr<T> List<T>::find(const T& key) const {
    Itr<T> result(beginning);
    while (result != 0) {
        if (*result == key) return result;
        ++result;
    }
    return Itr<T>(0);
}

template <typename T>
int List<T>::length() const {
    int len = 0;
    Itr<T> temp(beginning);
    while (temp != 0) { ++len; ++temp; }
    return len;
}

template <typename T>
void List<T>::insertBefore(const T& item, Itr<T> ptr) {
    dnode<T>* temp = new dnode<T>(item);
    if (beginning == 0) {
        beginning = temp;
        ending = temp;
        return;
    }
    if (ptr == beginning) {
        temp->next = beginning;
        beginning->prev = temp;
        beginning = temp;
        return;
    }

    temp->next = ptr.current;
    temp->prev = ptr->prev;
    ptr->prev->next = temp;
    ptr->prev = temp;
}

template <typename T>
void List<T>::insertAfter(const T& item, Itr<T> ptr) {
    dnode<T>* temp = new dnode<T>(item);
    if (ending == 0) {
        ending = temp;
        beginning = temp;
        return;
    }
    if (ptr == ending) {
        temp->prev = ending;
        ending->next = temp;
        ending = temp;
        return;
    }

    temp->prev = ptr.current;
    temp->next = ptr->next;
    ptr->next->prev = temp;
    ptr->next = temp;
}

template<typename T>
void List<T>::remove(Itr<T> ptr) {
    if (ptr == beginning) {
        beginning = ptr->next;
    } else {
        ptr->prev->next = ptr->next;
    }

    if (ptr == ending) {
        ending = ptr->prev;
    } else {
        ptr->next->prev = ptr->prev;
    }

    delete ptr.current;
}

template <typename T>
List<T>::~List() {
    // while (!isEmpty()) remove(begin());
    dnode<T>* temp;
    while (beginning != 0) {
        temp = beginning;
        beginning = beginning->next;

        delete temp;
    }
}

template <typename T>
List<T>::List(const List<T>& actual) : List<T>() {
    Itr<T> temp(actual.beginning);
    while (temp != 0) {
        if (beginning == 0) {
            beginning = new dnode<T>(temp->data);
            ending = beginning;
        } else {
            ending->next = new dnode<T>(temp->data);
            ending->next->prev = ending;
            ending = ending->next;
        }
        ++temp;
    }
}

template <typename T>
void List<T>::swap(List<T>& rhs) {
    dnode<T> *temp = rhs.beginning;
    rhs.beginning = beginning;
    beginning = temp;

    temp = rhs.ending;
    rhs.ending = ending;
    ending = temp;
}

#endif