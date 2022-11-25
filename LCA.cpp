#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node* LCA(Node* root,int p,int q){
    if(!root || root->data==p || root->data==q)return root;
    Node* left=LCA(root->left,p,q);
    Node* right=LCA(root->right,p,q);
    
    if(!left)return right;
    else if(!right)return left;
    else return root;
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    
    Node* temp=LCA(root,6,7);
    cout << temp->data <<"\n";
    
    //whtever node now temp have its the lowest common ancestor Node
    return 0;
}
