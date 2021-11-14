#include<bits/stdc++.h>
using namespace std;
#define ll long long
int freq[1000010];
int factors(int arr[],int N)
{
    int ans = 0;
    for(int i=0;i<N;i++)
    {
        ans = max(ans,freq[arr[i]]);
        for(int j = 1;j*j<=arr[i];j++)
        {
            if(arr[i]%j==0)
            {
                freq[j] += 1;
                if(arr[i]/j!=j)
                    freq[arr[i]/j]+=1;    
            }
        }
    }
    return ans;
}
int main()
{
    int T,N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++)
            cin>>arr[i];
        for(int i=0;i<1000010;i++)
            freq[i] = 0;    
        int ans = factors(arr,N);
        cout<<ans<<endl;
    }
    return 0;
}
