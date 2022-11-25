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

void rightView(Node* root,vector<int>&ans,int level){
    if(root==NULL)return ;
    if(level==ans.size())ans.push_back(root->data);
    rightView(root->right,ans,level+1);
    rightView(root->left,ans,level+1);
}
void leftView(Node* root,vector<int>&ans1,int level){
    if(root==NULL)return ;
    if(level==ans1.size())ans1.push_back(root->data);
    leftView(root->left,ans1,level+1);
    leftView(root->right,ans1,level+1);
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    
    vector<int>ans;
    rightView(root,ans,0);
    for(auto it:ans)cout << it <<" ";
    cout <<"\n";
    
    vector<int>ans1;
    leftView(root,ans1,0);
    for(auto it:ans1)cout << it << " ";
    cout <<"\n";
    return 0;
}
