#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define endl "\n"

int main()
{
  ll x = log2(1000000000000000000);
   x = pow(2,x);
   x = x%60;
  cout<<x;
}