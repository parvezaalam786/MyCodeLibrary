#include<bits/stdc++.h>
using namespace std;

struct Circle{
    int start,end;
};
bool comp(Circle a,Circle b){
    if(a.end==b.end)
        return a.start<b.start;
    return a.end<b.end;    
}

void CountCircles(int c[],int r[],int n)
{
    Circle diameter[n];
    for(int i=0;i<n;i++){
        diameter[i].start = c[i]-r[i];
        diameter[i].end = c[i]+r[i];
    }
    sort(diameter,diameter+n,comp);
    int count = 0;
    int cur = diameter[0].end;
    for(int i=1;i<n;i++){
        if(diameter[i].start>cur){
            cur = diameter[i].end;
        }
        else{
            count++;
        }
    }
    cout<<count<<endl;
}
int main() 
{ 
    int c[] = { 1, 2, 3, 4 }; 
    int r[] = { 1, 1, 1, 1 }; 
  
    int n = sizeof(c) / sizeof(int); 
  
    CountCircles(c, r, n); 
  
    return 0; 
} 