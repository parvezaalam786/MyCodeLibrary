#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main()
{
   //freopen("Test.txt","r",stdin);
   int q,c,m,x;
   cin>>q;
   while(q--){
       cin>>c>>m>>x;
       if(c==0||m==0){
           cout<<"0"<<endl;
       }
       else{
           int mini = min(c,m);
           int sum = (c-mini)+(m-mini)+x;
           int ans = 0;
           if(sum==0){
               int a = 1,count = 0;
               int b = 0;
               if(c-mini==0) b = m;
               else b = c;
               while(a<=b){
                   a*=2;
                   count++;
               }
               count--;
               ans = count;
           }
           else{
               int a1 = sum - mini;
           
                if(a1>=0){
                    ans = mini;
                }
                else{
                    ans = abs(sum-mini);
                }
           }
           cout<<ans<<endl;
       }
   }
   return 0;
}