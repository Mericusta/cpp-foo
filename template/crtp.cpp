#include <iostream>
#include <vector>

template <typename T>
class Animal {
public:
    void eat() {
        static_cast<T*>(this)->eat();
    }
};

class Lion : public Animal<Lion> {
public:
    void eat() {
        std::cout << "lion eat" << std::endl;
    }
};

class Cat : public Animal<Cat> {
public:
    void eat() {
        std::cout << "cat eat" << std::endl;
    }
};

template<typename T>
void Call(Animal<T>& animal) {
    animal.eat();
}

template<typename T>
void Insert(Animal<T>& animal, ...) {
    auto v = new std::vector<Animal<T>>();
    v->push_back(animal);
}

int main() {
    Lion lion;
    Cat cat;

    Call(lion);
    Call(cat);

    Insert(lion, cat);
    
    return 0;
}