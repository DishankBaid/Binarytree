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
bool isLeaf(Node* root){
        if(root->left==NULL && root->right==NULL)return true;
        else return false;
    }
void leftside(Node* root,vector<int>&ans){
        if(root==NULL)return ;
        Node* cur=root->left;
        while(cur){
            if(isLeaf(cur)!=true)ans.push_back(cur->data);
            if(cur->left)cur=cur->left;
            else cur=cur->right;
        }
}
void rightside(Node* root,vector<int>&ans){
        if(root==NULL)return ;
        vector<int>tmp;
        Node* cur=root->right;
        while(cur){
            if(isLeaf(cur)!=true)tmp.push_back(cur->data);
            if(cur->right)cur=cur->right;
            else cur=cur->left;
        }
        for(int i=tmp.size()-1;i>=0;--i)ans.push_back(tmp[i]);
}
void leafNodes(Node* root,vector<int>&ans){
        if(isLeaf(root)==true){
            ans.push_back(root->data);
            return ;
        }
        if(root->left)leafNodes(root->left,ans);
        if(root->right)leafNodes(root->right,ans);
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(7);
    root->left->left=new Node(3);
    root->left->left->left=new Node(4);
    root->left->left->left->left=new Node(5);
    root->left->left->left->right=new Node(6);
    root->right->right=new Node(8);
    root->right->right->left=new Node(9);
    root->right->right->left->left=new Node(10);
    root->right->right->left->right=new Node(11);
    
    vector<int>ans;
    if(isLeaf(root)==false)ans.push_back(root->data);
    leftside(root,ans);
    leafNodes(root,ans);
    rightside(root,ans);
    
    for(auto it:ans){
        cout << it <<" ";
    }
    return 0;
}
