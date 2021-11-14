#include<bits/stdc++.h>
using namespace std;
void closestSum(int arr[],int n)
{
    int min_l,min_r;
    int l=0,r = n-1;
    if(n<2)
        cout<<"Invalid Array\n";
    else{
        sort(arr,arr+n);
        int sum1 = INT_MAX,sum = INT_MAX;
        while(l<r)
        {
            sum1 = arr[l]+arr[r];
            if(abs(sum1)<sum)
            {
                min_l = l;
                min_r = r;
                sum = sum1;
            }
            (sum1<0)?l++:r--;
        }
    }
    cout<<"Closest sum to zero is "<<arr[min_l]<<" and "<<arr[min_r]<<endl;    
}
int main()
{
    int arr[] = {1,60,-10,70,-80,85};
    int n = sizeof(arr)/sizeof(int);
    closestSum(arr,n);
    return 0;
}