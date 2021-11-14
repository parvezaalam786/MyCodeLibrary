#include<bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256
int longestSubstring(string str)
{
    int n = str.size();
    int cur_len = 1;
    int max_len = 1;
    int prev_index ;

    int visited[256];
    memset(visited,-1,sizeof(visited));
    visited[str[0]] = 0;  //marked the first char as visited

    for(int i=1;i<n;i++){
        prev_index = visited[str[i]];
        if(prev_index==-1 || i-cur_len>prev_index){  //ye wahannse kaat de rha hai string ko jahan se repetition start ho rha hai
            cur_len++;
        }
        else{
            if(cur_len>max_len) 
                max_len = cur_len;

            cur_len = i-prev_index;    
        }
        visited[str[i]] = i;  //storing the index of the current visited character
    }
    if(cur_len>max_len){
        max_len = cur_len;
    }
    return max_len;
}
int main()
{
    string str = "abcdeabcab";
    int len = longestSubstring(str);
    cout<<"Longest substring length: "<<len<<endl;
    return 0;
}