#include<bits/stdc++.h>
using namespace std;

//this is O(n^2) solution
int minDis1(int arr[],int n,int x,int y)
{
    int mindis = INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((arr[i]==x&&arr[j]==y||arr[i]==y&&arr[j]==x)&&mindis>abs(j-i))
            {
                mindis = abs(j-i);
            }
        }
    }
    return mindis;
}

int minDis2(int arr[],int n,int x,int y)
{
    int prev = 0,mindis = INT_MAX,i=0;
    for(;i<n;i++)
    {
        if(arr[i]==x||arr[i]==y)
        {
            prev = i;
            break;
        }
    }
    for(;i<n;i++)
    {
        if(arr[i]==x||arr[i]==y)
        {
            if(arr[i]!=arr[prev]&&abs(i-prev)<mindis)
                mindis = abs(i-prev);
            else
                prev = i;
        }
    }
    return mindis;
}

int main()
{
    int arr[] = {3,5,4,2,6,5,6,6,5,4,8,3};
    int n = sizeof(arr)/sizeof(int);
    int x = 3,y = 6;
    
    cout<<minDis1(arr,n,x,y)<<endl;
    cout<<minDis2(arr,n,x,y)<<endl;
    return 0;
}