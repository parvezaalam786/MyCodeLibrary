#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node *newNode(int data)
{
    node *np = (struct node*)malloc(sizeof(struct node));
    np->data = data;
    np->left = np->right = NULL;
    return np;
}
bool isMirror(struct node *root1,struct node *root2)
{
    if(root1==NULL and root2==NULL)
        return true;
    if(root1 && root2 && root1->data == root2->data)
        return isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
    return false;        
}
bool isSymmetric(struct node *root)
{
    return isMirror(root,root);
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left  = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left  = newNode(4); 
    root->right->right = newNode(3); 
    cout<<isSymmetric(root);
}

//      1
//    /   \
//   2     2
//  / \   / \
// 3   4 4   3