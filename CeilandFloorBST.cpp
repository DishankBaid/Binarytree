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

int CeilInBST(Node* root,int v){
    if(root==NULL)return -1;
    int ceil=-1;
    while(root){
        if(root->data==v){
            ceil=root->data;
            return ceil;
        }
        if(root->data>v){
            ceil=root->data;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return ceil;
}
int floorInBST(Node* root,int v){
    if(root->data==v)return -1;
    
    int floor=-1;
    while(root){
        if(root->data==v){
            floor=root->data;
            return floor;
        }
        if(root->data>v){
            root=root->left;
        }
        else{
            floor=root->data;
            root=root->right;
        }
    }
    return floor;
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
    
    int ans=CeilInBST(root,8);
    cout << ans <<"\n";
    ans=floorInBST(root,8);
    cout << ans << "\n";
    return 0;
}
