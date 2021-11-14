#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b,int &x,int &y){
    if(a==0){
        x = 0;y = 1;
        return b;
    }
    int x1 , y1;
    int d = gcd(b%a,a,x1,y1);
    x = y1-(b/a)*x1;
    y = x1;
    return d;
}
bool find_any_soln(int a,int b,int c,int &x0,int &y0,int &g){
    g = gcd(abs(a),abs(b),x0,y0);
    if(c%g){
        return false;
    }
    return true;
}
int main(){
    int T,a,b,c;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>a>>b>>c;
        int x,y,g;
        if(find_any_soln(a,b,c,x,y,g)){
            cout<<"Case "<<i<<": Yes"<<endl;
        }
        else{
            cout<<"Case "<<i<<": No"<<endl;
        }
    }
}