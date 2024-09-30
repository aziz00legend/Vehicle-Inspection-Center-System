#ifndef COUPLE_H
#define COUPLE_H

#include "date.h"
#include <iostream>

using namespace std;

template<class t1, class t2>
class couple
{
protected:
    t1 x1;
    t2 x2;
public:
    couple(t1, t2);
    couple();
    template<class T, class V>
    friend ostream& operator<< (ostream& os, const couple<T, V>& c);
    template<class T, class V>
    friend istream& operator>> (istream& in , couple<T, V>& c);

    t1 get_x1();
    void set_x1(t1);
    void set_x2(t2);
    t2 get_x2();

    virtual ~couple();
};

template<class t, class v>
couple<t, v>::couple(t a, v b)
{
    x1 = a;
    x2 = b;
}

template<class t, class v>
couple<t, v>::couple()
{

}

template<class t, class v>
couple<t, v>::~couple()
{
    // No explicit clean-up needed
}

template<class a, class b>
istream& operator>> (istream& in, couple<a, b>& c)
{
    in >> c.x1;
    in >> c.x2;
    return in;
}

template<class T, class U>
ostream& operator<<(ostream& out, const couple<T,U>& c)
{
    out << c.x1 << endl;
    out << c.x2 << endl;
    return out;
}

template<class T, class U>
T couple<T, U>::get_x1()
{
    return x1;
}

template<class T, class U>
void couple<T, U>::set_x1(T a)
{
    x1 = a;
}

template<class T, class U>
void couple<T, U>::set_x2(U a)
{
    x2 = a;
}

template<class T, class U>
U couple<T, U>::get_x2()
{
    return x2;
}

#endif // COUPLE_H

