#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define int long long 
#define endl "\n"
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i < b; i++)
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define inf 1e9
const double pi = 3.141592653589793238460;
#define debug false
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007 

#define hashmap unordered_map<char,node*>
class node
{
public:
    char data;
    hashmap h;
    bool isTerminal;
    node(char d)
    {
        data = d;
        isTerminal = false;
    }
};

class Trie
{
    node* root;
public:
    Trie()
    {
        root = new node('\0');
    }
    void addWord(char *word)
    {
        node *temp = root;
        for(int i=0;word[i]!='\0';i++)
        {
            char ch = word[i];
            if(temp->h.count(ch)==0)
            {
                node *child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            }
            else
            {
                temp = temp->h[ch];
            }
        }
        temp->isTerminal = true;
    }

    bool search(char *word)
    {
        node *temp = root;
        for(int i=0;word[i]!='\0';i++)
        {
            char ch = word[i];
            if(temp->h.count(ch))
            { 
                temp = temp->h[ch];
            }
            else
            {
                return false;
            }
        }
        return temp->isTerminal;
    }
};


void solve()
{
    char word[10][100] = {"apple","ape","coder","code","coding blocks","no"};
    Trie t;
    for(int i=0;i<6;i++)
    {
        t.addWord(word[i]);
    }
    char searchWord[100];
    cin.getline(searchWord,100);
    
    if(t.search(searchWord))
    {
        cout<<searchWord<<" found "<<"\n";
    }
    else
    {
        cout<<"Not found !"<<"\n";
    }    
}

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        // freopen("Test.txt","r",stdin);
        // freopen("Output.txt","w",stdout);
    #endif
    
     // if(debug){watch_is();}
    solve();   
    return 0;
}