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

int height(Node* root){
    if(root==NULL)return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh);
}
int diameter(Node* root,int& maxi){
    if(root==NULL)return 0;
    int lh=diameter(root->left,maxi);
    int rh=diameter(root->right,maxi);
    maxi=max(maxi,1+lh+rh);
    return 1+max(lh,rh);
}
int maximumPathSum(Node* root,int& maxi1){
    if(root==NULL)return 0;
    int lh=max(0,maximumPathSum(root->left,maxi1));
    int rh=max(0,maximumPathSum(root->right,maxi1));
    maxi1=max(maxi1,root->data+lh+rh);
    return root->data+max(lh,rh);
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
  
//height of tree    
    int ans=height(root);
    cout << ans <<"\n";
  
//diameter of tree
    int maxi=INT_MIN;
    int ans1=diameter(root,maxi);
    cout << ans1 << "\n";
  
//maximum path sum in the tree
    int maxi1=INT_MIN;
    maximumPathSum(root,maxi1);
    
    cout << maxi1 << "\n";
    return 0;
}
