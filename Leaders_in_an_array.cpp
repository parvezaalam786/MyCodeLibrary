//An element is leader if it is greater than all the elements to its right side.And thr rightmost element is always a leader.
//We have to find all the leadeers in the array

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {16,17,4,3,5,2};
    int n = sizeof(arr)/sizeof(int);
    cout<<arr[n-1]<<" ";
    int max = arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            cout<<max<<" ";
        }
    }
    return 0;
}