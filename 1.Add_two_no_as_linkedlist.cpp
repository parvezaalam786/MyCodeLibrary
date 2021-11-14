#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
struct Node *CreateNode(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
//To insert at the beginning of list
void push(struct Node** head,int data){
    struct Node *newNode = CreateNode(data);
    newNode->next = (*head);
    (*head) = newNode;
}

//Adding the contents of the two linked lists
struct Node *addTwoLists(struct Node *first,struct Node *second){
    struct Node *res = NULL;//res is the head of the resultant
    struct Node *temp,*prev = NULL;
    int carry = 0,sum;

    while(first!=NULL || second!=NULL){
        sum = carry+(first?first->data:0)+(second?second->data:0);
        carry = (sum>=10)?1:0;
        sum = sum%10;
        temp = CreateNode(sum);
        if(res==NULL)
            res = temp;
        else 
            prev->next = temp;
        prev = temp;   
        if(first)
            first = first->next;
        if(second)
            second = second->next;        
    }
    if(carry>0){
        temp->next = CreateNode(carry);
    }
    return res;
}

void printList(struct Node *node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<"\n";
}

int main(void) 
{ 
    struct Node* res = NULL; 
    struct Node* first = NULL; 
    struct Node* second = NULL; 
  
    // create first list 7->5->9->4->6 
    push(&first, 6); 
    push(&first, 4); 
    push(&first, 9); 
    push(&first, 5); 
    push(&first, 7); 
    printf("First List is "); 
    printList(first); 
  
    // create second list 8->4 
    push(&second, 4); 
    push(&second, 8); 
    printf("Second List is "); 
    printList(second); 
  
    // Add the two lists and see result 
    res = addTwoLists(first, second); 
    printf("Resultant list is "); 
    printList(res); 
  
   return 0; 
} 
