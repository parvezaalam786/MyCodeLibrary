
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[] = {3,6,9,10,12,13,14,16,51,66};
    int n1 = sizeof(arr1)/sizeof(int);
    int n2 = sizeof(arr2)/sizeof(int);

    vector<int> union1,intersect1;
    
    int i=0,j=0;
    while(i<n1&&j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            union1.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            union1.push_back(arr2[j]);
            j++;
        }
        else
        {
            union1.push_back(arr1[i]);
            intersect1.push_back(arr1[i]);
            i++;j++;
        }
    }
    while(i<n1)
    {
        union1.push_back(arr1[i]);i++;
    }
    while(j<n2)
    {
        union1.push_back(arr2[j]);j++;
    }
    cout<<"Union:"<<endl;
    for(auto it1 = union1.begin();it1!=union1.end();it1++)
        cout<<*it1<<" ";
    cout<<endl;
    cout<<"Intersection:"<<endl;
    for(auto it1 = intersect1.begin();it1!=intersect1.end();it1++)
        cout<<*it1<<" ";
    return 0;
}