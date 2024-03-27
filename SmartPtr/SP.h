#pragma once
#ifndef MHDR_H
#define MHDR_H

#include <iostream>

template<class _Ty>
class smart_ptr
{
private:
    _Ty* ptr;
public:
    explicit smart_ptr(_Ty* ptr) noexcept;
    ~smart_ptr();
    _Ty& operator*() const noexcept;
    smart_ptr operator=(smart_ptr<_Ty>& sp);
    friend std::ostream& operator<<(std::ostream& os, smart_ptr& sp);
};
//................................................//


template<class _Ty>
inline smart_ptr<_Ty>::smart_ptr(_Ty* ptr) noexcept {
    this->ptr = ptr;
}

template<class _Ty>
inline smart_ptr<_Ty>::~smart_ptr() {
    delete ptr;
}

template<class _Ty>
inline _Ty& smart_ptr<_Ty>::operator*() const noexcept {
    return *ptr;
}

template<class _Ty>
inline smart_ptr<_Ty> smart_ptr<_Ty>::operator=(smart_ptr<_Ty>& sp)
{
    smart_ptr<_Ty> temp;
    temp.ptr = sp.ptr;
    return temp;
}

template<class _Ty>
std::ostream& operator<<(std::ostream& os, smart_ptr<_Ty>& sp)
{
    os << sp.ptr;
    return os;
}
#endif // !MHDR_H