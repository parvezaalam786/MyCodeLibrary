#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,vector<int>> m1;
    m1[1].push_back(1);
    m1[1].push_back(2);
    m1[2].push_back(2);
    m1[2].push_back(4);
    for(auto i:m1)
    {
        int x = i.first;
        cout<<x<<":";
        //auto it1 = (i.second).begin();
        //cout<<*it1;
        int c = abs((i.second).begin()-(i.second).end());
        cout<<c<<endl;
       for(auto it1=(i.second).begin();it1!=(i.second).end();it1++){
          cout<<*it1<<" ";
        }
    }
    m1.clear();
    return 0;
}
