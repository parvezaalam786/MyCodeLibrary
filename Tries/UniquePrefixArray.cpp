#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i < b; i++)
#define MIN(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;
#define debug false
#define MAXN 100010
#define mod 1000000007

#define MAX 256
#define MAX_WORD_LEN 500

struct trieNode
{
    struct trieNode *child[MAX];
    int freq;
};

struct trieNode *newTrieNode()
{
    trieNode *newNode = new trieNode;
    newNode->freq = 1;
    for(int i=0;i<MAX;i++)
        newNode->child[i] = NULL;
    return newNode;
}

void insert(struct trieNode *root,string str)
{
    int len = str.length();
    struct trieNode *pCrawl = root;
    for(int level=0;level<len;level++)
    {
        int index = str[level];
        if(!pCrawl->child[index])
        {
            pCrawl->child[index] = newTrieNode();
        }
        else
        {
            (pCrawl->child[index]->freq)++;
        }
        pCrawl = pCrawl->child[index];
    }
}

void findPrefixUtil(struct trieNode *root,char prefix[],int ind)
{
    if(root==NULL)
        return;
    if(root->freq == 1)
    {
        prefix[ind] = '\0';
        cout<<prefix<<" ";
        return;
    }
    for(int i=0;i<MAX;i++)
    {
        if(root->child[i]!=NULL)
        {
            prefix[ind] = i;
            findPrefixUtil(root->child[i],prefix,ind+1);
        }
    }
}

void findPrefixes(string arr[],int n)
{
    struct trieNode *root = newTrieNode();
    root->freq = 0;
    for(int i=0;i<n;i++)
        insert(root,arr[i]);
    
    char prefix[MAX_WORD_LEN];
    findPrefixUtil(root,prefix,0);
}

void solve()
{
    string arr[] = {"zebra", "dog", "duck", "dove"}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    findPrefixes(arr, n); 
}

int main()
{
     // input; // output; // if(debug){watch_is();}
    fast_io;
    solve();   
    return 0;
}