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

vector<int>topViewtree(Node* root){
   vector<int>ans;
    if(root==NULL)return ans;
    
    map<int,int>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        
        Node* node=it.first;
        int x=it.second;
        
        if(mp.find(x)==mp.end())mp[x]=node->data;
        if(node->left)q.push({node->left,x-1});
        if(node->right)q.push({node->right,x+1});
    }
    for(auto i:mp)ans.push_back(i.second);
    return ans;
}
vector<int>Bottomview(Node* root){
    vector<int>ans1;
    if(root==NULL)return ans1;
    
    map<int,int>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        
        Node* node=it.first;
        int x=it.second;
        
        mp[x]=node->data;
        if(node->left)q.push({node->left,x-1});
        if(node->right)q.push({node->right,x+1});
    }
    for(auto i:mp)ans1.push_back(i.second);
    return ans1;
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
     ans=topViewtree(root);
     for(auto it:ans)cout << it <<" ";
     cout <<"\n";
     vector<int>ans1;
     ans1=Bottomview(root);
     for(auto it:ans1)cout << it << " ";
     cout <<"\n";
     return 0;
}
