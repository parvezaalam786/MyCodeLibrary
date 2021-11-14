#include<bits/stdc++.h>
using namespace std;

void printPairs(int arr[],int n,int x)
{
    int i,temp;
    bool binMap[100] = {0};
    for(int i=0;i<n;i++)
    {
        temp = x-arr[i];
        if(temp>0 && binMap[temp]==1)
        {
            cout<<"pair having sum "<<x<<"is "<<arr[i]<<" and "<<temp<<endl;
        }
        binMap[arr[i]] = 1;
    }
}
int main()
{
    int arr[] = {1,4,45,6,10,-8};
    int n = sizeof(arr)/sizeof(int);
    int x = 16;
    printPairs(arr,n,x);
    return 0;
}