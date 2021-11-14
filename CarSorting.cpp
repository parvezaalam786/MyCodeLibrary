#include<bits/stdc++.h>
using namespace std;

class Car
{
    public:
    string car_name;
    int x,y;
    Car()
    {}

    Car(string n,int x,int y)
    {
        car_name = n;
        this->x = x;
        this->y = y;
    }
    int dist()
    {
        return x*x+y*y;
    }
};
bool compare(Car A,Car B)
{
    int da = A.dist();
    int db = B.dist();
    if(da==db)
    {
        return A.car_name<B.car_name;
    }
    return da<db;
}
int main()
{
    int n; 
    cin>>n;
    vector<Car> v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        string name;
        cin>>name>>x>>y;
        Car temp(name,x,y);
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),compare);
    for(auto c:v)
    {
        cout<<"Car :"<<c.car_name<<" Dist :"<<c.dist()<<" Location :"<<c.x<<" "<<c.y<<"\n";
    }

    return 0;
}

/*
Input:
4
Audi 1 2
NewBMW 2 2
Safari 1 0
Suzuki 0 1

Output:
Car :Safari Dist :1 Location :1 0
Car :Suzuki Dist :1 Location :0 1
Car :Audi Dist :5 Location :1 2
Car :NewBMW Dist :8 Location :2 2

 */