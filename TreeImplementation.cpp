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
void inorder(vector<int>&ans,Node* root){
    if(root==NULL)return ;
    
    inorder(ans,root->left);
    ans.push_back(root->data);
    inorder(ans,root->right);
}
void preOrder(vector<int>&a,Node* root){
    if(root==NULL)return ;
    a.push_back(root->data);
    preOrder(a,root->left);
    preOrder(a,root->right);
}
void postOrder(vector<int>&b,Node* root){
    if(root==NULL)return ;
    postOrder(b,root->left);
    postOrder(b,root->right);
    b.push_back(root->data);
}
void print(vector<int>ans){
    for(auto it:ans)cout << it << " ";
    cout << endl;
}
void levelOrder(vector<int>&level,Node* root){
    if(root==NULL)return ;
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left!=NULL)q.push(temp->left);
            if(temp->right!=NULL)q.push(temp->right);
            level.push_back(temp->data);
        }
        // final.push_back(level);
    }
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->left=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    
    vector<int>ans;
    inorder(ans,root);
    print(ans);
    
    vector<int>a;
    preOrder(a,root);
    print(a);
    
    vector<int>b;
    postOrder(b,root);
    print(b);
    
    // vector<vector<int>>final;
    vector<int>level;
    levelOrder(level,root);
    print(level);
    // for(auto it:final){
    //     for(auto i:it){
    //         cout << i << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}
