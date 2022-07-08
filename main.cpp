#include <iostream>
#include <string>
#include <vector>

template <typename T>
class BSTComparable {
public:
    virtual bool lessThan(T) = 0;
    virtual bool greaterThan(T) = 0;
};

template <typename T> class bstNode;
template <typename T> class BSTree;

class testBSTValue : BSTComparable<testBSTValue> {
public:
    testBSTValue();
    testBSTValue(int, std::string);
    bool lessThan(testBSTValue rv) {
        return this->i < rv.i && this->s < rv.s;
    }
    bool greaterThan(testBSTValue rv) {
        return this->i > rv.i && this->s > rv.s;
    }
private:
    int i;
    std::string s;
};

testBSTValue::testBSTValue() {}

testBSTValue::testBSTValue(int i, std::string s) {
    this->i = i;
    this->s = s;
}

template <typename T>
class bstNode {
public:
    bstNode(T);
    friend class BSTree<T>;
private:
    T v;
    bstNode<T> * l;
    bstNode<T> * r;
};

template <typename T>
bstNode<T>::bstNode(T v) {
    this->v = v;
    this->l = nullptr;
    this->r = nullptr;
}

template <typename T>
class BSTree {
public:
    void Set(T);
    friend class bstNode<T>;
private:
    bstNode<T>* r;
};

template <typename T>
void BSTree<T>::Set(T v) {
    if (this->r == nullptr) {
        this->r = new bstNode<T>(v);
        return;
    }
    auto p = this->r;
    while (true) {
        if (p->v < v) {
            if (p->l == nullptr) {
                p->l = new bstNode<T>(v);
                return;
            } else {
                p = p->l;
            }
        } else if (p->v > v) {
            if (p->r == nullptr) {
                p->r = new bstNode<T>(v);
                return;
            } else {
                p = p->r;
            }
        } else {
            return;
        }
    }
}

template <>
void BSTree<testBSTValue>::Set(testBSTValue v) {
    if (this->r == nullptr) {
        this->r = new bstNode<testBSTValue>(v);
        return;
    }
    auto p = this->r;
    while (true) {
        if (p->v.lessThan(v)) {
            if (p->l == nullptr) {
                p->l = new bstNode<testBSTValue>(v);
                return;
            } else {
                p = p->l;
            }
        } else if (p->v.greaterThan(v)) {
            if (p->r == nullptr) {
                p->r = new bstNode<testBSTValue>(v);
                return;
            } else {
                p = p->r;
            }
        } else {
            return;
        }
    }
}

int main() {
    auto bst1 = new BSTree<int>();
    auto bst2 = new BSTree<testBSTValue>();

    for (auto index = 0; index != 5; index++) {
		bst1->Set(5 - index);
		bst2->Set(testBSTValue(5-index, std::string(5-index, 'i')));
	}
    return 0;
}