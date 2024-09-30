#ifndef TRIPLE_H
#define TRIPLE_H

#include <couple.h>

#include "date.h"

#include <iostream>

using namespace std;

template<class t1, class t2, class t3>
class triple : public couple<t1, t2>
{

    t3 x3;
    public:
    triple();
    void set_x3(t3);
    t3 get_x3();
    triple(t1,t2,t3);
    template<class a, class b, class c>
    friend ostream& operator<< (ostream& os, const triple<a, b, c>& h);
    template<class T, class U, class V>
    friend istream& operator>> (istream& in, triple<T, U, V>& h);

    virtual ~triple();

    protected:

    private:
};
template<class T, class U, class V>
istream& operator>>(istream& in, triple<T, U, V>& h) {
    in >> h.x1;
    in >> h.x2;
    in >> h.x3;
    return in;
}

template<class T, class U, class V>
ostream& operator<<(ostream& out, const triple<T, U, V>& h) {
    out << h.x1 << endl;
    out << h.x2 << endl;
    out << h.x3 << endl;
    return out;
}
template<class t, class v,class u>
triple<t, v,u>::triple() {

}
template<class q, class s,class d>
triple<q, s,d>::triple(q a, s b,d c)
 {
    this->x1 = a;
    this->x2 = b;
    this->x3= c;
}
template<class t, class v,class u>
triple<t, v,u>::~triple() {

}
template<class T, class U, class V>
void triple<T, U,V>::set_x3(V a)
{
    x3 = a;
}

template<class T, class U, class V>
V triple<T, U,V>::get_x3()
{
    return x3;
}

#endif // TRIPLE_H

