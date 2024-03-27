#include "SP.h"

int main()
{
    smart_ptr<int> ptr(new int);
    // code
    ptr.operator*();
    *ptr = 5;
    std::cout << *ptr;

    return 0;
}