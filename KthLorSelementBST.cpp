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

void inordersmall(Node* root,int& cnt,int& k,int &ans){
    if(root==NULL)return ;
    
    inordersmall(root->left,cnt,k,ans);
    if(cnt++ == k-1){
        ans=root->data;
        return ;
    }
    inordersmall(root->right,cnt,k,ans);
}
void inorderlarge(Node* root,int& cnt1,int& k1,int &ans1){
    if(root==NULL)return ;
    
    inorderlarge(root->right,cnt1,k1,ans1);
    if(cnt1++ == k1-1){
        ans1=root->data;
        return ;
    }
    inorderlarge(root->left,cnt1,k1,ans1);
}
int main(){
    Node* root=new Node(8);
    root->left=new Node(5);
    root->right=new Node(12);
    root->left->left=new Node(2);
    root->left->right=new Node(7);
    root->right->left=new Node(10);
    root->right->right=new Node(13);
    root->left->left->left=new Node(1);
    root->left->left->right=new Node(3);
    root->left->right->left=new Node(6);
    root->left->right->right=new Node(8);
    root->left->left->right->right=new Node(4);
    
    int ans=INT_MAX;
    int cnt=0;
    int k=11;
    inordersmall(root,cnt,k,ans);
    cout << "11th smallest elemet in BST - "<< ans << endl;
    
    int ans1=INT_MIN;
    int cnt1=0;
    int k1=1;
    inorderlarge(root,cnt1,k1,ans1);
    cout <<"1st largest element in BST - "<< ans1 << endl;
    return 0;
}
