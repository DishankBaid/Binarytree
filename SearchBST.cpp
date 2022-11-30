#include<bits/stdc++.h>
using namespace std;
//BinarySearchTree

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
bool searchBST(Node* root,int x){
    if(root==NULL)return false;
    
    while(root!=NULL){
        if(root->data==x)return true;
        if(root->data>x)root=root->left;
        else root=root->right;
    }
    return false;
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(13);
    root->left->left=new Node(3);
    root->left->right=new Node(6);
    root->right->left=new Node(11);
    root->right->right=new Node(14);
    root->left->left->left=new Node(2);
    root->left->left->right= new Node(4);
    root->left->right->right=new Node(9);
    
    bool ans=searchBST(root,8);
    ans==0?cout <<"Not Found"<<"\n":cout <<"Found"<<"\n";
    return 0;
}
