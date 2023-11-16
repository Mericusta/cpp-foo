#include <iostream>
#include <vector>

template<typename T>
T Mock(T v)
{
    std::cout << "to mock" << std::endl;
    return v;
}

template<>
int Mock(int v)
{
    std::cout << "to mock int" << std::endl;
    return v;
}

int main()
{
    auto v = std::vector<int>();
    Mock(v);
    
    int i;
    Mock(i);
}