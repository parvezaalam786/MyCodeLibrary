#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
int main()
{
    freopen("Test.txt","r",stdin);
    int T;
    cin>>T;
    int str,intt,exp,ans;
    while(T--){
        cin>>str>>intt>>exp;
        ans = 0;
        str = str+exp;
        if(exp==0&&str>intt){
            ans = 1;
            }
        else if(str<=intt){
            ans = 0;
        }
            else{
            int diff = str-intt;
            if(diff&1){
                ans = diff/2 + 1;
            }
            else{
                ans = diff/2-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}