//Longest span with same sum in two Binary Arrays
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

//This solution is O(n^2)
int longestspan1(int arr1[],int arr2[],int n)
{
    int sum1 = 0,sum2 = 0,maxlen = 0,len = 0,i,j;
    for(i=0;i<n;i++)
    {
        sum1 = 0;sum2 = 0;
        for(j = i+1;j<n;j++)
        {
            sum1 += arr1[i];
            sum2 += arr2[i];
        }
        len = j-i+1;
        if(sum1 == sum2)
        {
            if(len>maxlen)
                maxlen = len;
        }    
    }
    return maxlen;
}
//This solution is O(n)
int longestspan2(int arr1[],int arr2[],int n)
{
    int maxLen = 0;
    int presum1 = 0,presum2 = 0;
    int diff[2*n+1];//as the difference can go from -n to n so the size is 2n+1
    memset(diff,-1,sizeof(diff));//setting to -1 so that e can find if it is visiting first time 
    for(int i=0;i<n;i++)
    {
        presum1 += arr1[i];
        presum2 += arr2[i];
        // cout<<"p1="<<presum1<<endl<<"p2="<<presum2<<endl;

        int curr_diff = presum1-presum2;
        int diffIndex = n+curr_diff;

        if(curr_diff==0)
            maxLen = i+1;
        else if(diff[diffIndex]==-1)
            diff[diffIndex] = i;
        else 
        {
            int len = i-diff[diffIndex];
            if(len>maxLen)
                maxLen = len;
        }
        // cout<<"maxLen="<<maxLen<<endl;
        // for(int i=0;i<2*n+1;i++)
        // cout<<diff[i]<<"  ";
        // cout<<endl;       
    }
    return maxLen;
}


int main()
{
    // freopen("Output.txt","w",stdout);
    int arr1[] = {0,1,0,1,1,1,1};
    int arr2[] = {1,1,1,1,1,0,1};
    cout<<longestspan2(arr1,arr2,7)<<endl;
    return 0;
}