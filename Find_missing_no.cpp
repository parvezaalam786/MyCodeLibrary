//Find the missing number from the set of number from 1 to n in which one no. is missing .there are no duplicates
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,7,8,9,10};
    int n = sizeof(arr)/sizeof(int);
    int xor1 = 0,xor2 = 0;
    for(int i=0;i<n;i++)
    {
        xor1 = xor1^arr[i];
        xor2 = (i+1)^xor2;
    }
    xor2 ^= (n+1);
    int missing = xor1^xor2;
    cout<<"Missing number is:"<<missing<<endl;
    return 0; 
}