#include<bits/stdc++.h>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A is called";
    }
};

class B
{
public:
    B()
    {
        cout << "B is called";
    }
};

class C: public A, public B
{
public:
    C()
    {
        cout << "C is called";
    }
};
int main()
{
    C c;
    return 0;
}